#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		if(a % 2 == 0)
			cout << a << " is even" << endl;
		else
			cout << a << " is odd" << endl;
	}
}