#include <iostream>
#include <vector>

using namespace std;

int debts[10000];
vector<int> edges[10000];
bool visited[10000];
int n, m;

int raskusuranje(int p){
    visited[p] = true;
    int pare = debts[p];
    for(int edge : edges[p])
        if(!visited[edge])
            pare += raskusuranje(edge);
    return pare;
}

bool is_possible(){
    for(int i = 0; i < n; i++){
        if(!visited[i])
            if(raskusuranje(i) != 0)
                return false;
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> debts[i];
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    if(is_possible())
        cout << "POSSIBLE" << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}
