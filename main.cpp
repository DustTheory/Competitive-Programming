#include "cpp_framework.h"

void loguj(Graph::Adjacency_List* _graph, Graph::Adjacency_List_DFS* iter){
        for(int i = 0; i < iter->depth; i++)
            std::cout << "  ";
        std::cout << iter->get_curr_pos() << std::endl;

}

int main(){
    Graph::Adjacency_List graph = Graph::Adjacency_List(10);
    graph.add_connection(1, 2, BIDIRECTIONAL);
    graph.add_connection(1, 3, BIDIRECTIONAL);
    graph.add_connection(1, 4, BIDIRECTIONAL);
    graph.add_connection(2, 5, BIDIRECTIONAL);
    graph.add_connection(2, 6, BIDIRECTIONAL);
    graph.add_connection(3, 7, BIDIRECTIONAL);
    graph.add_connection(4, 8, BIDIRECTIONAL);
    graph.add_connection(4, 9, BIDIRECTIONAL);
    graph.add_connection(5, 0, BIDIRECTIONAL);
    Graph::Adjacency_List_DFS iter = Graph::Adjacency_List_DFS(&graph, 1);
    iter.visit_each(loguj);
}
