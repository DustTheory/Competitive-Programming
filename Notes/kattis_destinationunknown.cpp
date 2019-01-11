#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graf;
vector<int> dest;

void dijkstra(int from, int to, vector<int> &dists){
    for(int i = 0; i <= graf.size()+2; i++){
        dists.push_back(999999999);
    }
    dists[from] = 0;
    queue<int> kju;
    kju.push(from);
    while(!kju.empty()){
        int curr = kju.front();
        for(int i = 0; i < graf[curr].size(); i++){
            if(curr != graf[curr][i].first && dists[curr] + graf[curr][i].second < dists[graf[curr][i].first]){
                kju.push(graf[curr][i].first);
                dists[graf[curr][i].first] = dists[curr] + graf[curr][i].second;
            }
        }
        kju.pop();
    }

}

int main(){
    int tc;
    cin >> tc;
    for(int test = 0; test < tc; test++){
        graf.clear();
        dest.clear();
        int n, m, t;
        cin >> n >> m >> t;
        int s, g, h;
        cin >> s >> g >> h;
        int from, to, dist;
        int dh_g;
        for(int i = 0; i <= m+1; i++)
            graf.push_back(vector<pair<int, int>>());
        for(int i = 0; i < m; i++){
            cin >> from >> to >> dist;
            graf[from].push_back(pair<int, int>(to, dist));
            graf[to].push_back(pair<int, int>(from, dist));
        }
        int x;
        for(int j = 0; j < t; j++){
            cin >> x;
            dest.push_back(x);
        }
        // PROBLEM SOLUTION
        vector<int> dists1;
        dijkstra(s, dest[0], dists1);
        vector<int> dists_g;
        dijkstra(g, dest[0], dists_g);
        vector<int> dists_h;
        dijkstra(h, dest[0], dists_h);
        vector<int> result;
        dh_g = dists_g[h];
        for(int i = 0; i < t; i++){
            if(dest[i] < dists1.size() && dest[i] < dists_g.size() && dest[i] < dists_h.size())
            if(dists1[dest[i]] == dists1[h] + dh_g + dists_g[dest[i]] || dists1[dest[i]] == dists1[g] + dh_g + dists_h[dest[i]])
                result.push_back(dest[i]);

        }
        sort(result.begin(), result.end());
        for(int i = 0; i < result.size(); i++)
            cout << result[i] << (i != result.size()-1 ? " " : "");
        cout << endl;
    }
}
