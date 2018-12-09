#include <iostream>
#include <iomanip>

using namespace std;

#define sqrt2 1.41421356237

double solve(int n){
    if(n == 1)
        return 0;
    int diagonals = (n-2)*(n-2);
    return n*n - diagonals + diagonals*sqrt2;
}

int main(){
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        cout << fixed << setprecision(3) << solve(n) << (i != t-1 ? "\n" : "") << endl;
    }
}

