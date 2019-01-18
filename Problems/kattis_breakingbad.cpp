#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

vector<string> verticies;
unordered_map<string, vector<string>> edges;
unordered_map<string, bool> visited;
unordered_map<string, bool> color;

vector<string> vec1;
vector<string> vec2;

bool bipartite(string p){
    queue<string> stek;
    visited[p] = true;
    color[p] = 0;
    vec1.push_back(p);
    stek.push(p);
    while(!stek.empty()){
        string curr = stek.front();
        stek.pop();
        for(string edge : edges[curr]){
            if(!visited[edge]){
                visited[edge] = true;
                color[edge] = !color[curr];
                if(color[edge])
                   vec2.push_back(edge);
                else
                    vec1.push_back(edge);
                stek.push(edge);
            }else if(color[edge] == color[curr])
                return false;
        }
    }
    return true;
}

int main(){
    int V;
    cin >> V;
    verticies.resize(V);
    for(int i = 0; i < V; i++){
        cin >> verticies[i];
        visited.insert({verticies[i], false});
        edges.insert({verticies[i], vector<string>()});
    }

    int E;
    cin >> E;
    string from, to;
    for(int i = 0; i < E; i++){
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    bool is_bi = true;
    for(auto i : visited){
        if(!i.second)
            if(!bipartite(i.first)){
                is_bi = false;
                break;
            }
    }
    if(is_bi){
        for(int i = 0; i < vec1.size(); i++)
            cout << vec1[i] << (i == vec1.size()-1 ? "\n" : " ");
        for(int i = 0; i < vec2.size(); i++)
            cout << vec2[i] << (i == vec2.size()-1 ? "\n" : " ");
    }else{
        cout << "impossible" << endl;
    }

}
