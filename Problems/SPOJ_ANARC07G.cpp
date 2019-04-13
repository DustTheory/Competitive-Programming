#include <iostream>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

#define INF 1<<29

int sn, fm;

struct node{
    string name;
    vector<node*> children;
    int S, F;
    node(string name) : name(name), S(INF), F(INF) {

    }
    void add_child(node* child){
        children.push_back(child);
    }
    void log_tree(int level = 0){
        for(int i = 0; i < level; i++)
            cout << "\t";
        printf("%s %d %d \n", name.c_str(), S, F);
        for(int i = 0; i < children.size(); i++)
            children[i]->log_tree(level+1);
    }

    int min_subtree_size(){
        S = sn;
        for(int i = 0; i < children.size(); i++)
            S += children[i]->min_subtree_size();
        F = fm;
        for(int i = 0; i < children.size(); i++){
            for(int j = 0; j < children[i]->children.size(); j++){
                F += children[i]->children[j]->min_subtree_size();
            }
        }
        return min(S, F);
    }
};

map<string, node*> people;

string find_root_name(){
    map<string, int> n_parents;
    for(map<string, node*>::iterator it = people.begin(); it != people.end(); ++it){
        for(int i = 0; i > it->second->children.size(); i++){
            n_parents[it->second->children[i]->name]++;
        }
    }
    for(map<string, node*>::iterator it = people.begin(); it != people.end(); ++it){
        if(n_parents[it->first] == 0)
            return it->first;
    }
    return "NO_ROOT?";
}

int main(){
    string s;
    cin >> sn >> fm;
    cin.ignore();
    while(true){
        getline(cin , s);
        if(s[0] == 'B')
            break;
        if(cin.eof())
            break;
        char c_parent[1010];
        sscanf(s.c_str(), "%s", c_parent);

        string parent = c_parent;
        string children = s.substr(parent.length());
        string child;
        stringstream children_stream(children);
        node* parent_node = people.insert({parent, new node(parent)}).first->second;
        while(children_stream >> child){
            node* child_node = people.insert({child, new node(child)}).first->second;
            parent_node->add_child(child_node);
        }
    }

    string root_name = find_root_name();
    cout << "ROOT: " << root_name << endl;
    cout << people[root_name]->min_subtree_size() << endl;
    people[root_name]->log_tree();
    return 0;
}
