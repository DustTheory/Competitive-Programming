
void io_boost(){
    std::ios_base::sync_with_stdio(false);
}

bool __are_equal(double a, double b){
    return fabs(a-b) < EPS;
}

struct Disjoint_Set{
    std::vector<int> parent;
    std::vector<int> ranks;
    std::vector<int> subtree_size;
    Disjoint_Set(int size){
        for(int i = 0; i <= size; i++){
            parent.push_back(i);
            ranks.push_back(0);
            subtree_size.push_back(1);
        }
    }

    int parent_of(int x){
        int curr = x;
        std::stack<int> cigare;
        while(curr != parent[curr]){
            cigare.push(curr);
            curr = parent[curr];
        }
        while(!cigare.empty()){
            parent[cigare.top()] = curr;
            subtree_size[cigare.top()] = 1;
            cigare.pop();
       }
        return curr;
    }

    int join(int a, int b){
        int parent_a = parent_of(a);
        int parent_b = parent_of(b);
        if(parent_a == parent_b)
            return parent_a;
        if(ranks[parent_a] > ranks[parent_b]){
            parent[parent_b] = parent_a;
            subtree_size[parent_a] += subtree_size[parent_b];
            return parent_a;
        }else{
            parent[parent_a] = parent_b;
            subtree_size[parent_b] += subtree_size[parent_a];
            if(ranks[parent_a] == ranks[parent_b]){
                ranks[parent_b] += 1;
            }
            return parent_b;
        }
    }

    bool same_parent(int a, int b){
        return parent_of(a) == parent_of(b);
    }

    void path_compression(){
        std::stack<int> cigare;
        for(int i = 0; i < parent.size(); i++){
            cigare.push(i);

            while(parent[cigare.top()] != cigare.top())
                cigare.push(parent[cigare.top()]);

            int big_daddy = cigare.top();
            while(!cigare.empty()){
                parent[cigare.top()] = big_daddy;
                cigare.pop();
            }
        }
    }

    void log(){
        for(int i = 0; i < parent.size(); i++)
            std::cout << parent[i] << ' ';
        std::cout << std::endl;
    }
};
//}
