#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
    int n, d , t;
    while(cin >> n >> d >> t){
        int cnt = (t-1)/n + 1;
        double longest_diag = 2 * d;
        double min_angle = (2 * M_PI / n) * (cnt + 1);
        double max_angle = (2 * M_PI / n) * cnt;
        double min = sqrt(longest_diag * longest_diag / (2 * (1 - cos(min_angle))));
        double max = sqrt(longest_diag * longest_diag / (2 * (1 - cos(max_angle))));

        if((t * 2) / n == n - 1)
            cout << fixed << setprecision(5) << 0 << " ";
        else if((t * 2) / n == n - 2)
            cout << fixed << setprecision(5) << d << " ";
        else
            cout << fixed << setprecision(5) << min << " ";

        cout << fixed << setprecision(5) << max << endl;
    }
    return 0;
}
