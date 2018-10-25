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

int mem[100][100];

int mabs(int a){
    if(a >= 0)
        return a;
    return -1*a;
}

int edit_distance(int i, int j, string &a, string &b){
    if(i == -1 && j == -1)
        return 0;
    if(i == -1)
        return j * alignment_score(a[j], '_');
    if(j == -1)
        return i * alignment_score(b[i], '_');
    if(mem[i][j] != INT_MIN)
        return mem[i][j];
    int option1 = edit_distance(i-1, j-1, a, b) + alignment_score(a[i], b[j]);
    int option2 = edit_distance(i-1, j, a, b) + alignment_score(a[i], '_');
    int option3 = edit_distance(i, j-1, a, b) + alignment_score('_', b[j]);
    mem[i][j] = min(option1,min(option2, option3));
    return mem[i][j];
}

void backtrack(int i, int j){
    if(i == 0 || j == 0)
        return;
    bool d,a,l = a = d = 0;
    if(i-1>=0 && mem[i-1][j]+1 == mem[i][j])
        a = true;
    if(j-1>=0 && mem[i][j-1]+1 == mem[i][j])
        l = true;
    if(j-1>=0  && i-1>=0 && mem[i-1][j-1]+1 == mem[i][j])
        d = true;
    cout << a << ' ' << l << ' ' << d << endl;
    backtrack(i-1, j-1);
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
        if(s1.length()-1 == m){
            int l = s1.length()-s2.length();
            for(int i = 0; i < l; i++){
                s2+='_';
            }
        }
        if(s2.length()-1 == m){
            int l = s2.length()-s1.length();
            for(int i = 0; i < l; i++){
                s1+='_';
            }
        }
        for(int i = 0; i < 100; i++)
            for(int j = 0; j < 100; j++)
                mem[i][j] = INT_MIN;

        cout << "Case #" << c << ": you can visit at most " << edit_distance(m, m, s1, s2) << " cities.\n";
        for(int i = 0; i < s1.length(); i++){
            for(int j = 0; j < s2.length(); j++){
                cout << mem[i][j] << ' ';
            }
            cout << endl;
        }
        backtrack(m, m);
        c++;
    }
}
