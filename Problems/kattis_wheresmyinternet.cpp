#include <iostream>
#include <vector>

using namespace std;

vector<int> edges[200001];
bool connected[200001];

void dfs(int p){
    connected[p] = true;
    for(int edge : edges[p])
        if(!connected[edge])
            dfs(edge);
}

int main(){
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1);
    bool all_connected = true;
    for(int i = 1; i <= n; i++){
        if(!connected[i]){
            cout << i << endl;
            all_connected = false;
        }
    }
    if(all_connected)
        cout << "Connected" << endl;
}
