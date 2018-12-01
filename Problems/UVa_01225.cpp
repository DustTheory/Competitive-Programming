#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        int n;
        cin >> n;
        int histo[10] = {0,0,0,0,0,0,0,0,0,0};
        for(int i = 0; i <= n; i++){
            int c = i;
            while(c > 0){
                histo[c%10]++;
                c/=10;
            }
        }
        for(int i = 0; i < 10; i++)
            cout << histo[i] << (i != 9 ? " " : "");
        cout << endl;
    }
}
