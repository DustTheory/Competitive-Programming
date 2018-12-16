#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 1)
            cout << "TERM " << n << " IS " << 1 << '/' << 1 << endl;
        else if(n == 2)
            cout << "TERM " << n << " IS " << 1 << '/' << 2 << endl;
        else if(n == 3)
            cout << "TERM " << n << " IS " << 2 << '/' << 1 << endl;
        else{
            int sum = 0, row = 0;
            for(int i = 1; i < n; i++){
                row++;
                sum += i;
                if(sum >= n)
                    break;
            }
            int a = sum-n+1, b =row-(sum-n);
            if(row % 2 != 0)
                cout << "TERM " << n << " IS " << a << '/' << b << endl;
            else
                cout << "TERM " << n << " IS " << b << '/' << a << endl;
        }
    }
}
