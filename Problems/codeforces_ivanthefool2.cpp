#include <iostream>

using namespace std;

long long a(int x){
	return (x*(1+x+(x*x)))/(1-x-(x*x));
}

int main(){
	for(int i = 0; i <=10; i++)
		cout << a(i) << endl;
}
