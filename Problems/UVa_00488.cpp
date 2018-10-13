#include <iostream>
#include <math.h>

using namespace std;

void UVa_00488(){
    int n;
    cin >> n;
    for(int t = 0; t < n; t++){
        int a, b;
        cin >> a >> b;
        for(int i = 0; i < b; i++){
            for(int j = 1; j < a; j++){
                for(int k = 0; k < j; k++){
                    cout << j;
                }
                cout << endl;
            }
            for(int j = a; j >= 0; j--){
                for(int k = 0; k < j; k++){
                    cout << j;
                }
                if(!(t == n-1 && i == b-1 && j == 0))
                    cout << endl;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    UVa_00488();
}
