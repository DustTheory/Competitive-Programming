#include <iostream>

using namespace std;

struct loc{
    int p, t, d;
    loc(int _p, int _t, int _d){
        p = _p;
        t = _t;
        d = _d;
    }
}

int main(){
    int n, T;
    cin >> n >> T;
    int p, t, d;
    for(int i = 0; i < n; i++){
        cin >> p >> t >> d;
    }
}
