#include <iostream>

using namespace std;

bool is_special(char c){
    if(c >= '[' && c <= ']')
        return true;
    if(c >= '!' && c <= '*')
        return true;
    return false;
}

string escape(string s){
    string result;
    for(int i = 0; i < s.length(); i++){
        if(is_special(s[i]))
           result += '\\';
        result += s[i];
    }
    return result;
}

int main(){
    int n;
    while(cin >> n){
        string s;
        cin.ignore();
        getline(cin, s);
        while(n--){
            s = escape(s);
        }
        cout << s << endl;
    }
}
