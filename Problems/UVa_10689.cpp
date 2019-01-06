#include <iostream>
#include <iostream>

using namespace std;

int pow10[5] = {1, 10, 100, 1000, 10000};

// This solution is too slow. Will use a soulution using the power matrix
int generate_fibonacci(int a, int b, int n, int m){
    int f1 = a % pow10[m];
    int f2 = b % pow10[m];
    int f_curr;

    if(n == 0)
        return f1;
    if(n == 1)
        return f2;

    for(int i = 2; i <= n; i++){
        f_curr = (f1 + f2) % pow10[m];
        f1 = f2;
        f2 = f_curr;
    }

    return f_curr;
}

// Multiplies 2x2 matricies
void multiply (int F[2][2], int M[2][2], int m){
    int f00 = (((F[0][0]*M[0][0]) % pow10[m]) + ((F[0][1]*M[1][0]) % pow10[m])) % pow10[m];
    int f10 = (((F[1][0]*M[0][0]) % pow10[m]) + ((F[1][1]*M[1][0]) % pow10[m])) % pow10[m];
    int f01 = (((F[0][0]*M[0][1]) % pow10[m]) + ((F[0][1]*M[1][1]) % pow10[m])) % pow10[m];
    int f11 = (((F[1][0]*M[0][1]) % pow10[m]) + ((F[1][1]*M[1][1]) % pow10[m])) % pow10[m];
    F[0][0] = f00;
    F[1][0] = f10;
    F[0][1] = f01;
    F[1][1] = f11;
    return;
}

void _power_matrix(int F[2][2], int n, int m){
    if(n == 0 || n == 1)
        return;
    int M[2][2] {{1, 1}, {1, 0}};
     _power_matrix(F, n/2, m);
     multiply(F, F, m);
     if(n%2 != 0)
        multiply(F, M, m);
    return;
}

int power_matrix(int a, int b, int n, int m){
    if(n == 0 || n == 1)
        return 1;

    int M[2][2] {{1, 1}, {1, 0}};
    int F[2][2] {{a+b, b}, {b, a}};

    // F^n = F^n/2^2 Do this recursively
    _power_matrix(M, n-1, m);
     multiply(F, M, m);
    return F[0][0];
}

int fib(int a, int b, int n, int m){
    if(n == 0)
        return a;
    if(n == 1)
        return b;
    if(n == 2)
        return a+b;
    return power_matrix(a, b, n-1, m);
}

int main(){
    int a, b, n, m;
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        cin >> a >> b >> n >> m;
        cout << fib(a, b, n, m) << endl;
    }
}
