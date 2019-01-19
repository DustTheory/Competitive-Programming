#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

unordered_map<string, vector<string>> graf;
unordered_map<string, vector<string>> graf_t;
unordered_map<string, vector<string>> understands;
unordered_map<string, string> speaks;
unordered_map<string, bool> visited;
vector<string> toposort;

void do_toposort(string curr){
    visited[curr] = true;
    for(string to : graf[curr])
        if(!visited[to])
            do_toposort(to);
    toposort.push_back(curr);
}

int dfs(string curr){
    visited[curr] = true;
    int cnt = 1;
    for(string to : graf_t[curr])
        if(!visited[to])
            cnt += dfs(to);
    return cnt;
}

void clear_visited(){
    for(auto &b : visited)
        b.second = false;
}

int main(){
    int n;
    string line, who, lng1, lng2;

    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++){
        getline(cin, line);
        stringstream ss(line);
        ss >> who >> lng1;
        speaks[who] = lng1;
        understands[lng1].push_back(who);
        while(ss >> lng2)
            understands[lng2].push_back(who);
    }

    for(auto i : speaks)
        for(string j : understands[i.second]){
            graf[i.first].push_back(j);
            graf_t[j].push_back(i.first);
        }

    clear_visited();
    for(auto i : speaks)
        if(!visited[i.first])
            do_toposort(i.first);


    clear_visited();
    reverse(toposort.begin(), toposort.end());

    int m = 0;
    for(string start : toposort)
        if(!visited[start])
             m = max(dfs(start), m);

    cout << graf.size() - m << endl;
}
