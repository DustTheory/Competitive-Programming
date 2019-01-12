#include <bits/stdc++.h>

using namespace std;

vector<int> price;

int mem[1000][1000];

unsigned long long rek(int pos, int j){
    if(pos >= 0 && pos < 1000 && mem[pos][j] != 0)
        return mem[pos][j];
    if(pos == price.size()-1)
        return price[pos];
    if(pos < 0 || pos >= price.size())
        return 1 << 31;
    mem[pos][j] = min(rek(pos+j+1, j+1)+price[pos], rek(pos-j, j)+price[pos]);
    return mem[pos][j];
}

int main(){
    int n;
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        price.push_back(x);
    }
    cout << rek(1, 1) << endl;
}
