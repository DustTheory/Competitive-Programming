#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void solve(int n, int k){
    vector<pair<int, int>> vek;
    for(int i = 1; i <= n; i++){
        for(int j  = i; j <= n; j++){
            if(i % j != 0 && __gcd(i, j) == 1){
                vek.push_back(pair<int, int>(i, j));
            }
        }
    }
    vek.push_back(pair<int, int>(1, 1));
    sort(vek.begin(), vek.end(), [](pair<int, int> &a, pair<int, int> b){
        return (float)a.first/a.second < (float)b.first/b.second;
    });
    cout << vek[k-1].first << '/' << vek[k-1].second << endl;
}

int main(){
    int n, k;
    while(cin >> n >> k)
        solve(n, k);
}
