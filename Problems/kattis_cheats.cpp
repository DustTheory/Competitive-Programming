#include <iostream>
#include <vector>

using namespace std;

int arr[210];
vector<int> arr2[210];

int all_combinations(int c, int p = 1){
	//don't use cheat
	int res = 0;
	for(int next : arr2[p]){
		cout << next << endl;
		res += all_combinations(next) + 1;
	}

	//if(p != 1 && c > 0){
		//use cheat
		
	//}
	return res;
}

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 2; i <= n; i++){
		cin >> arr[i];
		arr2[arr[i]].push_back(i);
	}
	
	cout <<	all_combinations(k) << endl;

}
