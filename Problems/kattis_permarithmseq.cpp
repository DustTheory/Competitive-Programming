#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int arr[n];
		int arr2[n];
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		for(int i = 0; i < n; i++)
			arr2[i] = arr[i];
		sort(arr, arr+n);
		bool sorted = true;
		for(int i = 0; i < n; i++){
			if(arr[i] != arr2[i]){
				sorted = false;
				break;
			}
		}
		bool arithm = true;
		int interv = abs(arr[2] - arr[1]);
		for(int i = 1; i < n; i++)
			if(arr[i] - arr[i-1] != interv){
				arithm = false;
				break;
			}
		if(arithm && sorted)
			cout << "arithmetic" << endl;
		else if(arithm)
			cout << "permuted arithmetic" << endl;
		else
			cout << "non-arithmetic" << endl;
	}
}
