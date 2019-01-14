#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void solve(int n, int d, int t){
    int j = 0;
    int cnt = 0;
    for(int i = 1; i < n/2+!(n%2==0); i++)
        if(j == t)
            break;
        else{
            j += n;
            cnt++;
        }
    if(j != t){
        j += (n+!(n%2==0))/2;
        cnt++;
    }
    double longest_diag, angle, radius;
    longest_diag = 2*d;
    angle = (2*(M_PI)/n)*(cnt+1);
    radius = sqrt(longest_diag*longest_diag/(2*(1-cos(angle))));
    cout << fixed << setprecision(5) << radius << endl;
}

void solve2(int n, int d, int t){
    int j = 0;
    int cnt = 0;
    for(int i = 1; i < n/2+!(n%2==0); i++)
        if(j == t)
            break;
        else{
            j += n;
            cnt++;
        }
    if(j != t){
        j += (n+!(n%2==0))/2;
        cnt++;
    }
    double longest_diag, angle, radius;
    longest_diag = 2*d;
    angle = (2*(M_PI)/n)*(cnt);
    radius = sqrt(longest_diag*longest_diag/(2*(1-cos(angle))));
    cout << fixed << setprecision(5) << radius << endl;
}

int main(){
    int n, d , t;
    while(cin >> n >> d >> t){
    int novo_T = t * 2 / n == n - 2 ? (t * 2 / n + 1) * (n / 2) : (t * 2 / n + 2) * (n / 2);
    if(((t * 2) / n) == n - 1){
       cout << fixed << setprecision(5) << 0 << endl;
    }else if((t * 2) / n == n - 2){
        cout << fixed << setprecision(5) << d << endl;
    }else{
        solve(n, d, t);
    }
    solve2(n, d, t);
}
}

