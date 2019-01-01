#include <iostream>

using namespace std;

float pow(float a, int n){
  //  if(n == 0)
  //      return 0;
    float res = 1;
    for(int i = 0; i < n; i++)
        res *= a;
    return res;
}

string log(int a, int b, int c){
    string res = "";
    for(int i = 0; i < a; i++)
        res+="L";
    for(int i = 0; i < b; i++)
        res+="W";
    for(int i = 0; i < c; i++)
        res+="L";
    return res;
}

float solve(int n, float p){
    float res = 0;
    float q = 1.0 - p;
    for(int i = 0; i < n/2; i++){
        // Lose the first i games;
        float a = pow(q, i);
        for(int j = i+1; j <= n; j++){
                // Win the next (j-i) games and lose the rest
                int wins = j-i;
                    int l2 = n-i-wins;
                    float tmp = pow(p, wins)* pow(q, l2);
                    float inv = pow(p, l2) * pow(q, wins);
                    //cout << i << ' ' << j << endl;
                    //cout << wins << ' ' << l2 << endl;
                    cout << log(i, wins, l2) << "  " << wins <<  "   " <<  a*tmp << endl;
                    res += a*tmp*wins;
                    res += a*inv*(n-wins);
        }
    }
    cout << res << endl;
}

int main(){
    int n;
    float p;
    cin >> n >> p;
    solve(n, p);
}
