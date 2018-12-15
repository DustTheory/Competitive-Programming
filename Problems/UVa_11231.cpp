#include <iostream>

using namespace std;

int main(){
    int n, m;
    bool c;
    while(1){
        cin >> n >> m >> c;
        if(n == 0 && m == 0 && c == 0)
            break;
        int res = (m-7)*(n-7)/2;
        if(m % 2 == 0 && n % 2 == 0 && c)
            res++;
        cout << res << endl;
    }
}
