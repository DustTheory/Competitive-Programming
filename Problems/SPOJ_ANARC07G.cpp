#include <iostream>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

#define INF 1<<29

int sn, fm;

struct option{
    int s, f, t;
    option(){s = f = t= 0;}
    void update(){
        t = sn*s + fm*f;
    }
    option(int s, int f): s(s), f(f){
        update();
    }
    option(int t): t(t){}
    void buys(int _s){
        s += _s;
        update();
    }

    void buyf(int _f){
        f += _f;
        update();
    }
    bool is_valid(){
        return !(s == -1 && f == -1);
    }
};

option min(option &a, option &b){
    if(a.t < b.t)
        return a;
    return b;
}

struct node{
    string name;
    vector<node*> children;
    option S, F;
    option mo;
    node(string name) : name(name), S(), F(), mo(-1, -1) {}
    void add_child(node* child){
        children.push_back(child);
    }
    void log_tree(int level = 0){
        for(int i = 0; i < level; i++)
            cout << "\t";
        printf("%s %d %d | (%d, %d) | (%d, %d)\n", name.c_str(), S.t, F.t, S.s, S.f, F.s, F.f);
        for(int i = 0; i < children.size(); i++)
            children[i]->log_tree(level+1);
    }

    bool is_leaf(){
        return children.size() == 0;
    }

    option min_subtree_size(){
        if(is_leaf())
            return option(1, 0);
        if(mo.is_valid())
            return mo;
        S = option(1, 0);
        for(int i = 0; i < children.size(); i++){
            option op = children[i]->min_subtree_size();
            S.buys(op.s);
            S.buyf(op.f);
        }
        F = option(0, 1);
        for(int i = 0; i < children.size(); i++){
            for(int j = 0; j < children[i]->children.size(); j++){
                option op = children[i]->children[j]->min_subtree_size();
                F.buys(op.s);
                F.buyf(op.f);
            }
        }
        mo = min(S, F);
        return mo;
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
    int tc = 0;
    bool first = true;
    ios_base::sync_with_stdio(false);
    while(true){
        getline(cin , s);
        if(cin.eof())
            break;
        if(s[0] >= '0' && s[0] <= '9'){
            if(!first){
                string root_name = find_root_name();
                cout << "ROOT: " << root_name << endl;
                people[root_name]->log_tree();
                option op = people[root_name]->min_subtree_size();
                printf("%d. %d %d %d", tc, op.s, op.f, op.t);
            }else{
                first = false;
            }
            sscanf(s.c_str(), "%d %d", &sn, &fm);
            if(sn == 0 && fm == 0)
                break;
            people.clear();
            tc++;
        }else{
            char c_parent[5010];
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
    }
    return 0;
}
