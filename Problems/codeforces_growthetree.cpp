#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> L;

int main(){
	int n;
	cin >> n;
	int x;
	for(int i = 0; i < n; i++){
		cin >> x;
		L.push_back(x);
	}
	sort(L.rbegin(), L.rend());
	unsigned long long a = 0, b = 0, c;
	int i = 0;
	for(; i < ceil((double)L.size()/2.0); i++){
		a += L[i];	
	}
	for(; i < L.size(); i++){
		b+= L[i];
	}
	c = a*a + b*b;
	cout << c << endl;
}
