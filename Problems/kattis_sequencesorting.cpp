#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

bool at_front(int arr[], int m ,int x, int c){
	for(int i = 0; i < c; i++)
		if(arr[i] != x)
			return false;
	return true;
}

bool at_back(int arr[], int m ,int x, int c){
	for(int i = m-1; i >= m-c-1; i--)
		if(arr[i] != x)
			return false;
	return true;
}

int solve(int arr[], int n){
	map<int, int> s;
	vector<int> tmp;
	for(int i = 0; i < n; i++)
		s[arr[i]]++;
	for(auto p : s){
//		cout << p.first <<  ' ' << p.second << endl;
		tmp.push_back(p.first);
	}
	int mid = tmp.size()/2;
	int l = (tmp.size() % 2 == 0 ? mid : mid-1); 
	int h = (tmp.size() % 2 == 0 ? l+1: l+2);
	int cnt = 0;
	while(1){
		cout << tmp[l] << ' '  << tmp[h] << endl;
		if(l >= 0){
			if(!at_front(arr, n, tmp[l], s[tmp[l]])){
				for(int i = 0; i < n; i++){
					if(arr[i] == tmp[l]){
						for(int j = i; j > 0; j--)
							swap(arr[j], arr[j-1]);
					}
				}
				break;	
			}else{
				cnt++;
				l--;
			}
		}
		if(h < n){
			if(!at_back(arr, n, tmp[h], s[tmp[h]])){
				for(int i = 0; i < n; i++){
					if(arr[i] == tmp[h]){
						for(int j = i; j < n-1; j++)
							swap(arr[j], arr[j+1]);
					}
				}
				break;	
			}else{
				cnt++;
				h++;
			}
		}
		if(l == 0 && h == n-1)
			break;
	}

	return s.size()-1-cnt;

}

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		cout << solve(arr, n) << endl;
	}
}
