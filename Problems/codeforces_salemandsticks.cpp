#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int min_c = 99999;
	int min_t = 1;
	for(int t = 0; t <= 101; t++){
		int c = 0;
		for(int i = 0; i < n; i++){
			int changeto;
			if(arr[i] == t)
				changeto = t;
			else if(arr[i] > t)
				changeto = t+1;
			else
				changeto = t-1;
			c += abs(arr[i]-changeto);
		}
		if(c <= min_c){
			min_c = c;
			min_t = t;
		}
		//cout << t << ' ' << c << endl;
	}
	cout << min_t << ' ' << min_c << endl;
}