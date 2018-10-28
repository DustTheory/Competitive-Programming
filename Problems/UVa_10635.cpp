#include <iostream>
#include <vector>

using namespace std;

#define NAN -420694206
#define nINF -999999

vector<vector<int>> mem;

int lcs(int i , int j, vector<int> &a, vector<int> &b){
	if(i == -1 || j == -1)
		return 0;
	if(mem[i][j] != nINF)
		return mem[i][j];		
	int score = -9999999;
	if(a[i] == b[j])
		score = 1;
	int  option1 = lcs(i-1, j-1, a, b) + score;
	int  option2 = lcs(i-1, j, a, b);
	int  option3 = lcs(i, j-1, a, b);
	int m = max(option1, max(option2, option3));
	mem[i][j] = m;
	return m;
}

int main(){
	int tc;
	cin >> tc;
	for(int t = 0; t < tc; t++){
		int n, p, q;
		cin>> n >> p >> q;
		vector<int> prince;
		vector<int> queen;
		for(int i = 0; i <= p; i++){
			int tmp;
			cin >> tmp;
			prince.push_back(tmp);
		}
		for(int i = 0; i <= q; i++){
			int tmp;
			cin >> tmp;
			queen.push_back(tmp);
		}
		mem.clear();
		for(int i = 0; i <= p; i++){
			mem.push_back(vector<int>());
			for(int j = 0; j <= q; j++){
				mem[i].push_back(nINF);
			}
		}
		cout << "Case " << t+1<< ": " << lcs(p, q, prince, queen) << endl;
	}
}
