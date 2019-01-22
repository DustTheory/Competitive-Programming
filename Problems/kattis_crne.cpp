#include <iostream>

using namespace std;

int main(){
	long long n;
	cin >> n;
	if(n == 0)
		cout << 0 << endl;
	else if(n % 2 == 0)
		cout << (n/2+1)*(n/2+1) << endl;
	else
		cout << ((n+1)/2) * ((n+1)/2+1) << endl;
	return 0;
 }
  