#include <utility>
#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<long, int> pli;

vector<pli> S;
#define IRREVERSIBLE -1

int R[10] = {0, 1, 2, -1, -1, 5, 9, -1, 8, 6};

long reverse(long n){
	long r = 0;	
	while(n > 0){
		int d = n%10;
		n/=10;
		if(R[d] == -1)
			return -1;
		r*=10;
		r+=R[d];
	}
	return r;
}

int main(){
	long n, s, x;
	cin >> n >> s;
	int paircnt = 0;
	for(int i = 0; i < n; i++){
		cin >> x;
		long r = reverse(x);
		if(r != IRREVERSIBLE)
			S.push_back({x, paircnt}),
			S.push_back({r, paircnt}), paircnt++;
		else
			S.push_back({x, -1});
	}

	sort(S.begin(), S.end(), [](pli &a, pli &b){
		return a.first < b.first;
	});

	for(int i = 0; i < S.size(); i++){
		long needed = s - S[i].first, pi = S[i].second;
		auto it = lower_bound(S.begin(), S.end(), needed, [pi](pli &a, long b){
			return a.first < b || a.second == pi;
		});
		if(it != S.end() && it->first == needed){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

}
