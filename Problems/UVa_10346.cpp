#include <iostream>

using namespace std;

int main(){
    int n, k;
    while(cin >> n >> k){
        int sum = n;
        int c = n;
        while(c >= k){
            int tmp = c/k;
            sum += tmp;
            c = c - (c/k)*(k-1);
        }
        cout << sum << endl;
    }
}
