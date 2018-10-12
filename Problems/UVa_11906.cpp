#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <stack>

#define BIDIRECTIONAL true
#define UNIDIRECTIONAL false

namespace Graph{
    class Adjacency_List{
        public:
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
    class Adjacency_Matrix{
        public:
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
    class Edge_List{};
    class Binary_Search_Tree{
        public:
            int value;
            Binary_Search_Tree* left_child;
            Binary_Search_Tree*  right_child;
            Binary_Search_Tree(){
                value = NULL;
                left_child = nullptr;
                right_child = nullptr;
            }
            void add_number(int number){
                if(value == NULL){
                    value = number;
                    return;
                }
                if(number < value){
                    if(left_child == nullptr)
                        left_child = new Binary_Search_Tree();
                    left_child->add_number(number);
                }else if(number > value){
                    if(right_child == nullptr)
                        right_child = new Binary_Search_Tree();
                    right_child->add_number(number);
                }
            }
            void log(int level = 0){
                for(int  i = 0; i < level; i++)
                    std::cout << "    ";
                std::cout << value << std::endl;
                if(left_child != nullptr)
                    left_child->log(level+1);
                if(right_child != nullptr)
                    right_child->log(level+1);
            }
    };

    class Adjacency_List_Iterator{
        public:
            Adjacency_List* graph;
            Adjacency_List_Iterator(Adjacency_List* _graph){
                graph = _graph;
            }
    };

    class Adjacency_List_DFS : Adjacency_List_Iterator{
        public:
            std::stack<int> path;
            std::vector<bool> visited;
            int depth;
            Adjacency_List_DFS(Adjacency_List* _graph, int start_point) : Adjacency_List_Iterator(_graph){
                path.push(start_point);
                for(int i = 0; i < graph->graph.size(); i++)
                    visited.push_back(false);
                depth = 0;
            }
            int get_curr_pos(){
                return path.top();
            }
            int next(){
                if(path.empty())
                    return -1;
                int curr_point = path.top();
                std::set<int>::iterator it;
                for (it = graph->graph[curr_point].begin(); it != graph->graph[curr_point].end(); ++it){
                    if(!visited[*it]){
                        path.push(*it);
                        visited[*it] = true;
                        depth++;
                        return *it;
                    }
                }
                path.pop();
                depth--;
                return next();
            }
            void visit_each(void (*f)(Adjacency_List* _graph, Adjacency_List_DFS* _iter)){
                f(graph, this);
                visited[get_curr_pos()] = true;
                while(1){
                    int p = next();
                    if(p == -1)
                        break;
                    f(graph, this);
                }
            }
    };
}

bool is_between_bounds(int h, int l, int a){
    if(l > h)
        std::swap(h, l);
    return a >= l && a < h;
}

void UVa_11906_counter(int x, int y, int &r, int &c, int &m, int &n, std::vector<std::vector<int>> &visited){
    if(m == 0 && n == 0)
        return;

    if(m == 0){
        for(int i = 0; i < c; i+=n)
            if(visited[0][i] != -1 && i != 0)
                visited[0][i]++;
        return;
    }
    if(n == 0){
        for(int i = 0; i < r; i+=m)
            if(visited[i][0] != -1)
                visited[i][0]++;
        return;
    }

    if(m == n){
        int i = 0;
        int j = 0;
        while(i < r && j < c){
            if(visited[i][j] != -1)
                visited[i][j]++;
            i += m;
            j += n;
        }
        return;
    }

    if(visited[x][y] == -1)
        return;

    visited[x][y]++;
    if(visited[x][y] > 1 && !(x == 0 && y == 0))
        return;

    int moves[4][2] = { {1, 1},
                        {-1, -1},
                        {1, -1},
                        {-1, 1}};

    for(int i = 0; i < 4; i++)
            if(is_between_bounds(0, r, x+moves[i][0]*m) && is_between_bounds(0, c, y+moves[i][1]*n))
                UVa_11906_counter(x+moves[i][0]*m, y+moves[i][1]*n, r, c, m, n, visited);

    for(int i = 0; i < 4; i++)
        if(is_between_bounds(0, r, x+moves[i][0]*n) && is_between_bounds(0, c, y+moves[i][1]*m))
            UVa_11906_counter(x+moves[i][0]*n, y+moves[i][1]*m, r, c, m, n, visited);

    return;
}

void UVa_11906(){
    int test_cases;
    std::cin >> test_cases;
    for(int tc = 0; tc < test_cases; tc++){
        int r, c, m, n, w, x, y;
        std::cin >> r >> c >> m >> n;
        std::cin >> w;
        std::vector<std::vector<int>> visited(r, std::vector<int>(c, 0));
        for(int i = 0; i < w; i++){
            std::cin >> x >> y;
            visited[x][y] = -1;
        }
        visited[0][0] = 1;
        UVa_11906_counter(0, 0, r, c, m, n, visited);
        int even = 0, odd = 0;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(visited[i][j] > 0)
                    if(visited[i][j] % 2 == 0)
                        even++;
                    else
                        odd++;

        std::cout << "Case " << tc+1 << ": " << even << ' ' << odd << std::endl;
    }
}

int main(){
    UVa_11906();
}
