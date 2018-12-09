#include <iostream>

using namespace std;


int solve(int n){
    if(n == 1)
        return 1;
    // Find nearest power
    int p = 1, cnt = 0;
    while(p < n){
        p <<= 1;
        cnt++;
    }
    if(p == n)
        return cnt;
    return (n-(p>>1))<<1;
}

int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0)
            break;
        cout << solve(n) << endl;
    }
}
