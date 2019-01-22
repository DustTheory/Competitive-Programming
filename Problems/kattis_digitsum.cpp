#include <iostream>
#include <cmath>

using namespace std;

int sumofdigits(int n){
	int sum = 0;
	while(n > 0){
		sum += n%10;
		n/=10;
	}
	return sum;
}

int main(){
	int sum = 0;
	for(int i = 0; i <= 100; i++)
		sum += sumofdigits(i);
	cout << sum << endl;
	cout << 45 + 45 * 11 << endl;
	return 0;
 }
  