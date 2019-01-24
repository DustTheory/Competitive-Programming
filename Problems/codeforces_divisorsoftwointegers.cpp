#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr+n);
	int a = arr[n-1];
	bool deleted[10010] = {};
	for(int i = 0; i < n; i++){
		if(a % arr[i] == 0){
			if(!deleted[arr[i]]){
				deleted[arr[i]] = true;
				arr[i] = -1;
			}
		}
	}
	cout << a << ' ';
	for(int i = n-1; i >= 0 ; i--){
		if(arr[i] != -1){
			cout << arr[i] << endl;
			break;
		}
	}
 }
  