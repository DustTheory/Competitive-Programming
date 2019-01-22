#include<iostream>

using namespace std;

#define ull unsigned long long

ull sumofdigits(ull a){
	ull sum = 0;
	while(a > 0){
		sum += a%10;
		a/=10;
	}	
	return sum;
}

int main(){
	ull n;
	while(1){
		cin >> n;
		if(n == 0)
			break;
		ull p = 11;
		ull s = sumofdigits(n);
		while(1){
			if(sumofdigits(p*n) == s){
				cout << p << endl;
				break;
			}
			p++;
		}
	}
}