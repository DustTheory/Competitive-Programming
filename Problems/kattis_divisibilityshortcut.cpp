#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
	int b, k;
	cin >> b >> k;
	int maxi = 1;
	int c = b-1;
		for(int i = 1; i <= sqrt(b) ; i++){
			if(c%i ==0){
				int x=i, y=c/i;
				//cout << x << ' ' << y << endl;
				if(x > k)
					x = 1;
				if(y > k)
					y = 1;
				maxi = max(maxi, max(x, y));
			}
		}
		cout << maxi << endl;
	}
}
