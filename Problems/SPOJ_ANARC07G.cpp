#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <utility>
#include <stdio.h>

using namespace std;

int s, f;

#define INVALIDSTR "THIS STRING IS INVALID"

struct Tree{
    map<string, string> parent;
    string master;
    Tree(){
        master = INVALIDSTR;
    };
    void add(string p, string c){
        parent[c] = p;
        if(master == INVALIDSTR)
            master = p;
    }
    bool exists(string c){
        return parent.find(c) != parent.end();
    }
    string get_master(){
        if(master == INVALIDSTR)
            return INVALIDSTR;
        while(parent[master] != master){
            master = parent[master];
        }
        return master;
    }
    void clear(){
        parent.clear();
    }
};

Tree tree;

void solve(){
    cout << s << ' ' << f << endl;
    cout << tree.get_master() << endl;
    return;
}

int main(){

    string st;
    getline(cin, st);
    bool first = true;
    for(;;){
        if(!first){
            if(st[0] >= '0' && st[0] <= '9'){
                solve();
                sscanf(st.c_str(), "%d %d", &s, &f);
                if(s == 0 && f == 0)
                    break;
                tree.clear();
            }else{
                stringstream ss(st);
                string tmp, father;
                ss >> father;
                if(!tree.exists(father))
                    tree.add(father, father);
                while(ss >> tmp){
                    tree.add(father, tmp);
                }
            }
        }else{
            first = false;
            sscanf(st.c_str(), "%d %d", &s, &f);
            tree.clear();
        }
        getline(cin, st);
    }
}
