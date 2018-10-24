#include <iostream>

using namespace std;

int main(){
    char sign;
    int a, b, c;
    int cnt = 0;
    while(1){
        string input;
        getline(cin, input);
        sscanf(input.c_str(), "%d%c%d=%d", &a, &sign, &b, &c);
        if(sign == '+' && a+b == c)
            cnt++;
        else if(sign == '-' && a-b == c)
            cnt++;
        if(cin.eof())
            break;
    }
    cout << cnt << endl;
}
