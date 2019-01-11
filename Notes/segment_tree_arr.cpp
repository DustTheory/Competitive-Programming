#include <bits/stdc++.h>

using namespace std;

#define INF 1 << 29

vector<int> tree;

int closest_pow2(int n){
    int pow2 = 1;
    while(n > pow2)
        pow2 <<= 1;
    return pow2;
}

int build_tree(int n){
    if(tree[n] != INF)
        return tree[n];
    tree[n] = min(build_tree(n*2), build_tree(n*2+1));
}

int get_min(int from, int to, int a , int b, int curr_index){
    if(a >= from && b <= to)
        return tree[curr_index];
    if(b < from || a > to)
        return 1 << 29;
    return min(get_min(from, to, a, (a+b)/2, curr_index*2), get_min(from, to, (a+b)/2+1, b, curr_index*2+1));
}

int main(){

    int n;
    cin >> n;
    tree.resize(closest_pow2(n)*2);
    fill(tree.begin(), tree.end(), INF);
    for(int i = 0; i < n; i++){
        cin >> tree[closest_pow2(n)+i];
    }
    build_tree(1);
    cout << get_min(1, 3, 1, 4, 1) << endl;
    cout << get_min(1, 3, 1, 4, 1) << endl;
    return 0;
}
