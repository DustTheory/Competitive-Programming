#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
  /*  int n;
    std::cin >> n;
    double last = log(102./101.);
    double test = log(102.0) - log(101.0);
    std::cout << std::fixed << std::setprecision(20 ) << test << " " << last << std::endl;
    for(int i = 1; i <= n; i++){
        last = ((double)(1 << i) - 1.0)/((double)i) - (100.0*last) ;
    }
    std::cout << last << std::endl;
    */
    double sum = 0;
    int n = 10;
    for(int  i = 0; i < 5; i++){
        sum += (1.0 - (double)(1 << (n+1+i)))/(precise_power(-100.0, i+1)*(n+1.0+i));
    }
    std::cout << sum << std::endl;
}
