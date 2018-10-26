#include <iostream>
#include <limits.h>

using namespace std;

int alignment_score(char a, char b){
    if(a == '_' || b == '_')
        return 1;
    if(a == b)
        return 0;
    return 1;
}

int mem[101][101];
enum op{nothing, replacement, insertion, deletion};

int mabs(int a){
    if(a >= 0)
        return a;
    return -1*a;
}
/*
mem[i][j] = min(option3,min(option2, option1));
    if(mem[i][j] == option1 && alignment_score(a[i], b[j]) != 0)
        mek[i][j] = replacement;
    else if(mem[i][j] == option2 && option1 != option2)
        mek[i][j] = deletion;
    else if(mem[i][j] == option3 && option1 != option3)
        mek[i][j] = insertion;
    cout << i << ' ' << j << endl;
*/

/*    if(option3 <= option1 && option3 <= option2){
        mem[i][j] = option3;
        mek[i][j] = insertion;
    }
    else if(option2 <= option1 && option2 <= option3){
        // Then favour deletions
        mem[i][j] = option2;
        mek[i][j] = deletion;
    }else {
        // Favour replacements
        mem[i][j] = option1;
        if(alignment_score(a[i], b[j]) == 0){
            mek[i][j] = nothing;
        }
        else{
            mek[i][j] = replacement;
        }
    }*/

int edit_distance(int i, int j, string &a, string &b){
    if(i == -1)
        return j+1;
    if(j == -1)
        return i+1;
    int cost = 1;
    if(a[i] == b[j])
        cost = 0;
    if(mem[i][j] != INT_MIN)
        return mem[i][j];
    int option1 = edit_distance(i-1, j-1, a, b) + cost;
    int option2 = edit_distance(i-1, j, a, b) + 1;
    int option3 = edit_distance(i, j-1, a, b) + 1;

    mem[i][j] = min(option3,min(option2, option1));
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
////else if(m == diag && mem[i][j] == m){
      //  if(a[i] != b[j] && i < a.length() && j < b.length())
      //      cout << n << ' ' << "Replace " << a.length()-i << ',' << b[a.length()-i] << endl;
      //  else n--;
      //  backtrack(i-1, j-1, a, b, n+1);

void backtrack(int i, int j, string &a, string &b, int n){
    int up, left, diag = up = left = INT_MAX;
    if(i == -1 || j == -1)
        return;
    if(i - 1 >= 0)
        up = mem[i-1][j];
    if(j - 1 >= 0)
        left = mem[i][j-1];
    if(i - 1 >= 0 && j - 1 >= 0)
        diag = mem[i-1][j-1];
    int m = min(up, min(left, diag));
    if(m == INT_MAX)
        return;
    if(m == up){
        cout << n << ' ' << "Delete " << a.length()-i << endl;
         backtrack(i-1, j, a, b, n+1);
    }else if(m == diag && a[i] != b[a.length()-i] && i < a.length() && a.length()-i < b.length()){
        cout << n << ' ' << "Replace " << a.length()-i << ',' << b[a.length()-i] << endl;
        backtrack(i-1, j-1, a, b, n+1);
    }else if(m == left){
        cout << n << ' ' << "Insert " << a.length()-i << ',' << b[a.length()-i] << endl;
         backtrack(i, j-1, a, b, n+1);
    }else if(m == diag){
        backtrack(i-1, j-1, a, b, n);
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
     //   for(int i = 0; i < s1.length(); i++){
    //        for(int j = 0; j < s2.length(); j++){
    //            cout << mem[i][j] << ' ';
    //        }
    //        cout << endl;
    //    }
        backtrack(s1.length()-1, s2.length()-1, s1, s2, 1);
        cout << endl;
        c++;
    }
}
