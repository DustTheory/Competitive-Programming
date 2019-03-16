#include <iostream>

using namespace std;

long long choose(int n, int k){
	long long ncm = 1;
	int norg = n;
	for(int i = n; i >= norg-k+1; i--)
		ncm *= i;
	long long f = 1;
	for(int i = 2; i <=k; i++)
		f*=i;
	return ncm/f;
}

int main(){
	int n, m;	
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		if(n == 0 || m > n)
			cout << 0 << endl;
		else
			cout << choose(n, m-1) << endl;
	}
}
