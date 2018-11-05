#include <iostream>
#include <vector>
#include <map>

using namespace std;

// https://www.murrayc.com/permalink/2016/08/19/suffix-tree-ukkonen-c/
// https://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-1/
// https://www2.cs.duke.edu/courses/fall14/compsci260/resources/suffix.trees.in.detail.pdf
struct edge{
    int startindex,
        length;
};

struct node{
    bool leaf_node;
    map<char, edge*> edge_map;
    node(char c){
        leaf_node = true;
        if(c == '$')
            leaf_node = true;
    }
    node(){
        leaf_node = false;
    }
    void break_edge(char c, int pos){
        if(pos == 0)
            return;
    }
};

class Suffix_tree{
    string s;
    node root;
    Suffix_tree(string _s){
        s = _s;
        build_suffix_tree_naive();
    }

    void build_suffix_tree_naive(){
        for(int i = 0; i < s.length(); i++){

        }
    }

    node* first_mismatch(int from, int to){
            node* curr = &root;
            int curr_c;
            map<char, edge*>::iterator curr_e;
            for(curr_e = curr->edge_map.begin(); curr_e != curr->edge_map.end(); curr_e++){
                    int pos = curr_e->second->startindex;
                    for(int i = from; i < to; i++){
                        if(pos >= s.length()){
                            return new node('$');
                        }
                        if(s[i] == s[pos]){
                            pos++;
                        }else{
                            // TODO: Split edge hopefully sometime soon
                            return i;
                        }
                    }
                    return to;
            }
    }
};

int main(){

}
