#include <iostream>
#include <set>

using namespace std;

int main(){
   int p, n;
   set<string> parts;
   cin >> p >> n;
   string s;
   for(int i = 1; i <= n; i++){
       cin >> s;
       parts.insert(s);
       if(parts.size() == p){
        cout << i << endl;
        goto uglycode;
       }
   }
   cout << "paradox avoided" << endl;
uglycode: int keke;
}
