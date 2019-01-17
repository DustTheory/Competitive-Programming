#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int memo[2000000];
int memogreedy[2000000];

int cc(vector<int> &arr, int p, int l){
    if(p >= arr.size())
        return INT_MAX;
    if(l < 0)
        return INT_MAX;
    if(memo[l] != 0)
        return memo[l];
    if(l == 1)
        return 1;
    if(l == 0)
        return 0;
    int a = cc(arr, p, l-arr[p]);
    if(a != INT_MAX)
        a++;
    memo[l] = min(a , cc(arr, p+1, l));
    return memo[l];
}
/*
int greedy(vector<int> &arr, int l, int p){
    if(p == arr.size())
        return 0;
    if(l == 0)
        return 0;
    if(memogreedy[l] != 0)
        return memogreedy[l];
    if(l >= arr[p])
        memogreedy[l] = 1 + greedy(arr, l-arr[p], p);
    else
        memogreedy[l] = greedy(arr, l, p+1);
    return memogreedy[l];
}
*/

int greedy(vector<int> &arr, int p, int l){
    if(p >= arr.size())
        return 0;
    if(l == 0)
        return 0;
    if(memogreedy[l] != 0)
        return memogreedy[l];
    if(l >= arr[p])
        memogreedy[l] = l/arr[p] + greedy(arr, p, l%arr[p]);
    else
        memogreedy[l] = greedy(arr,  p+1, l);
    return memogreedy[l];
}


bool is_canonical(vector<int> &arr){
    for(int i = 2; i < arr[0]+arr[1]; i++){
        //cout << i << ' ' << cc(arr, 0, i) <<  ' ' << greedy(arr, i, 0) << endl;
        if(cc(arr, 0, i) != greedy(arr, 0, i))
            return false;
    }
    return true;
}

int main(){
    int n, x;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> x;
        arr.push_back(x);
    }
    reverse(arr.begin(), arr.end());
    cout << (is_canonical(arr) ? "canonical" : "non-canonical") << endl;
}
