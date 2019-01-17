#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define GROWING 1
#define FALLING 0
#define INF 1 << 29

int memo[1000000][2];

bool check(int &a, int &b, bool dir){
    if(a == b)
        return false;
    if(a < b && dir == GROWING)
        return true;
    if(a > b && dir == FALLING)
        return true;
    return false;
}

int solve(vector<int> &arr, int pos, bool dir, int last){
    if(pos >= arr.size())
        return 0;
    if(memo[pos][dir] != -1)
        return memo[pos][dir];
    int option1, option2 = option1 = option2 = -(INF);

    // Include this element
    if(check(arr[last], arr[pos], dir)){
        option1 = solve(arr, pos+1, !dir, pos) + 1;
    }
    // Skip this element
    option2 = solve(arr, pos+1, dir, pos);
    memo[pos][dir] = max(option1, option2);
    return memo[pos][dir];
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        arr.push_back(x);
        memo[i][0] = -1;
        memo[i][1] = -1;
    }
    int m = 0;
    if(n == 1)
        cout << 1 << endl;
    else{
        for(int i = 1; i < n; i++){
            bool dir = GROWING;
            if(arr[i-1] > arr[i])
                dir = FALLING;
            m = max(m, solve(arr, i-1 , dir, i) + 1);
        }
        cout << m << endl;
    }
}
