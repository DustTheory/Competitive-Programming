#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<unsigned long long> factorials;

void generate_fac(int n){
	unsigned long long curr = 1;
	for(int i = 1; i <= n; i++){
		if(curr > ((unsigned long long)-1)/i) 
			break;
		curr *= i;
		factorials.push_back(curr);
	}
}

int main(){
	unsigned long long p;
	cin >> p;
	generate_fac(10000000);
	cout << factorials.size() << endl;
}
