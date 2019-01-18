#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// WA ON KATTIS

#define UNKNOWN 0

int inlab[100010];
vector<int> edges[100010];
int in[100010];
int og_in[100010];
int n, m, x;
int lab = UNKNOWN;

int solve(){
    int transfers = 0;
    unordered_multiset<int> alone;

    for(int i = 0; i < n; i++)
        if(in[i] == 0)
            alone.insert(i);

    while(!alone.empty()){
        int curr = *alone.begin();
        for(int p : alone){
            if(inlab[p] == lab){
                curr = p;
                break;
            }
        }
       // cout << curr << endl;
        in[curr] = -1;
        alone.erase(curr);
        for(int to : edges[curr])
            in[to]--;

        for(int to : edges[curr])
            if(in[to] == 0){
                alone.insert(to);
                if(lab != inlab[curr]){
                    lab = inlab[curr];
                    transfers++;
                }
            }
    }
    return transfers;
}

void reset_in(){
    for(int i = 0; i < 100005; i++){
        in[i] = og_in[i];
    }
}

int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        fill(in, in+100005, 0);
        fill(edges, edges+100005, vector<int>());
        fill(inlab, inlab+100005, 0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> inlab[i];
        }

        int from, to;
        for(int i = 0; i < m; i++){
             cin >> from >> to;
             edges[from].push_back(to);
             og_in[to]++;
        }
        reset_in();
        lab = 1;
        int a = solve();
        reset_in();
        lab = 2;
        int b = solve();
        cout << min(a, b) << endl;
    }
}
