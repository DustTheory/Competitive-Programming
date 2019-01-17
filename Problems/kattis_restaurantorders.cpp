#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>> &memo, vector<int> &items, int p, int m){
    if(m < 0)
        return 0;

    if(p >= items.size())
        return 0;

    if(memo[p][m] != 0)
        return memo[p][m];

    if(m == 0){
        memo[p][m] = 1;
        return 1;
    }
    // Take this item
    memo[p][m] += solve(memo, items, p, m-items[p]);
    // Don't take this item
    memo[p][m] += solve(memo, items, p + 1, m);
    return memo[p][m];
}

void backtrack(vector<int> &result, vector<vector<int>> &memo, vector<int> &items, int p, int m, int mm){
    if(p < 0 || m >= mm)
        return;
    result.push_back(p+1);
    for(int i = 0; i < items.size(); i++){
        if(memo[i][m + items[p]] == 1){
            backtrack(result, memo, items, i, m + items[p], mm);
            return;
        }
    }
}

int main(){
    int n, m, x;
    vector<int> items, orders;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        items.push_back(x);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x;
        orders.push_back(x);
    }
    vector<vector<int>> memo(n, vector<int>());
    for(int i = 0; i < memo.size(); i++){
        for(int j = 0; j <= 30001; j++)
            memo[i].push_back(0);
    }
    for(int i = 0; i < m; i++){

        int ways = solve(memo, items, 0, orders[i]);
        cout << orders[i] << endl;
        for(int j = 0; j < n; j++){
            for(int k = 0; k <= orders[i]; k++){
                cout << memo[j][k] << ' ';
            }
            cout << endl;
        }
        if(ways == 0)
            cout << "Impossible" << endl;
        else if(ways > 1)
            cout << "Ambiguous" << endl;
        else{
            vector<int> result;
            int spos = 0;
            for(int j = 0; j < n; j++)
                if(memo[j][0] != 0)
                    spos = j;
            cout << spos << endl;
            backtrack(result, memo, items, spos, 0, orders[i]);
            for(int j = result.size()-1; j >= 0; j--){
                cout << result[j] << (j == 0 ? "" : " ");
            }
            cout << endl;
        }
    }
}

