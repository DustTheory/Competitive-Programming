#include <iostream>
#include <vector>
#include <stack>

struct Disjoint_Set{
    std::vector<int> parent;
    std::vector<int> ranks;
    Disjoint_Set(int size){
        for(int i = 0; i <= size; i++){
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

    void join(int a, int b){
        int parent_a = parent_of(a);
        int parent_b = parent_of(b);
        if(parent_a == parent_b)
            return;
        if(ranks[parent_a] < ranks[parent_b]){
            parent[parent_a] = parent_b;
            ranks[parent_b] += ranks[parent_a];
        }else{
            parent[parent_b] = parent_a;
            ranks[parent_a] += ranks[parent_b];
        }
    }

    bool same_parent(int a, int b){
        return parent_of(a) == parent_of(b);
    }
};

int main(){
    int n, q;
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> q;
    Disjoint_Set uf = Disjoint_Set(n);
    char c;
    int a, b;
    for(int i = 0; i < q; i++){
        std::cin >> c >> a >> b;
        if(c == '=')
            uf.join(a, b);
        else if(c == '?'){
            std::cout << (uf.same_parent(a, b) ? "yes" : "no") << std::endl;
        }
    }
}
