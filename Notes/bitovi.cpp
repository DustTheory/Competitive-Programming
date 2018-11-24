#include <iostream>

using namespace std;

#define p1 2
#define p2 10
#define p3 26

void res(){
	int n;
	cin >> n;
	int bi, ni, by = bi = ni = 0;
	// puni ciklusi
	bi = 1 << n/p3-1;
	n /= p3;
	if(n == 0){
		cout << bi << ni << by << endl;
		return;
	}	
	if(n>=p1 && n < p2){
		ni = bi;
		bi = 0;	
		cout << bi << ni << by << endl;
		return;
	}
	if(n >= p2){
		by = bi;
		bi = 0;
		cout << bi << ni << by << endl;
		return;
	}
	return;
}

int main(){
	res();
}
