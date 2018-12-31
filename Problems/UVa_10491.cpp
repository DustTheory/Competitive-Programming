#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) != EOF)
        cout << fixed << setprecision(5) << (double)a*(double)b/(((double)a+(double)b)*((double)a+(double)b-(double)c-1.0)) + (double)b*((double)b-1.0)/(((double)a+(double)b)*((double)a+(double)b-(double)c-1.0)) << endl;
}
