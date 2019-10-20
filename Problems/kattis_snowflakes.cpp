#include <iostream>
#include <map>

using namespace std;

int arr[1000010];

int main(){
	int T;
	cin >> T;
	while(T--){
	int n;
	cin >> n;	
	
	for(int i = 1; i <= n; i++)
		cin >> arr[i];

	int m = 0;
	int l = 1, r = 1;
	map<int, int> mp;
	for(int i = 1; i <= n; i++){
		auto it = mp.find(arr[i]);
		if(it == mp.end()){
			r++;
			mp.insert({arr[i], i});
		}else{
			for(int j = l; j < it->second; j++){
				mp.erase(mp.find(arr[j]));
			}
			l = it->second+1;
			it->second = i;
			r++;	
		}
		m = max(m, (r-l));
	}
	cout << m << endl;
	}
}
