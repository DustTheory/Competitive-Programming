#include <iostream>
#include <algorithm>
using namespace std;

void UVa_10252(){
    string a, b;
    while(1){
        getline(cin, a);
        if(cin.eof())
            break;
        getline(cin, b);
        int cnt_a[256];
        fill(cnt_a, cnt_a+256, 0);
        int cnt_b[256];
        fill(cnt_b, cnt_b+256, 0);
        for(int i = 0; i < a.length(); i++)
            cnt_a[a[i]]++;
        for(int i = 0; i < b.length(); i++)
            cnt_b[b[i]]++;
        string res;
        for(int i = 0; i < 256; i++){
            for(int j = 0; j < min(cnt_a[i], cnt_b[i]); j++)
                res += char(i);
        }
        sort(res.begin(), res.end());
        cout << res << endl;
    }
}
int main(){
    UVa_10252();
}
