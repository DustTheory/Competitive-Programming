
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

