#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int timeline[101] = {0};
    for(int i = 0; i < 3; i++){
        int f, t;
        cin >> f >> t;
        for(int j = f; j < t; j++){
            timeline[j]++;
        }
    }
    int price = 0;
    for(int i = 0; i <= 100; i++){
        if(timeline[i] == 1)
            price += a;
        else if(timeline[i] == 2)
            price += b*2;
        else if(timeline[i] == 3)
            price += c*3;
    }
    cout << price << endl;
}
