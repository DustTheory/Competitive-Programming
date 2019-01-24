#include <iostream>

using namespace std;

int main(){
    int n, w, h;
    cin >> n >> w >> h;
    int d = w*w + h*h;
    int s;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s*s <= d)
            cout << "DA" << endl;
        else
            cout << "NE" << endl;
    }
}
