#include <iostream>

using namespace std;

unsigned long long f(unsigned long long n){
	n-=3;
	if(n%2==0)
		return n*(n+2)/4; 
	return ((n+1)/2)*((n+1)/2);
}

#define MAX 10000000

unsigned long long mem[MAX+1];

int main(){
	unsigned long long n;
	mem[3] = 0;
	mem[4] = 1;
	for(int i = 5; i < MAX; i++)
		mem[i] = f(i) + mem[i-1]; 
	while(1){
		cin >> n;
		if(n < 3)
			break;
		cout << mem[n] << endl;
	}
}
