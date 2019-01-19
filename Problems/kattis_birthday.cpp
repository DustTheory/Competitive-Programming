#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graf[1010];
int dfs_num[1010];
int dfs_min[1010];
int dfs_parent[1010];

#define UNKNOWN -69420
int e, v;
int dfs_cnt = 0;

bool possible = true;

void dfs(int p){
    dfs_num[p] = dfs_cnt;
    dfs_min[p] = dfs_cnt;
    dfs_cnt++;

    for(int to : graf[p]){
        if(dfs_parent[to] == UNKNOWN){
            dfs_parent[to] = p;
            dfs(to);
            if(dfs_min[to] > dfs_num[p]){
                possible = false;
            }
            dfs_min[p] = min(dfs_min[p], dfs_min[to]);
        }else if(dfs_parent[p] != to){
            dfs_min[p] = min(dfs_min[p], dfs_min[to]);
        }
    }

}

void cleanup(){
    for(int i = 0; i < 1010 ; i++)
        graf[i].clear();
    fill(dfs_num, dfs_num+1010, 0);
    fill(dfs_min, dfs_min+1010, 0);
    fill(dfs_parent, dfs_parent+1010, UNKNOWN);
    dfs_cnt = 0;
    possible = true;
}

int main(){
    int a, b;
    while(1){
        cleanup();
        cin >> v >> e;
        if(v == 0 && e == 0)
            break;
        for(int i = 0; i < e; i++){
            cin >> a >> b;
            graf[a].push_back(b);
            graf[b].push_back(a);
        }
        dfs_parent[0] = true;
        dfs(0);
        for(int i = 0; i < v; i++){
            if(dfs_parent[i] == UNKNOWN){
                possible = false;
            }
        }
        if(!possible)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
