#include <iostream>
#include <math.h>

#define log2_10 3.3219280948873623478703194294893901758648313930245806120547563958159347766086252158501397433593701550996573717102502518

using namespace std;

int numofdigits(int n){
    int cnt = 0;
    while(n > 0){
        cnt++;
        n/=10;
    }
    return cnt;
}

int digits_pow2(int E){
    int m = E/log2_10 - 1;
    while(m*log2_10 < E+1)
        m++;
    return m;
}

int starting_point(int N){
    int nd = numofdigits(N);
    int i = 1;
    while(nd*2 > digits_pow2(i))
        i++;
    return i+1;
}

int main(){
    unsigned long long N;
    while(cin >> N){
        int i = starting_point(N);
        long double log2N = log2(N);
        long double log2N1 = log2(N+1);
        int ndN = numofdigits(N);
        while(1){
            if(digits_pow2(i) > 2*ndN && log2N + (digits_pow2(i)-ndN)*log2_10 - 1<= i && i <= log2N1 + (digits_pow2(i)-ndN)*log2_10-1 ){
                break;
            }
            i++;
        }

        cout << i+1 << endl;
    }
}
