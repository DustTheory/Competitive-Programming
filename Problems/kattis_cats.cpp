#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int m, c;

struct Disjoint_Set{
    vector<int> parent;
    vector<int> ranks;
    Disjoint_Set(int _size){
        for(int i = 0; i <= _size; i++){
            parent.push_back(i);
            ranks.push_back(1);
        }
    }

    int parent_of(int x){
        int curr = x;
        while(curr != parent[curr]){
            curr = parent[curr];
            parent[curr] = parent[parent[curr]];
        }
        return curr;
    }

   bool join(int a, int b){
        int parent_a = parent_of(a);
        int parent_b = parent_of(b);
        if(parent_a == parent_b)
            return true;
        if(ranks[parent_a] < ranks[parent_b]){
            parent[parent_a] = parent_b;
            ranks[parent_b] += ranks[parent_a];
        }else{
            parent[parent_b] = parent_a;
            ranks[parent_a] += ranks[parent_b];
        }
        return false;
    }

    bool same_parent(int a, int b){
        return parent_of(a) == parent_of(b);
    }
};

struct edge{
    int from, to, cost;
    edge(int _from, int _to, int _cost){
        from = _from;
        to = _to;
        cost = _cost;
    }
};

vector<edge> edgelist;

int mst(){
    sort(edgelist.begin(), edgelist.end(), [](edge &a, edge &b){
        return a.cost < b.cost;
    });
    int edges = 0;
    int dist = 0;
    Disjoint_Set uf = Disjoint_Set(c);
    for(int i = 0; i < edgelist.size() && edges < c-1; i++)
        if(!uf.join(edgelist[i].from, edgelist[i].to)){
            edges++;
            dist += edgelist[i].cost;
        }
    return dist;
}

void cleanup(){
    edgelist.clear();
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cleanup();
        int a, b, p;
        cin >> m >> c;
        for(int i = 0; i < (c*(c-1))/2; i++){
            cin >> a >> b >> p;
            edgelist.push_back(edge(a, b, p));
        }
        if(mst() <= m-c)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}
