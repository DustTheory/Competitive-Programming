#include <iostream>

using namespace std;

int main(){
    // GIVING UP
    // NOTE TO SELF: use rule (a+b) % c = (a%c + b%c) % c
    int sum = 0, n = 3, A[10] = {1, 2, 3}, MOD = 30000;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum = sum + A[i] + A[j];
           //sum = sum % MOD;
        }
    }
    cout << sum << endl;
}
