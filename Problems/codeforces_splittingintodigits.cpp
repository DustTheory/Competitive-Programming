#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int n;
	cin >> n;
	if(n == 0){
		cout << 0 << endl;
	}
	else if(n == 1)
		cout << 1 << endl << 1 << endl;
	else{
		int mini = 99999;
		int mini_id = 1;
		for(int i = 1; i <= 9; i++){
			int digits = 1;
			if(n%i != 0)
				digits++;
			if(digits < mini && n/i + (n % i == 0 ? 0 : 1) <= n){
				mini = digits;
				mini_id = i; 
			}
		}

		int sum = 0;
		cout << n/mini_id + (n % mini_id == 0 ? 0 : 1) << endl;
		while(sum+mini_id <= n){
			cout << mini_id << endl;
			sum += mini_id;
		}
		if(sum < n)
			cout << n-sum << endl;
		return 0;
	}
 }
  