//
// Created by de5c3nder on 10/22/18.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string a;
    while(1){
        cin >> a;
        if(a == ".")
            break;
        int len = 1;
        int cnt = 1;
        for(int i = 1; i < a.length(); i++){
            bool match = true;
            for(int j = i, k = 0; j < i+len; j++){
                if(j >= a.length() || k >= a.length() || a[j] != a[k]){
                    match = false;
                    break;
                }
                k++;
            }
            if(match == false){
                len = i+1;
                cnt = 1;
            }else{
                i += len-1;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
