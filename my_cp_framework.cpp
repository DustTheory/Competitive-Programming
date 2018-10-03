#include <iostream>
#include <complex>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>

/// Spaghetti code by DE5C3NDER(Ishak Dervisevic)

// Defining some constants//{

// Max acceptable error value
const double EPS = 1e-5;

// Graph direction parameters
#define BIDIRECTIONAL true
#define UNIDIRECTIONAL false

#define NULL_POINT Point(-69420, -42069);

//}

// Forward declarations wooohooo //{
bool __are_equal(double a, double b);

namespace Geometry{
    struct Point;
    struct Line;
    struct Vector2;
    struct Line_Segment;
    struct Polygon;

    double DEG_TO_RAD(double deg);
    double RAD_TO_DEG(double deg);

    //Point related stuff
    double dist_nosqrt(Point &point1, Point &point2);
    double dist(Point &point1, Point &point2);
    Point translate(Point point, Vector2 vec);

    //Line related stuff
    bool are_paralel(Line &line1, Line &line2);
    double determinant(Line &line1, Line &line2);
    Point intersection(Line &line1, Line &line2);

    //Vector2 related stuff
    double vector_dot(Vector2 &vec1, Vector2 &vec2);
    double vector2_cross_product(Vector2 &vec1, Vector2 &vec2);
    Vector2 vec_abs(Vector2 &vec);
    Vector2 to_unit_vector(Vector2 &vec);
    double determinant(Vector2 &vec1, Vector2 &vec2);

    // Line segment stuff
    Point intersection(Line_Segment &ls1, Line_Segment &ls2);

    // Polygon stuff
    std::vector<Polygon> split_by_intersections(Polygon poly);

    // General geometry suff
    double ccw(Line_Segment line, Point point);
    double ccw(Line line, Point point);
    double ccw(Point p1, Point p2, Point p3);
    double angle(Point p1, Point p2, Point p3);
    double dist_to_line_segment(Point point, Line_Segment line);
    bool is_point_on_line(Point &point, Line &line);
    bool is_point_on_line_segment(Point point, Line_Segment ls);
}

namespace Graph{
    struct Adjacency_List;
    struct Adjacency_Matrix;
    struct Edge_List;
}

namespace StringProcessing{
    struct Trie;
    std::vector<int> kmp_preproces(std::string &str);
    int kmp_find_first(std::string &to_read, std::string &to_find);
    std::vector<int> kmp_find_multiple(std::string &to_read, std::string &to_find);
}

//}

// Actual framework //{
bool __are_equal(double a, double b){
    return fabs(a-b) < EPS;
}

namespace Graph{
    struct Adjacency_List{
        std::vector<std::set<int>> graph;
        Adjacency_List(){}
        Adjacency_List(int vertecies){
            graph.clear();
            std::set<int> dummy;
            for(int i = 0; i < vertecies; i++){
                graph.push_back(dummy);
            }
            return;
        }
        void add_connection(int from, int to, bool direction){
            graph[from].insert(to);
            if(direction == BIDIRECTIONAL)
                graph[to].insert(from);
        }
        // All the stuff needed to get graph components here //{
        std::vector<std::vector<int>> get_components(){
            std::vector<bool> visited (graph.size()+1);
            fill(visited.begin(), visited.end(), false);

            std::vector<std::vector<int>> components;

            for(int i = 0; i < graph.size(); i++){
                if(!visited[i])
                    components.push_back(_get_components(i, visited));
            }
            return components;
        }
        std::vector<int> _get_components(int p, std::vector<bool> &visited){
            std::vector<int> components;
            __get_components(p, visited, components);
            return components;
        }
        void __get_components(int p, std::vector<bool> &visited, std::vector<int> &components){
            components.push_back(p);
            visited[p] = true;
            std::set<int>::iterator it;
            for (it = graph[p].begin(); it != graph[p].end(); ++it){
                if(!visited[*it])
                    __get_components(*it, visited, components);
            }
        }
        //}
        void log(){
            for(int i = 0; i < graph.size(); i++){
                std::cout << "Point " << i << " connects to points: ";
                std::set<int>::iterator it;
                for (it = graph[i].begin(); it != graph[i].end(); ++it){
                    std::cout << *it << ' ';
                }
                std::cout << std::endl;
            }
        }
    };
    struct Adjacency_Matrix{
        std::vector<std::vector<bool>> matrix;
        Adjacency_Matrix(){}
        Adjacency_Matrix(int verticies){
            matrix.clear();
            for(int i = 0; i < verticies; i++){
                matrix.push_back(std::vector<bool>());
                for(int j = 0; j < verticies; j++){
                    if(i == j)
                        matrix[i].push_back(true);
                    matrix[i].push_back(false);
                }
            }
        }
        Adjacency_Matrix(std::vector<std::vector<bool>> _matrix){
            matrix = _matrix;
        }
        void add_connection(int from, int to, bool direction){
            matrix[from][to] = true;
            if(direction == BIDIRECTIONAL)
                matrix[to][from] = true;
        }
        bool connection_exists(int from, int to){
            return matrix[from][to];
        }
        void clear(){
            matrix.clear();
        }
    };
    struct Edge_List{};
}

namespace Geometry{
    struct Point{
        double x, y;

        Point(){ x = y = 0.0; }

        Point(double _x, double _y){
            x = _x;
            y = _y;
            correct();
        }

        bool operator == (Point other){
            return __are_equal(x, other.x) && __are_equal(y, other.y);
        }
        void correct(){
            if(__are_equal(x, 0.0))
                x = 0;
            if(__are_equal(y, 0.0))
                y = 0;
        }
        Point* rotate_rad(double rad){
            double mem_x = x;
            x = x*cos(rad) - y*sin(rad);
            y = mem_x*sin(rad) + y*cos(rad);
            correct();
            return this;
        }

        Point* rotate_deg(double deg){
            return rotate_rad(DEG_TO_RAD(deg));
        }
        void log(){
            std::cout << "x: " << x << "y: " << y << std::endl;
        }
        bool is_null(){
           return *this == NULL_POINT;
        }
    };

    struct Line{
        double a, b, c;
        Line(){}
        Line(double _a, double _b, double _c){
            a = _a;
            b = _b;
            c = _c;
        }
        Line(Point point1, Point point2){

            if(point1.x > point2.x)
                std::swap(point1, point2);

            if(__are_equal(point1.x, point2.x)){
                a = 1.0;
                b = 0.0;
                c = point1.x;
            }else{
                a = (point2.y-point1.y)/fabs((point2.x-point1.x));
                b = 1.0;
                c = point1.y - (a * point1.x);
            }
        }
        double f(double _x){
            return _x*a + c;
        }
        bool operator == (Line other){
            return are_paralel(*this, other) && c == other.c;
        }
        void log(){
            std::cout << a << "per 1 unit starting from y = " << c << std::endl;
        }
    };

    struct Vector2{
        double x, y;

        Vector2(double _x, double _y){
            x = _x;
            y = _y;
        }
        Vector2(Point point){
            x = point.x;
            y = point.y;
        }
        Vector2(Point point1, Point point2){
            x = point1.x-point2.x;
            y = point1.y-point2.y;
        }
        Vector2* scale(double scalar){
            x = x*scalar;
            y = y*scalar;
            return this;
        }
        Vector2* rotate_rad(double rad){
            Point temp = Point(x, y);
            temp.rotate_rad(rad);
            x = temp.x;
            y = temp.y;
            return this;
        }
        Vector2* rotate_deg(double deg){
            return rotate_rad(DEG_TO_RAD(deg));
        }
        Point get_point(){
            return Point(x, y);
        }
        double magnitude(){
            return sqrt(x*x + y*y);
        }
        void log(){
            std::cout << x << ' ' << y << std::endl;
        }
    };

    struct Line_Segment{
        Point a, b;
        double length;
        Line line;
        Line_Segment(){}
        Line_Segment(Point _a, Point _b){
            if(_a.x > _b.x)
                std::swap(_a, _b);
            a = _a;
            b = _b;
            line = Line(a, b);
            length = dist(a, b);
        }
        Line_Segment(double ax, double ay, double bx, double by){
            a = Point(ax, ay);
            b = Point(bx, by);
        }
        void log(){
            std::cout << "Parent line: ";
            line.log();
            std::cout << "starting point:";
            a.log();
            std::cout << "ending point: ";
            b.log();
            std::cout << "length: " << length << std::endl;
        }
    };

    struct Polygon{
        std::vector<Point> points;
        Graph::Adjacency_Matrix graph;
        bool graph_exists = false;

        Polygon(){}
        Polygon(std::vector<Point> _points){
            points = _points;
            graph.clear();
        }
        void add_point(Point point){
            points.push_back(point);
        }
        bool is_point_in_polygon(Point point){
            double sum = 0;
            for(int i = 1; i < points.size(); i++){
                sum += angle(points[i-1], point, points[i]);
            //    cout << angle(points[i-1], point, points[i]) << endl;
                }
            sum += angle(points[points.size()-1], point, points[0]);
          // cout << sum << endl;
            return __are_equal(sum, 360.0) || __are_equal(sum, -360.0);
        }
        Graph::Adjacency_Matrix* create_graph(){
            graph.clear();
            graph = Graph::Adjacency_Matrix(points.size());
            for(int i = 1; i < points.size(); i++)
                graph.add_connection(i-1, i, BIDIRECTIONAL);
            graph.add_connection(0, points.size()-1, BIDIRECTIONAL);
            graph_exists = true;
        }
        Graph::Adjacency_Matrix* create_blank_graph(){
            graph.clear();
            graph = Graph::Adjacency_Matrix(points.size());
            graph_exists = true;
        }
        void log(){
            for(int i = 0; i < points.size(); i++)
                points[i].log();
        }
        double area(){
            if(!graph_exists)
                create_graph();

            double area = 0;
            for(int i = 0; i < points.size(); i++){
                for(int j = i; j < points.size(); j++){
                    if(graph.connection_exists(i, j)){
                        Vector2 a = Vector2(points[i]);
                        Vector2 b = Vector2(points[j]);
                        area += fabs(determinant(a, b))/2.0;
                    }
                }
            }
            return area;
        }
        bool connection_exists(int from, int to){
            return graph.connection_exists(from, to);
        }
        double perimeter(){
            if(!graph_exists)
                create_graph();

            double perimeter = 0;
            for(int i = 0; i < points.size(); i++){
                for(int j = i; j < points.size(); j++){
                    if(graph.connection_exists(i, j)){
                        perimeter += Line_Segment(points[i], points[j]).length;
                    }
                }
            }
            return perimeter;
        }
    };

    double DEG_TO_RAD(double deg){
        return deg * (M_PI/180);
    }

    double RAD_TO_DEG(double deg){
        return deg * (180/M_PI);
    }

    double dist_nosqrt(Point &point1, Point &point2){
        return (point1.x-point2.x)*(point1.x-point2.x) + (point1.y-point2.y)*(point1.y-point2.y);
    }

    double dist(Point &point1, Point &point2){
        return sqrt(dist_nosqrt(point1, point2));
    }

    double determinant(Line &line1, Line &line2){
        if(line1.b == 0 || line2.b == 0)
            return 0;
        return (double)(line1.a * line2.b - line2.a * line1.b);
    }

    bool are_paralel(Line &line1, Line &line2){
        return __are_equal(determinant(line1, line2), 0.0);
    }

    Point intersection(Line &line1, Line &line2){
        if(are_paralel(line1, line2))
            return NULL_POINT;

        double x = (line2.b-line1.b+line2.c-line1.c)/(line1.a-line2.a);
        double y = x*line1.a+line1.c;

        Point intersection = Point(x, y);
        return intersection;
    }

    bool is_point_on_line(Point &point, Line &line){
        return ccw(line, point) == 0;
    }

    bool is_point_on_line_segment(Point point, Line_Segment ls, bool including_endpoints){
        if(!is_point_on_line(point, ls.line))
            return false;
        if(including_endpoints)
            return point.x >= ls.a.x && point.x <= ls.b.x;
        else
            return point.x > ls.a.x && point.x < ls.b.x;
    }

    Point intersection(Line_Segment &ls1, Line_Segment &ls2){
        Line l1 = ls1.line;
        Line l2 = ls2.line;
        Point intersect = intersection(l1, l2);
        if(!intersect.is_null() && is_point_on_line_segment(intersect, ls1, false) && is_point_on_line_segment(intersect, ls2, false))
            return intersect;
        return NULL_POINT;
    }

    double vector_dot(Vector2 &vec1, Vector2 &vec2){
        return vec1.x*vec2.x + vec1.y*vec2.y;
    }

    Vector2 to_unit_vector(Vector2 &vec){
        double m = fabs(vec.magnitude());
        if(m == 0)
            return Vector2(0, 0);
        return Vector2(vec.x/m, vec.y/m);
    }

    Vector2 vector_projection(Vector2 &vec1, Vector2 &vec2){
        Vector2 unit_vec2 = to_unit_vector(vec2);
        double projection_magnitude = vector_dot(vec1,unit_vec2);
        unit_vec2.scale(projection_magnitude);
        return unit_vec2;
    }

    double vector2_cross_product(Vector2 &vec1, Vector2 &vec2){
        //similar to determinant
        return vec1.x*vec2.y - vec1.y*vec2.x;
    }

    Point translate(Point point, Vector2 vec){
        return Point((double)point.x+vec.x, (double)point.y+vec.y);
    }

    double dist_to_line_segment(Point point, Line_Segment line){
        Vector2 vec2 = Vector2(line.a, point);
        Vector2 vec1 = Vector2(line.a, line.b);
        Point proj_tip = vector_projection(vec1, vec2).get_point();
        return dist(point, proj_tip);
    }

    Vector2 vec_abs(Vector2 &vec){
        return Vector2(fabs(vec.x), fabs(vec.y));
    }

    double angle(Point p1, Point p2, Point p3){
        Vector2 vec1 = Vector2(p2, p1), vec1_abs = vec_abs(vec1);
        Vector2 vec2 = Vector2(p2, p3), vec2_abs = vec_abs(vec2);
        if(p1 == p3)
            return 0;
        double ccw_val = ccw(p2,p1,p3);
        double ang = RAD_TO_DEG(acos(vector_dot(vec1, vec2)/(vec1.magnitude()*vec2.magnitude())));
        if(__are_equal(ccw_val, 0))
            return 180;
        if(ccw_val > EPS)
            return -ang;
        return ang;
    }

    double ccw(Line_Segment line, Point point){
        // Counter clockwise test
        if(Line(line.a,line.b) == Line(line.a, point))
            return 0;
        Vector2 vec1  = Vector2(line.a, point), vec2 = Vector2(line.a, line.b);
        return vector2_cross_product(vec1, vec2);
    }

    double ccw(Point p1, Point p2, Point p3){
        // Counter clockwise test
        Vector2 vec1  = Vector2(p1, p3), vec2 = Vector2(p1, p2);
        return vector2_cross_product(vec1, vec2);
    }

    double ccw(Line line, Point point){
        // HELLA BROKEN
        Point a = Point(0, line.f(0));
        Point b = Point(1, line.f(1));
        if(Line(a, b) == Line(a, point))
            return 0;
        Vector2 vec1  = Vector2(a, point), vec2 = Vector2(a, b);
        return vector2_cross_product(vec1, vec2);
    }

    double determinant(Vector2 &vec1, Vector2 &vec2){
        return (double)(vec1.x * vec2.y - vec2.x * vec1.y);
    }

    std::vector<Polygon> split_by_intersections(Polygon poly){

        // Make a graph from polygon with added verticies at intersections
        int s = poly.points.size();
        Graph::Adjacency_List graph = Graph::Adjacency_List(2*s);
        poly.create_graph();
        for(int i = 0; i < s; i++){
            for(int j = i+1; j < s; j++){
                if(poly.connection_exists(i, j)){
                    bool intersects = false;
                    for(int k = i+1; k < s; k++){
                        for(int l = k+1; l < s; l++){
                            if(poly.connection_exists(k, l)){
                                Geometry::Line_Segment ls1 = Geometry::Line_Segment(poly.points[i], poly.points[j]);
                                Geometry::Line_Segment ls2 = Geometry::Line_Segment(poly.points[k], poly.points[l]);
                                Geometry::Point intersect = intersection(ls1, ls2);
                                if(!intersect.is_null()){
                                    intersects = true;
                                    poly.add_point(intersect);
                                    graph.add_connection(i, poly.points.size()-1, BIDIRECTIONAL);
                                    graph.add_connection(l, poly.points.size()-1, BIDIRECTIONAL);

                                    poly.add_point(intersect);
                                    graph.add_connection(poly.points.size()-1, j,  BIDIRECTIONAL);
                                    graph.add_connection(poly.points.size()-1, k,  BIDIRECTIONAL);
                                    poly.graph.matrix[i][j] = false;
                                    poly.graph.matrix[j][i] = false;
                                    poly.graph.matrix[k][l] = false;
                                    poly.graph.matrix[l][k] = false;
                                }
                            }
                        }
                    }
                    if(!intersects)
                        graph.add_connection(i, j, BIDIRECTIONAL);
                }
            }
        }

        // Use the graph to create a vector of seperate polygons
        std::vector<std::vector<int>> components = graph.get_components();
        std::vector<Geometry::Polygon> results;

        for(int i  = 0; i < components.size(); i++){
            Geometry::Polygon curr_poly;
            std::map<int, int> point_mapping;
            // add all the points
            if(components[i].size() > 1){
                for(int j = 0; j < components[i].size(); j++){
                    curr_poly.add_point(poly.points[components[i][j]]);
                    point_mapping.insert(std::pair<int, int>(components[i][j], curr_poly.points.size()-1));
                }

                // copy the individual component graphs from components
                curr_poly.create_blank_graph();

                for(int j = 0; j < components[i].size(); j++){
                    std::set<int>::iterator it;
                    for (it = graph.graph[components[i][j]].begin(); it != graph.graph[components[i][j]].end(); ++it)
                        curr_poly.graph.add_connection(point_mapping.find(components[i][j])->second, point_mapping.find(*it)->second, BIDIRECTIONAL);
                }

                results.push_back(curr_poly);
            }
        }

        return results;
    }

    std::vector<Point> convex_hull(std::vector<Point> &points){

        std::sort(points.begin(), points.end(), [points](Point &a, Point &b){
           return atan2(a.x,a.y) < atan2(b.x, b.y);
        });

        int start_point_index = points.end() - std::min_element(points.begin(),points.end(), [](Point &a, Point &b){
            if(a.y == b.y)
                return a.x > b.x;
            return a.y < b.y;
        });

        std::stack<int> stek;

        int i = 0;
        stek.push(start_point_index);

        while(true){
            if(i != start_point_index){
                if(i > 2){
                    int p1, p2, p3;
                    p3 = stek.top(); stek.pop();
                    p2 = stek.top(); stek.pop();
                    p1 = stek.top();
                    stek.push(p2);
                    stek.push(p3);

                    if(ccw(points[p1], points[p2], points[p3]) < 0){
                        stek.pop(); stek.pop();
                        i--;
                    }
                    if(i >= points.size())
                        break;
                }
              stek.push(i);
            }
            i++;
        }

        std::vector<Point> result;
        while(!stek.empty()){
            result.push_back(points[stek.top()]);
            stek.pop();
        }
        return result;
    }

}

namespace StringProcessing{
    std::vector<int> kmp_preproces(std::string &str){
        std::vector<int> reset_table (str.length());
        fill(reset_table.begin(), reset_table.end(), -1);
        int j = -1;
        for(int i = 0; i < str.length(); i=i){
            for(j = j; j >= 0 && str[i] != str[j]; j = reset_table[j])
                continue;
            j++;
            i++;
            reset_table[i] = j;
        }
        return reset_table;
    }
    int kmp_find_first(std::string &to_read, std::string &to_find){
        std::vector<int> reset_table = kmp_preproces(to_find);
        for(int i = 0; i < to_read.size(); i++){
            int len = 0;
            int mem = i;
            for(int j = 0; j < to_find.size(); j++){
                if(to_read[i] == to_find[j]){
                    len++;
                    i++;
                }else{
                    i = mem + 1 + reset_table[j];
                    break;
                }
            }
            if(len == to_find.size())
                return mem;
        }
        return -1;
    }
    std::vector<int> kmp_find_multiple(std::string &to_read, std::string &to_find){
        std::vector<int> reset_table = kmp_preproces(to_find);
        std::vector<int> found;
        for(int i = 0; i < to_read.size(); i++){
            int len = 0;
            int mem = i;
            for(int j = 0; j < to_find.size(); j++){
                if(to_read[i] == to_find[j]){
                    len++;
                    i++;
                }else{
                    i = mem + 1 + reset_table[j];
                    break;
                }
            }
            if(len == to_find.size()){
                found.push_back(mem);
                i = mem + to_find.length() - reset_table[to_find.length()-1]-2;
            }

        }
        return found;
    }
}
//}

// Solved Problems //{
void TEST007(){
    std::vector<Geometry::Point> vec = {
        Geometry::Point(1, 1),
        Geometry::Point(3, 3),
        Geometry::Point(9, 1),
        Geometry::Point(12, 3),
        Geometry::Point(9, 7),
        Geometry::Point(1, 7)
    };
    Geometry::Polygon p = Geometry::Polygon(vec);
    p.log();
    std::cout << p.is_point_in_polygon(Geometry::Point(2, 3)) << std::endl;
    std::cout << p.area() << std::endl;
}

void TEST_KMP(){
    std::string to_read = "I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN SEVSEVENTY SEVEN";
    std::string to_find = "SEVENTY SEVEN";
    std::cout << "Next line should say 30:" << std::endl;
    std::cout << StringProcessing::kmp_find_first(to_read, to_find) << std::endl;
    std::cout << "Next line should say 30, 38:" << std::endl;
    std::vector<int> found = StringProcessing::kmp_find_multiple(to_read, to_find);
    for(int i = 0; i < found.size(); i++)
        std::cout << found[i] << " , ";// (i == found.size()-1) ? " " : ", ";
    std::cout << std::endl;
}

void irfan_zadaca_001(){
    int n;
    double x, y;
    std::cin >> n;
    Geometry::Polygon poly;
    for(int i = 0; i < n; i++){
        std::cin >> x >> y;
        poly.add_point(Geometry::Point(x, y));
    }

    std::vector<Geometry::Polygon> polygons = Geometry::split_by_intersections(poly);
    for(int i = 0; i < polygons.size(); i++){
        std::cout << "##############" << std::endl << "Polygon " << i << std::endl << "##############" << std::endl;
        polygons[i].log();
    }
    for(int i = 0; i < polygons.size(); i++){
        std::cout << "Area of polygon " << i << ": " << polygons[i].area() << std::endl;
        std::cout << "Perimeter of polygon " << i << ": " << polygons[i].perimeter() << std::endl;
    }

    std::cout << "Enter a point you want to check" << std::endl;
    std::cin >> x >> y;
    Geometry::Point search_for = Geometry::Point(x, y);

    bool found = false;
    for(int i = 0; i < polygons.size(); i++){
        if(polygons[i].is_point_in_polygon(search_for)){
            found = true;
            break;
        }
    }
    if(found)
        std::cout << "Your point is somewhere in the polygon" << std::endl;
    else
        std::cout << "Nah, you missed" << std::endl;
}

void TEST_CONVEX_HULL(){

    std::vector<Geometry::Point> vec = {
        Geometry::Point(1, 1),
        Geometry::Point(3, 1),
        Geometry::Point(2, 2),
        Geometry::Point(3, 3),
        Geometry::Point(1, 3)
    };

    std::vector<Geometry::Point> test = Geometry::convex_hull(vec);
    for(int i = 0; i < test.size(); i++)
        test[i].log();
}
//}

int main(){

    TEST_CONVEX_HULL();
    return 0;
}

