#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){
    cout << "PERFECTION OUTPUT" << endl;
    int n;
    while(cin >> n){
        if(n == 0)
            break;
        int sum = 0;
        for(int i = 1; i < n; i++)
            if(n % i == 0)
                sum += i;
        cout << setw(5) << n << "  ";
        if(sum == n)
            cout << "PERFECT" << endl;
        else if(sum < n)
            cout << "DEFICIENT" << endl;
        else cout << "ABUNDANT" << endl;
    }
    cout << "END OF OUTPUT" << endl;
}
