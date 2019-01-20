#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graf[1010];
vector<int> horrors;
int hid[1010];
int m, h, s;
#define INF 1<<29

int dijkstra(){
    int dists[1010];
    fill(dists, dists+1010, INF);
  	queue<int> q;
    for(int horror : horrors){
    	dists[horror] = 0;
    	q.push(horror);
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int to : graf[curr]){
            if(dists[to] == INF){
                dists[to] = dists[curr] + 1;
                q.push(to); 
            }
        }
    }

    int mx = 0;
    int mx_id = 0;
   // cout << "##################" << endl;
    for(int i = 0; i < m; i++){
    //	cout << i << ' ' << dists[i] << endl;
        if(dists[i] > mx){
            mx = dists[i];
            mx_id = i;
        }
    }

    return mx_id;
}

int main(){

    cin >> m >> h >> s;

    int x;
    for(int i = 0; i < h; i++){
        cin >> x;
        horrors.push_back(x);
    }

    int a, b;
    for(int i = 0; i < s; i++){
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    cout << dijkstra() << endl;
} 