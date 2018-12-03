#include <iostream>
#include <cmath>

using namespace std;

unsigned long f(unsigned long a, unsigned long r){
    return (a+(a+r-1))*r/2;
}

bool solve(unsigned long n){
    for(unsigned long i = sqrt(2*n); i > 0; i--){
       unsigned long a = (2*n - i*i + i)/(2*i);
       if(f(a, i) == n){
                cout << n << " = " << a << " + ... + " << a+i-1 << endl;
                return true;
        }
    }
}

int main(){
   unsigned long n;
    while(1){
        cin >> n;
        if(n == -1)
            break;
       if(!solve(n)){
            cout << n << " = " << n << " + ... + " << n << endl;
       }
    }
}
