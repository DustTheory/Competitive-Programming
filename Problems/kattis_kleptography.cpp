#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> m >> n;
    string a, b;
    cin >> b >> a;
    for(int i = 0; i < m; i++){
        cout << a[a.length()-m+i] << ' ' << b[i] << ' ';
        if(a[a.length()-m+i] < b[i])
    }
}
