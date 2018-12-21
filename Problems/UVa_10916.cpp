#include <iostream>
#include <math.h>

using namespace std;

long double mem[254017];

void log2_fac(){
    long double sum = 0;
    for(int j = 1; j <= 254016; j++){
        sum += log2(j);
        mem[j] = sum;
    }
    return;
}

int solve(int n){
    int i = 1;
    unsigned long long a = 2 << n;
    while(i <= 254016 && mem[i] <= a){
         i++;
    }
    return i-1;
}

int main(){
    int n;
    log2_fac();
    while(1){
        cin >> n;
        if(n == 0)
            break;
        n -= 1950;
        n /= 10;
        cout << solve(n) << endl;
    }
}
