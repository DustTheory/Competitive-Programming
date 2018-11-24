#include <iostream>

using namespace std;

int powah10(int n){
	int res = 10;
	for(int i = 2; i <= n; i++){
		res*=10;
	}
	return res;
}

int generate_num(int n){
	int res = 0;
	for(int i = 1; i <= n; i++){
		res *= 10;
		res += i;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	int num = generate_num(n);
	cout << num << '/' << powah10(n)-1 << endl; 
}
