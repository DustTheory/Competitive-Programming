// Graph direction parameters
#define BIDIRECTIONAL true
#define UNIDIRECTIONAL false

#define NULL_POINT Point(-69420, -42069);

const double EPS = 1e-6;

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
    bool is_point_on_line_segment(Point point, Line_Segment ls, bool including_endpoints = true);
    Point point_to_line_projection(Point point, Line_Segment line);
    std::vector<Point> convex_hull(std::vector<Point> &points);
    std::vector<Polygon> split_by_intersections(Polygon poly);
    int quadrant(Point a);
}

namespace Graph{
    struct Adjacency_List;
    struct Adjacency_Matrix;
    struct Edge_List;
    struct Binary_Search_Tree;
}

namespace StringProcessing{
    struct Suffix_Tree;
    std::vector<int> kmp_preproces(std::string &str);
    int kmp_find_first(std::string &to_read, std::string &to_find);
    std::vector<int> kmp_find_multiple(std::string &to_read, std::string &to_find);
}

void io_boost();
bool __are_equal(double a, double b);

struct Disjoint_Set;

