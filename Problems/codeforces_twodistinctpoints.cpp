#include <iostream>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		int a = l1;
		int b = l2;
		if(a == b && l2 + 1 <= r2)
			b = l2+1;
		else if(a == b && l1 + 1 < r1)
			a = l1+1;
		cout << a << ' ' << b << endl;
	}
 }
  