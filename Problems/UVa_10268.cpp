#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    while(1){
        string line1, line2;
        if(cin.eof())
            break;
        getline(cin, line1);
        getline(cin, line2);
        stringstream ss1(line1), ss2(line2);

        vector<int> c,x;

        int n;
        while(ss1 >> n)
            x.push_back(n);
        while(ss2 >> n)
            c.push_back(n);
        for(int i = 0; i < x.size(); i++){
            long long res = 0;
            long long curr = 1;
            for(int j = c.size()-2; j >= 0; j--){
                res += curr*c[j]*(c.size()-1-j);
                curr*=x[i];
            }
            cout << res << (i == x.size()-1 ? "\n" : " ");
        }
    }
}
