#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int sum = 0;
	int x;
	bool b = 0;
	for(int i = 0; i < n; i++){
		cin >> x;
		if(x % 2 == 0 || x == 0){
			cout << x/2 << endl;
			continue;
		}
		if(b)
			cout << x/2 - (x < 0 ? 1 : 0) << endl;
		else
			cout << x/2+1 - (x < 0 ? 1 : 0)<< endl;
		b=!b;
	}
}
