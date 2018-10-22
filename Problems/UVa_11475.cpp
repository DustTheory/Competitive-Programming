#include <iostream>
#include <algorithm>
using namespace std;

string pal(string &s){
        for(int i = 0; i < s.length(); i++){
            int start = 0;
            bool flag = false;
            for(int j = i; j < (i+s.length())/2; j++){
                if(j != s.length()-j-1){
                    if(s[j] == s[s.length()-j-1]){
                        if(!flag){
                            flag = true;
                            start = j;
                        }
                    }else{
                        flag = false;
                        start = 0;
                    }
                }
            }
            if(i == s.length()-1 && start == 0){
             //   int shift = (s[i] == s[])
               // cout << "no" << endl;
                return string(s.rbegin()+1, s.rend());
            }
            if(flag){
              //  cout << start << endl;
                if(start == 0){
                    return "";
                }else{
                    string res = s.substr(0, start+1);
                    return s.substr(start+1, s.length()-start-1) + string(res.rbegin(), res.rend());
                }
            }
        }
    }


string fix(string &s1, string s2){
    if(s2.length() == 0)
        return s1;
    string res = s1;
    int pt = 0;
    for(int i = 0; i < s2.length(); i++){
        if(s2[i] != s1[s1.length()-i-1])
            break;
        pt++;
    }
    if(pt == s2.length()){
        int c = 0;
        for(int i = 1; i < s2.length() ; i++){
            if(s2[i] == s2[i-1]){
                c++;
            }else{
                break;
            }
        }
        cout << c << ' ' << s2 << endl;
        return s1 + s2.substr(c+1, s2.length()-c);
    }
    res += s2.substr(pt, s2.length()-pt+1);
    return res;
}

int main(){
    string s;
    while(cin >> s){
        // Find the palindrome in the string and copy and
        // reverse everything around it
        if(s.length() == 1)
            cout << s << endl;
        else
            cout << fix(s, pal(s)) << endl;
    }
}
