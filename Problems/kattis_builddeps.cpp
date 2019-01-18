#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
map<string, int> ids;
vector<int> edges[100010];
bool visited[100010];
string names[100010];

vector<int> sorted;

void toposort(int pos){
    visited[pos] = true;
    for(int edge : edges[pos])
        if(!visited[edge])
            toposort(edge);
    sorted.push_back(pos);
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    int id = 0;
    for(int i = 0; i < n; i++){
        string line;
        getline(cin, line);
        stringstream ss(line);

        string from, to;
        ss >> from;
        from = from.substr(0, from.size()-1);
        if(ids.insert({from, id}).second)
            id++;
        int fromid = ids[from];
        names[fromid] = from;
        while(ss >> to){
            if(ids.insert({to, id}).second)
                id++;
            int toid = ids[to];
            edges[toid].push_back(fromid);
            names[toid] = to;
        }
    }
    /*
    cout << "###########" << endl;
    for(auto edge : ids){
        cout << edge.first << ' ' << edge.second << endl;
    }
    cout << "###########" << endl;
    for(int i = 0; i < n; i++){
        cout << i << " : ";
        for(int j = 0; j < edges[i].size(); j++){
            cout << edges[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "##########" << endl;
    */
    string s;
    cin >> s;
    toposort(ids[s]);
    reverse(sorted.begin(), sorted.end());
    for(int i = 0; i < sorted.size(); i++){
        cout << names[sorted[i]] << endl;
    }
}
