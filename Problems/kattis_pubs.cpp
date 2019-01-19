#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> edges[10010];
bool visited[10010];
bool color[10010];
int n, m;

void paint(int pos){
    queue<int> stek;
    stek.push(pos);
    visited[pos] = true;
    color[pos] = false;
    while(!stek.empty()){
        int curr = stek.front();
        stek.pop();
        for(int edge : edges[curr]){
            if(!visited[edge]){
                visited[edge] = true;
                color[edge] = !color[curr];
                stek.push(edge);
            }
        }
    }
}

bool is_possible(){
    for(int i = 1; i <= n; i++)
        if(color[i] == 0){
            int cnt = 0;
            for(int j = 0; j < edges[i].size(); j++)
                if(color[edges[i][j]] == 1)
                    cnt++;
            if(cnt == 0)
                return false;
        }

    return true;
}

int main(){
    cin >> n >> m;

    int from, to;
    int start;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        start = from;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    for(int i = 0; i <= n; i++){
        if(!visited[i])
            paint(i);
    }
    if(!is_possible())
        cout << "Impossible" << endl;
    else{
        for(int  i = 1; i <= n; i++){
            if(!color[i])
                cout << "pub ";
            else
                cout << "house ";
        }
        cout << endl;
    }
}
