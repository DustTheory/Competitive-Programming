#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		if(n == 2)
			cout << 2 << endl;
		else{
			int half = ceil((float)n/2.0);
			cout << 2*half -  n << endl;
		}
	}
}
