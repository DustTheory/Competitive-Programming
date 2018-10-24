#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool is_pal(string &s, int from, int to){
    if(to-from == 1)
        return true;
    if(to-from == 2){
        if(s[from] == s[from+1])
            return true;
        else return false;
    }
    for(int i = from; i < (from+to)/2; i++){
        if(s[i] != s[to-i+from-1] && i != to-i+from-1){
            return false;
        }
    }
    return true;
}

string pal(string &s){
    for(int i = 0; i < s.length(); i++){
        bool is_p = is_pal(s, i, s.length());
        if(is_p){
            string tmp = s.substr(0, i);
            return string(tmp.rbegin(), tmp.rend());
        }
    }
    return string(s.rbegin(), s.rend());
}


int main(){
    string s;
    while(cin >> s){
        // Find the palindrome in the string and copy and
        // reverse everything around it
        if(s.length() == 1)
            cout << s << endl;
        else
            cout << s << pal(s) << endl;
    }
}
