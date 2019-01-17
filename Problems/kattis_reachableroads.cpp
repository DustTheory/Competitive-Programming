#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[1010];
vector<int> edges[1010];

void dfs(int p){
    visited[p] = true;
    for(int edge : edges[p])
        if(!visited[edge])
            dfs(edge);
}

void cleanup(){
    fill(edges, edges+1010, vector<int>());
    fill(visited, visited+1010, false);
}

int main(){
    int n, m, r;
    cin >> n;
    for(int t = 0; t < n; t++){
        cleanup();
        cin >> m >> r;
        int from, to;
        for(int i = 0; i < r; i++){
            cin >> from >> to;
            edges[from].push_back(to);
            edges[to].push_back(from);
        }
        int cnt = 0;
        for(int i = 0; i < m; i++){
            if(!visited[i]){
                dfs(i);
                cnt++;
            }
        }
        cout << cnt-1 << endl;
    }
}
