#include <iostream>
#include <bitset>
using namespace std;

unsigned long long calculate(string &s){
    unsigned long long res = 0;
    unsigned long long power = 2;
    for(int i = s.length()-1; i >= 0; i--){
        res += (power-1)*(s[i]-'0');
        power <<= 1;
    }
    return res;
}

int main(){
    char before, after;
    scanf("%s2%s", &before, &after);
    printf("%s\n%s\n", before, after);
   /* string s;
    while(1){
        cin >> s;
        if(s == "0")
            break;
        cout << calculate(s) << endl;
    }*/
}
