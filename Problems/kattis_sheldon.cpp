#include <iostream>
#include <limits.h>

using namespace std;

unsigned long long calc(unsigned long long maxi){

	int digits = 0;
	bool pow2 = true;	
	unsigned long long c_maxi = maxi;
	
	while(c_maxi > 0){
		digits++;
		if(pow2 && !(c_maxi & 1))
			pow2 = false;
		c_maxi >>=1;
	}

	cout << digits <<  ' ' << pow2 << endl;

	unsigned long long noways = 0;
	
	for(int m = 1; m < digits; m++){
		for(int n = 1; n < digits; n++){
			noways += digits/(n+m); 
			if(digits % (2*n+m) == 0)
				noways++;
		}
	}

	if(pow2)
		noways += digits;
	else
		noways += digits-1;

	return noways;
}

int main(){
	unsigned long long mini, maxi;
	cin >> mini >> maxi;
	calc(1);
	//	cout << calc(maxi) << ' ' <<  calc(mini-1) << endl;
}
