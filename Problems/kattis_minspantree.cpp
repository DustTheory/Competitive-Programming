#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

int v, e;
vector<edge> edgelist;
vector<edge> result;

int mst(){
    sort(edgelist.begin(), edgelist.end(), [](edge &a, edge &b){
        return a.cost < b.cost;
    });
    int edges = 0;
    Disjoint_Set uf = Disjoint_Set(v);
    int cost = 0;
    for(int i = 0; i < edgelist.size() && edges < v-1; i++)
        if(!uf.join(edgelist[i].from, edgelist[i].to)){
            edges++;
            result.push_back(edgelist[i]);
            cost += edgelist[i].cost; 
        }
    if(edges != v-1)
        return -1;
    return cost;
}

void cleanup(){
    result.clear();
    edgelist.clear();
}

int main(){
    while(true){
        cleanup();
        cin >> v >> e;
        if(v == 0 && e == 0)
            break;
        int a, b, c;
        for(int i = 0; i < e; i++){
            cin >> a >> b >> c;
            edgelist.push_back(edge(a, b, c));
        }
        int s = mst();
        if(s == -1){
                cout << "Impossible" << endl;
        }else{
            cout << s << endl;
            sort(result.begin(), result.end(), [](edge &a, edge &b){
                if(a.from > a.to)
                    swap(a.from, a.to);
                if(b.from > b.to)
                    swap(b.from, b.to);
                if(a.from == b.from)
                    return a.to < b.to;
                return a.from < b.from;
            });
            for(int i = 0; i < result.size(); i++){
                cout << result[i].from << ' ' << result[i].to << endl;
            }
        }
    }
}