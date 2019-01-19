#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graf[20010];
vector<int> graf_t[20010];
vector<int> toposort;
bool visited[20010];

void do_toposort(int curr){
    visited[curr] = true;
    for(int to : graf[curr]){
        if(!visited[to])
            do_toposort(to);
    }
    toposort.push_back(curr);
}

void dfs(int curr){
    cout << "   " << curr << endl;
    visited[curr] = true;
    for(int to : graf_t[curr])
        if(!visited[to])
            dfs(to);
}

void cleanup(){
    fill(visited, visited+20010, false);
    toposort.clear();
    for(auto i: graf)
        i.clear();
    for(auto i: graf_t)
        i.clear();
}

int main(){

    int T;
    cin >> T;
    while(T--){
        cleanup();
        int v, e, a, b;
        cin >> v >> e;

        for(int i = 0; i < e; i++){
            cin >> a >> b;
            cout << a << ' ' << b << endl;
            graf[a].push_back(b);
            graf_t[b].push_back(a);
        }

        for(int i = 1; i <= v; i++){
            if(!visited[i])
                do_toposort(i);
        }

        fill(visited, visited+20010, false);

        int cnt = 0;

        for(int i = toposort.size()-1; i >= 0; i--)
            if(!visited[toposort[i]]){
                cout << toposort[i] << endl;
                dfs(toposort[i]);
                cnt++;
            }

        cout << cnt << endl;
    }

}
