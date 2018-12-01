#include <iostream>
#include <math.h>
using namespace std;

bool valid(int n, int p){
    int c = n;
    for(int i = 0; i < p; i++){
        if(c%p != 1)
            return false;
        c -= (c/p + c%p);
    }
    if(c%p == 0)
        return true;
    return false;
}

int solution(int n){
    for(int i = sqrt(n)+1; i > 0; i--)
        if(valid(n, i))
            return i;
    return -1;
}

int main(){
    int n;
    while(1){
        cin >> n;
        if(n < 0)
            break;
        int s = solution(n);
        cout << n << " coconuts, ";
        if(s == -1)
            cout << "no solution" << endl;
        else
            cout << s << " people and 1 monkey" << endl;
    }
    return 0;
}
