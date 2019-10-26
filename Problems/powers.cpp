#include <iostream>

using namespace std;

long MOD;

void add(long &a, long b){
	a = (a + b%MOD)%MOD;
}

int calls = 0;

long power(long a, long b){
	long c = 1;
	for(int i = 0; i < b; i++)
		c = (c * a)%MOD;
	return c;
}

int main(){
	long a, b;
	cin >> a >> b;
	MOD = a;
	cout << (a%2==0 ? power(a/2, b) : 0 ) << endl;
}
