#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

enum state {UNVISITED, VISITED, EXPLORED};

state states[5010];
vector<int> edges[5010];

bool dfs(int pos){
    states[pos] = EXPLORED;
    bool found_cycle = false;
    for(auto edge : edges[pos]){
        if(states[edge] == EXPLORED)
            return true;
        if(states[edge] == UNVISITED)
            if(dfs(edge))
                found_cycle = true;
    }
    states[pos] = VISITED;
    return found_cycle;
}

int main(){
    int n;
    cin >> n;
    map<string, int> cities;
    int city_index = 0;

    string from, to;
    int from_id, to_id;

    for(int i = 0; i < n; i++){
        cin >> from >> to;
        if(cities.insert({from, city_index}).second)
            city_index++;
        if(cities.insert({to, city_index}).second)
            city_index++;

        from_id = cities.find(from)->second;
        to_id = cities.find(to)->second;

        states[from_id] = UNVISITED;
        states[to_id] = UNVISITED;

        edges[from_id].push_back(to_id);
    }

    string city;
    while(cin >> city){
        memset(states, UNVISITED, 5050);
        cout << city << ' ';
        if(!dfs(cities[city]))
            cout << "trapped" << endl;
        else
            cout << "safe" << endl;
    }
}
