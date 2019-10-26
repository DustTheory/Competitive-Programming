#include <set>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[10010];

int lis(vector<int> &V){
	
	multiset<int> s;
	multiset<int>::iterator it;
	for(int i = 0; i < V.size(); i++){
		s.insert(V[i]);
		it = upper_bound(s.begin(), s.end(), arr[i]);
		if(it!=s.end())
			s.erase(it);
	}
	return s.size();
}


int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int res = 0;

	for(int k = 0; k < n; k++){
	vector<int> lesser;
	vector<int> greater;

	int cnt = 1;
	for(int i = k+1; i < n; i++)
		if(arr[i] > arr[k])
			greater.push_back(arr[i]);
		else
			lesser.push_back(arr[i]);
		
	vector<int> G(greater.size(), -1);

	for(int i = 0; i < greater.size(); i++){
		int g = 0;
		for(int j = i+1; j < greater.size(); j++){
			if(greater[j] > greater[i])
				g++;	
		}
		G[i] = g;	
	}
	
	vector<int> L(lesser.size(), -1);

	for(int i = 0; i < lesser.size(); i++){
		int l = 0;
		for(int j = i+1; j < lesser.size(); j++){
			if(lesser[j] < lesser[i])
				l++;
		}
		L[i] = l;	
	}

	cout << endl;
	cout << endl;
	cout << endl;

	for(int i = 0; i < L.size(); i++)
		cout << lesser[i] <<  ' ' << L[i] << endl;

	reverse(G.begin(), G.end());
	reverse(L.begin(), L.end());
	res = max(res, 1+lis(L) + lis(G));
	}
	cout << res << endl;
}
