#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    set<int> please;
    int old;
    bool useold = false;
    for(int i = 0; i < n; i++){
        char c;
        int a;
        cin >> c >> a;
        if(c == '+')
            please.insert(a);
        else{
            useold = false;
            please.erase(a);
        }
        int prev;
        if(!useold){
            set<int>::iterator it;
            prev = *please.begin();
            for(it = please.begin(); it != please.end(); ++it){
                if(it == please.begin())
                    continue; // skip first
                else{
                    prev = __gcd(prev, *it);
                }
            }
            useold = true;
        }else{
            prev = __gcd(prev, a);
        }
        old = prev;
        cout << prev << endl;
    }
}
