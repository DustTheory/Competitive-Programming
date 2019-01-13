#include <iostream>

using namespace std;

int main(){
    int p[9];
    for(int i = 0; i < 9; i++)
        cin >> p[i];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            int sum = 0;
            if(i != j){
                for(int k = 0; k < 9; k++)
                    if(k != i && k != j)
                        sum += p[k];
                if(sum == 100){
                    for(int k = 0; k < 9; k++)
                        if(k != i && k != j)
                            cout << p[k] << endl;
                    goto finishline;
                }
            }
        }
    }
    finishline: int kek;
    return 0;
}
