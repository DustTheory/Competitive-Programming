#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int prev1 = 1;
	int prev2 = 1;
	int curr;
	cout << 1 << endl << 1 << endl;
	for(int i = 2; i < n; i++){
		curr = prev1+prev2;
		prev1 = prev2;
		prev2 = curr;
		cout << curr << endl;
	}
}
