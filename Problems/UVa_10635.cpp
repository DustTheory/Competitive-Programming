#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> mem;

int lis(int i, vector<int> &a){
	set<int> s;
	set<int>::iterator it;
	for(int i = 0; i < a.size(); i++){
		it = s.insert(a[i]).first;
		it++;
		if(it!=s.end())
			s.erase(it);
	}
	return s.size();
}

int main(){
	int tc;
	cin >> tc;
	for(int t = 1; t <= tc; t++){
		int n, q, p, tmp;
		cin >> n >> p >> q;
		int square[n*n+1];
		for(int i = 0; i <= n*n+1; i++)
			square[i] = -1;
		for(int i = 0; i <= p; i++){
			cin >> tmp;
			square[tmp] = i;
		}
		vector<int> queen;
		for(int i = 0; i <= q; i++){
			cin >> tmp;
			if(square[tmp] != -1)
				queen.push_back(square[tmp]);
		}
//		for(int i = 0; i < queen.size(); i++)
//			cout << queen[i] << endl;
		cout << "Case " << t << ": " << lis(queen.size(), queen) << endl;
	}
}
