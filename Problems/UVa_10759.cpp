#include <iostream>
#include <math.h>
#include <algorithm>

#define SECRET 98765432100012

using namespace std;

int x;

unsigned long long mem[25][151];

unsigned long long cnt(int dice, int score){
    if(dice == 0 && score >= x)
        return 1;
    if(dice == 0)
        return 0;
    if(score > 1000)
        cout << score << endl;
    if(score < 150 && mem[dice][score] != SECRET)
        return mem[dice][score];
    unsigned long long res = 0;
    for(int i = 1; i <= 6; i++)
        res += cnt(dice-1, score+i);
    mem[dice][score] = res;
    return res;
}

unsigned long long pow6(int n){
    unsigned long long res = 1;
    for(int i = 0; i < n; i++)
        res*=6;
    return res;
}

int main(){
    int n;
    while(1){
        cin >> n >> x;
        if(n == 0 && x == 0)
            break;
        for(int i = 0; i <= 24; i++)
            for(int j = 0; j <= 150; j++)
                mem[i][j] = SECRET;
        unsigned long long r = cnt(n, 0);
        unsigned long long m = pow6(n);
        if(r == 0){
            cout << 0 << endl;
        }
        else if(r >= m){
          //  cout << r << endl << m << endl;
            cout << 1 << endl;
        }else{
            int g = __gcd(r, m);
            if(m/2 == r)
                cout << 1 << '/' << 2 << endl;
            else
        	  cout << r/g << '/' << m/g << endl;
        }
    }
}
