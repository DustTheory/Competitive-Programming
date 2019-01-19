#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graf[50010];
vector<int> graf_t[50010];
int scc[50010];
int indegrees[50010];
int outdegrees[50010];
vector<int> toposort;
bool visited[50010];

int cnt;

void do_toposort(int curr){
    visited[curr] = true;
    for(int to : graf[curr]){
        if(!visited[to])
            do_toposort(to);
    }
    toposort.push_back(curr);
}

void dfs(int curr){
    scc[curr] = cnt;
    visited[curr] = true;
    for(int to : graf_t[curr])
        if(!visited[to])
            dfs(to);
}

void count_indegrees(int curr){
    visited[curr] = true;
    for(int to : graf_t[curr]){
       if(scc[to] != scc[curr]){
          indegrees[scc[to]]++;
          outdegrees[scc[curr]]++;
       }
       if(!visited[to])
                count_indegrees(to);
       }
}



void cleanup(){
    cnt = 1;
    fill(visited, visited+50010, 0);
    fill(indegrees, indegrees+50010, 0);
    fill(outdegrees, outdegrees+50010, 0);
    fill(scc, scc+50010, 0);
    toposort = vector<int>();
    for(auto &i: graf)
        i.clear();
    for(auto &i: graf_t)
        i.clear();
}

void clear_visited(){
     fill(visited, visited+50010, false);
}

void log_data(){
    cout << "##########################" << endl;

    cout << "visited: ";
    for(int i = 0; i < 10; i++)
        cout << visited[i] << ' ';
    cout << endl;

    cout << "indegrees: ";
    for(int i = 0; i < 10; i++)
        cout << indegrees[i] << ' ';
    cout << endl;

    cout << "outdegrees: ";
    for(int i = 0; i < 10; i++)
        cout << outdegrees[i] << ' ';
    cout << endl;

    cout << "scc: ";
    for(int i = 0; i < 10; i++)
        cout << scc[i] << ' ';
    cout << endl;

    cout << "toposort: ";
    for(int i = 0; i < toposort.size(); i++)
        cout << toposort[i] << ' ';
    cout << endl;

    cout << "GRAF: " << endl;
    for(int i = 0; i < 10010; i++){
        if(graf[i].size() > 0){
            cout << i << " : ";
            for(int j = 0; j < graf[i].size(); j++){
                cout << graf[i][j] << ' ';
            }
            cout << endl;
        }
    }

    cout << "GRAF_T: " << endl;
    for(int i = 0; i < 10010; i++){
        if(graf_t[i].size() > 0){
            cout << i << " : ";
            for(int j = 0; j < graf_t[i].size(); j++){
                cout << graf_t[i][j] << ' ';
            }
            cout << endl;
        }
    }
    cout << "##########################" << endl;
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
            graf[a].push_back(b);
            graf_t[b].push_back(a);
        }   

        clear_visited();
        for(int i = 1; i <= v; i++){
            if(!visited[i])
                do_toposort(i);
        }

        clear_visited();
        for(int i = toposort.size()-1; i >= 0; i--){
            if(!visited[toposort[i]]){
                dfs(toposort[i]);
                cnt++;
            }
        }
        clear_visited();
        for(int i = 1; i <= v; i++)
            if(!visited[i])
                count_indegrees(i);

        int cnt1, cnt2 = cnt1 = 0;
        for(int i = 1; i < cnt; i++){
            if(indegrees[i] == 0)
                cnt1++;
            if(outdegrees[i] == 0)
                cnt2++;
      //      cout << i << ' ' << indegrees[i] << ' ' << outdegrees[i] << endl;
        }
       // cout << cnt << endl;
        if(cnt != 2)
            cout << max(cnt1, cnt2) << endl;
        else
            cout << 0 << endl;
    }

}
