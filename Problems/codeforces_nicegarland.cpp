#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
int n;

pair<int, string> solve(string t, string s){
	int changes = 0;
	for(int i = 0; i < n; i+=3){
		if(s[i] != t[0]){
			changes++;
			s[i] = t[0];
		}
	}

	for(int i = 1; i < n; i+=3){
		if(s[i] != t[1]){
			changes++;
			s[i] = t[1];
		}
	}

	for(int i = 2; i < n; i+=3){
		if(s[i] != t[2]){
			changes++;
			s[i] = t[2];
		}
	}
	return pair<int, string> (changes, s);
}

int main(){
	
	cin >> n;
	string s;
	cin >> s;
	pair<int, string> res[6] = { solve("RGB", s),
				solve("RBG", s),
				solve("BRG", s),
				solve("BGR", s),
				solve("GBR", s),
				solve("GRB", s),
	};
	sort(res, res+6, [](pair<int, string> &a, pair<int, string> &b){
		return a.first < b.first;
	});
	cout << res[0].first << endl;
	cout << res[0].second << endl;
	return 0;
 }
  