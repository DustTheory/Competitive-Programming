#include <iostream>
#include <iomanip>
using namespace std;

long double rekurzija(int n, int R){
	if(n == 1)
		return 3*R;
	return 1/(1/rekurzija(n-1, R) + 1/(long double)R) + 2*(long double)R;
}

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cout << setprecision(20) << rekurzija(i, 1) << endl;
}
