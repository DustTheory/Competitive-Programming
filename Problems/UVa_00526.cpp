#include <iostream>
#include <limits.h>

using namespace std;
int mem[101][101];

int edit_distance(int i, int j, string &a, string &b){
    if(i == -1)
        return j+1;
    if(j == -1)
        return i+1;
    if(mem[i][j] != INT_MIN)
        return mem[i][j];
    int cost = 1;
    if(a[i] == b[j])
        cost = 0;
    int option1 = edit_distance(i-1, j-1, a, b) + cost;
    int option2 = edit_distance(i-1, j, a, b) + 1;
    int option3 = edit_distance(i, j-1, a, b) + 1;

    mem[i][j] = min(option1,min(option2, option3));
   // cout << i << ' ' << j << endl;

    return mem[i][j];
}

int mini(int &a, int &b, int &c){
    if(a <= b && a <= c)
        return a;
    if(b <=a && b <= c)
        return b;
    return c;
}

void backtrack(int i, int j, string &a, string &b, int n){
    int up, left, diag = up = left = INT_MAX;
    if(i == -1 || j == -1)
        return;
    if(i == 0 && j == 0)
        return;
    if(i > 0)
        up = max(0,mem[i-1][j]);
    if(j > 0)
        left = max(0, mem[i][j-1]);
    if(i > 0 && j > 0)
        diag = max(0, mem[i-1][j-1]);
    int m = min(diag, min(left, up));
    if(m == INT_MAX)
        return;
    if(m == up){
        cout << n << ' ' << "Delete " << a.length()-i << endl;
        backtrack(i-1, j, a, b, n+1);
    }else if(m == left){
        cout << n << ' ' << "Insert " << a.length()-i << ',' << b[b.length()-j] << endl;
         backtrack(i, j-1, a, b, n+1);
    }else if(m == diag && a[i] != b[j] && a.length()-i <= a.length() && b.length()-j <= a.length()){
        cout << n << ' ' << "Replace " << a.length()-i-1 << ',' << b[b.length()-j-1] << endl;
        backtrack(i-1, j-1, a, b, n+1);
    }else if(m == diag){
        backtrack(i-1, j-1, a, b, n);
    }else{
        cout << "KEK" << endl;
    }


    return;
}

int main(){
    int c = 1;
    while(1){
        string s1, s2;
        if(cin.eof())
            break;
        getline(cin, s1);
        getline(cin, s2);
        int m = max(s1.length(), s2.length())-1;
        for(int i = 0; i < 101; i++)
            for(int j = 0; j < 101; j++){
                mem[i][j] = INT_MIN;
            }

        cout << edit_distance(s1.length()-1, s2.length()-1, s1, s2) << "\n";
 //       for(int i = 0; i < s1.length(); i++){
      //      for(int j = 0; j < s2.length(); j++){
      //          cout << mem[i][j] << ' ';
      //      }
      //      cout << endl;
    //    }
        backtrack(s1.length()-1, s2.length()-1, s1, s2, 1);
        cout << endl;
        c++;
    }
}
