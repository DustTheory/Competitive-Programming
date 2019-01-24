#include <iostream>
#include <cmath>

using namespace std;

string decrypt(string s){
    int n = sqrt(s.length());
    string d;
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            d+=s[j*n+i];
        }
    }
    return d;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        cout << decrypt(s) << endl;
    }
}
