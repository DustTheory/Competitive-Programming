#include <iostream>
#include <math.h>
using namespace std;

int arr[100010];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	unsigned long long cost = 0;
	int p = 0, ng = 0, z = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] < 0){
			cost += abs(arr[i]) - 1;
			ng++;
		}else if(arr[i] > 0){
			p++;
			cost += arr[i] - 1;
		}else
			z++;
	}

	if(ng % 2 != 0 && ng != 0 ){
		if(z > 0){
			z--;
			ng++;
			cost++;
		}else{
			ng--;
			p++;
			cost+=2;
		}
	}
	cost += z;
	cout << cost << endl;
	return 0;
}
