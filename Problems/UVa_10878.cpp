#include <iostream>

using namespace std;

void UVa_10878(){
    string a;
    while(1){
        getline(cin, a);
        if(cin.eof())
            break;
        if(a != "___________"){
            int mlt = 1, dec = 0;
            for(int i = a.length()-2; i > 0; i--){
                if(a[i]!='.'){
                    if(a[i] == 'o')
                        dec += mlt;
                    mlt *= 2;
                }
            }
            cout << char(dec);
        }
    }
}

int main(){
    UVa_10878();
}
