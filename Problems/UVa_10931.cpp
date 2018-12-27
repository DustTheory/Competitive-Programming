#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0)
            break;
        int cnt = 0;
        cout << "The parity of ";
        string c = "";
        while(n > 0){
            c += ('0'+(n&1));
            if(n&1==1)
                cnt++;
            n >>= 1;
        }
        reverse(c.begin(), c.end());
        cout << c << " is " << cnt << " (mod 2)." << endl;
    }
}
