#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0)
            break;
        int K = sqrt(n);
        if(K % 2){  // If K is odd we're on the y axis
            if(K*K == n){
                cout << 1 << ' ' << K << endl;
            }else if(n - K*K - 1 <= K){
                cout << n-K*K << ' ' << K+1 << endl;
            }else{
                cout << K+1 << ' ' << (K+1)*(K+1) - n + 1<< endl;
            }
        }else{  // We're on the y axis
            if(K*K == n){
                cout << K << ' ' << 1 << endl;
            }else if(n - K*K - 1 <= K){
                cout << K+1 << ' ' << n-K*K << endl;
            }else{
                cout << (K+1)*(K+1) - n + 1 << ' ' << K+1 << endl;
            }
        }
    }
}
