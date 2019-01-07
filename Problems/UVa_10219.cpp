#include <iostream>
#include <cmath>

using namespace std;


long double log10_fac(unsigned long long n){
    long double result = 0;
    for(unsigned long long i = 1; i <= n; i++){
        result += log10(i);
    }
    return result;
}

long double log10_f_fac(unsigned long long n, unsigned long long k){
    long double result = 0;
    for(unsigned long long i = 0; i < k; i++){
        result += log10(n-i);
    }
    return result;
}


unsigned long long solve(unsigned long long n, unsigned long long k){
    if(n <= k)
        return 1;
    if(k > n-k)
        k = n-k;
    return floor(log10_f_fac(n, k)-log10_fac(k))+1;
}

int main()
{
    unsigned long long n, k;
    while(cin >> n >> k)
        cout << solve(n, k) << endl;
    return 0;
}
