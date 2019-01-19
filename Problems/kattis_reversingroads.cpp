#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graf[100];
vector<int> graf_t[100];
vector<pair<int, int>> edgelsit;
bool enabled[100][100];
bool enabled_t[100][100];
vector<int> toposort;
bool visited[100];
int v, e;

void clean_visited(){
    fill(visited, visited+99, 0);
}


void cleanup(){
    for(auto &i : graf)
        i.clear();
    for(auto &i : graf_t)
        i.clear();
    edgelsit.clear();
    toposort.clear();

    for(int i = 0; i < 99; i++)
        for(int j = 0; j < 99; j++){
            enabled[i][j] = false;
            enabled_t[i][j] = false;
        }

    clean_visited();
}

void _do_toposort(int curr){
    visited[curr] = true;
    for(int to : graf[curr])
        if(!visited[to] && enabled[curr][to])
            _do_toposort(to);
    toposort.push_back(curr);
}

void do_toposort(){
    toposort.clear();
    for(int i = 0; i < v; i++)
        if(!visited[i])
            _do_toposort(i);

    reverse(toposort.begin(), toposort.end());
    clean_visited();
}

void trans_dfs(int curr){
    visited[curr] = true;
    for(int to : graf_t[curr])
        if(!visited[to] && enabled_t[curr][to])
            trans_dfs(to);
}

void log_graph(){
    cout << "##############" << endl;
    for(int i = 0; i < v; i++){
        cout << i << " : ";
        for(int j = 0; j < graf[i].size(); j++)
            if(enabled[i][graf[i][j]])
                cout << graf[i][j] << ' ';
        cout << endl;
    }
    cout << "##############" << endl;   
}

int count_scc(){
    do_toposort();
    int scc = 0;
    for(int start : toposort)
        if(!visited[start]){
            trans_dfs(start);
            scc++;
        }
    clean_visited();
    toposort.clear();
    return scc;
}


int main(){
    int T = 1;
    while(cin >> v >> e){
        cleanup();
        int a, b;
        for(int i = 0; i < e; i++){
            cin >> a >> b;

            graf[a].push_back(b);
            graf[b].push_back(a);
            graf_t[b].push_back(a);
            graf_t[a].push_back(b);

            enabled[a][b] = true;
            enabled[b][a] = false;
            enabled_t[b][a] = true;
            enabled_t[a][b] = false;

            edgelsit.push_back({a, b});
        }       

        cout << "Case " << T << ": ";
        if(count_scc() == 1){
            cout << "valid" << endl;
        }else{
            bool valid = false;
            for(int i = 0; i < edgelsit.size(); i++){
                int a = edgelsit[i].first, b = edgelsit[i].second;
                if(enabled[a][b]){

                    enabled[a][b] = false;
                    enabled[b][a] = true;

                    enabled_t[a][b] = true;
                    enabled_t[b][a] = false;

                    int scc = count_scc();

                    enabled[a][b] = true;
                    enabled[b][a] = false;

                    enabled_t[a][b] = false;
                    enabled_t[b][a] = true;

                    if(scc == 1){
                        cout << a << ' ' << b << endl;
                        valid = true;
                        break;
                    }
                }
            }
            if(!valid)
                cout << "invalid" << endl;
        }
        T++;
    }
}