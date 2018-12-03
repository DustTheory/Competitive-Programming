#include <iostream>

using namespace std;

double solve(int n){
    double res = 0;
    int squares = n*n;
    int turns = 3;
    if(n % 2 == 0){
        turns += max(0,(n-2)*2);
    }else{
        turns += max(0,(n-3)*2);
        squares -= (n-2);
    }
    cout << squares << endl;
    cout << turns << endl;
    return 0;
}

int main(){
    int n;
    cin >> n;
    cout << solve(n) << endl;
}
