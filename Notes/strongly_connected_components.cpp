#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graf[100];
vector<int> graf_t[100];
vector<int> toposort;
bool visited[100];

void do_toposort(int curr){
    visited[curr] = true;
    for(int to : graf[curr])
        if(!visited[to])
            do_toposort(to);
    toposort.push_back(curr);
}

void dfs(int curr){
    visited[curr] = true;
    for(int to : graf_t[curr])
        if(!visited[to])
            dfs(to);
}

int main(){
    int v, e, a, b;
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        cin >> a >> b;
        graf[a].push_back(b);
        graf_t[b].push_back(a);
    }

    do_toposort(0);

  //  for(int i : toposort){
   //     cout << i << endl;
  //  }

    fill(visited, visited+100, false);

    int cnt = 0;

    for(int i = toposort.size()-1; i >= 0; i--){
        if(!visited[toposort[i]]){
            dfs(toposort[i]);
            cnt++;
        }
    }

    cout << cnt << endl;

}
