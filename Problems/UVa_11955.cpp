#include <iostream>
#include <sstream>
#include <string>

using namespace std;

unsigned long long pascals_triangle[53][53];

void generate_pascals_triangle(){
    pascals_triangle[1][1] = 1;
    for(int i = 2; i <= 51; i++){
        for(int j = 1; j <= i; j++){
            pascals_triangle[i][j] = pascals_triangle[i-1][j-1]+pascals_triangle[i-1][j];
        }
    }
}

int main(){
    generate_pascals_triangle();
    int t;
    cin >> t;
    cin.ignore();
    for(int tc = 0; tc < t; tc++){
        char a[101], b[101];
        int k;
        string line;
        getline(cin, line);
        sscanf(line.c_str(), "(%101[^+]+%101[^)])^%d", a, b, &k);
        cout << "Case " << tc+1 << ": ";
        for(int i = 1; i <=k+1; i++){
            unsigned long long d = pascals_triangle[k+1][i], e =  k-i+1, f = i-1;
            if(d != 1)
                cout << d << "*";
            if(e == 1)
                cout << a;
            else if(e != 0)
                cout << a << "^" << e;
            if(e != 0 && f != 0)
                cout << "*";
            if(f == 1)
                cout << b;
            else if(f != 0)
                cout << b << "^" << f;
            if(i != k+1)
                cout << "+";
        }
        cout << endl;
    }

}
