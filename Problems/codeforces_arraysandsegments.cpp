#include <iostream>
#include <utility>
#include <vector>

using namespace std;

pair<int, int> segs[310];
int arr[310];
int n, m;

int solve(int minp, int maxp){
	vector<int> affectmaxi;
	vector<int> affectmini;
	int arrc[n];
	for(int i = 0; i < n; i++)
		arrc[i] = arr[i];
	bool include[m] = {};
	for(int i = 0; i < m; i++){
		int from = segs[i].first;
		int to = segs[i].second;
		bool maxia = false, minia = false;
		if(maxp >= from && maxp <= to)
			maxia = true;
		if(minp >= from && minp <= to)
			minia = true;
		if(minia && !maxia){
			affectmini.push_back(i);
			include[i] = true;
		}
	}

	for(int i = 0; i < affectmini.size(); i++){
		for(int j = segs[affectmini[i]].first; j <= segs[affectmini[i]].second; j++){
			arrc[j]--;
		}
	}
	int maxi, mini;
	maxi = 0;
    mini = 1 << 29;
	for(int i = 0; i < n; i++){
		if(arrc[i] > maxi){
			maxi = arrc[i];
			maxp = i;
		}
		if(arrc[i] < mini){
			mini = arrc[i];
			minp = i;
		}
	}
	cout << "##########?" << endl;
	cout << maxi-mini << endl;
	cout << affectmini.size() << endl;
	for(int i = 0; i < affectmini.size(); i++){
		cout << affectmini[i] + 1 << (i == affectmini.size()-1 ? "\n" : " ");
	}
	cout << "########" << endl;
}

int main(){

	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		segs[i] = pair<int, int>(a, b);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << solve(i, j) << endl;
		}
	}	
	
	return 0;
 }
  