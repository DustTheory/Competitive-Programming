#include <iostream>

using namespace std;

string  a = "aabbc", b = "ccabba";
int memo[5][5];

int lcs(int i, int j){
    if(memo[i][j] != -1)
        return memo[i][j];
    if(i >= a.length() || j >= b.length())
        return 0;
    if(a[i] == b[j])
        return lcs(i+1, j+1) + 1;
    memo[i][j] = max(lcs(i+1, j), lcs(i, j+1));
    return memo[i][j];
}

int main(){
    for(int i = 0; i < a.length(); i++)
        for(int j = 0; j < b.length(); j++)
            memo[i][j] = -1;
    cout << lcs(0, 0) << endl;
}
