#include <iostream>
#include <map>
#include <set>
#include <utility>
using namespace std;

int main(){
    int f, n;
    bool usable[10];
    map<char, int> keys = {
        pair<char, int>('q', 1),
        pair<char, int>('a', 1),
        pair<char, int>('z', 1),
        pair<char, int>('w', 2),
        pair<char, int>('s', 2),
        pair<char, int>('x', 2),
        pair<char, int>('e', 3),
        pair<char, int>('d', 3),
        pair<char, int>('c', 3),
        pair<char, int>('r', 4),
        pair<char, int>('f', 4),
        pair<char, int>('v', 4),
        pair<char, int>('t', 4),
        pair<char, int>('g', 4),
        pair<char, int>('b', 4),
        pair<char, int>('y', 7),
        pair<char, int>('h', 7),
        pair<char, int>('n', 7),
        pair<char, int>('u', 7),
        pair<char, int>('j', 7),
        pair<char, int>('m', 7),
        pair<char, int>('i', 8),
        pair<char, int>('k', 8),
        pair<char, int>(',', 8),
        pair<char, int>('o', 9),
        pair<char, int>('l', 9),
        pair<char, int>('.', 9),
        pair<char, int>('p', 10),
        pair<char, int>(';', 10),
        pair<char, int>('/', 10)
    };
    while(cin >> f >> n){
        fill(usable, usable+10, 1);
        int a;
        for(int i = 0; i < f; i++){
            cin >> a;
            usable[a-1] = false;
        }
        set<string> writable;
        int max_size = 0;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            bool is_writable = true;
            for(int j = 0; j < s.length(); j++){
                if(!usable[keys.find(s[j])->second-1]){
                    is_writable = false;
                    break;
                }
            }
            if(is_writable && s.length() >= max_size){
                if(s.length() > max_size){
                    writable.clear();
                    max_size = s.length();
                }
                writable.insert(s);
            }
        }

        cout << writable.size() << endl;
        for(auto w : writable){
            cout << w << endl;
        }
    }
}
