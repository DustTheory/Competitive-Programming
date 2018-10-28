#include <iostream>
#include <sstream>
#include <stack>
#include <limits.h>

using namespace std;

int mem[101][101];

int edit_distance(int i, int j, string &a, string &b){
    if(i == 0){
        mem[i][j] = j;
        return j;
    }
    if(j == 0){
        mem[i][j] = i;
        return i;
    }
    if(mem[i][j] != INT_MIN)
        return mem[i][j];
    int cost = 1;
    if(a[i-1] == b[j-1])
        cost = 0;
    int option1 = edit_distance(i-1, j-1, a, b) + cost;
    int option2 = edit_distance(i-1, j, a, b) + 1;
    int option3 = edit_distance(i, j-1, a, b) + 1;

    mem[i][j] = min(option1,min(option2, option3));
    return mem[i][j];
}

ostringstream result;

void backtrack(int i, int j, string &a, string &b){
    if(i == -1 || j == -1)
        return;

    int up, left, diag = up = left = INT_MAX;
    if(i > 0)
        up = max(0,mem[i-1][j]);
    if(j > 0)
        left = max(0, mem[i][j-1]);
    if(i > 0 && j > 0)
        diag = max(0, mem[i-1][j-1]);
    int m = min(diag, min(left, up));

    if(m == INT_MAX)
        return;

    if(m == diag && a[i-1] != b[j-1]){
        result << "Replace " << j << ',' << b[j-1] << endl;
        backtrack(i-1, j-1, a, b);
    }else if(m == diag){
        backtrack(i-1, j-1, a, b);
    }else if(m == up){
        result << "Delete " << j+1 << endl;
        backtrack(i-1, j, a, b);
    }else if(m == left){
        result << "Insert " << j << ',' << b[j-1] << endl;
        backtrack(i, j-1, a, b);
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
        if(cin.eof())
            break;
        getline(cin, s2);
        if(cin.eof())
            break;
        if(c != 1)
            cout << endl;
        int m = max(s1.length(), s2.length())-1;
        for(int i = 0; i < 101; i++)
            for(int j = 0; j < 101; j++)
                mem[i][j] = INT_MIN;


        int ed = edit_distance(s1.length(), s2.length(), s1, s2);
        cout << ed << "\n";
        result = ostringstream();
        backtrack(s1.length(), s2.length(), s1, s2);
        // Reverse stringstream
        istringstream iss (result.str());
        stack<string> o;
        string temp;
        while(getline(iss,temp))
            o.push(temp);
        int cnt = 1;
        while(!o.empty()){
            cout << cnt << ' ' << o.top() << endl;
            o.pop();
            cnt++;
        }
        c++;
    }
}
