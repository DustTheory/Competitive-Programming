#include <iostream>
#include <vector>

using namespace std;

#define NAN -420694206
#define nINF -99999999

vector<vector<int>> mem;

int lcs(int i , int j, vector<int> &a, vector<int> &b){
	if(i == -1 || j == -1)
		return 0;
	if(mem[i][j] != NAN)
		return mem[i][j];		
	int score = nINF;
	if(a[i] == b[j])
		score = 1;
	int  option1 = lcs(i-1, j-1, a, b);
	if(option1 != nINF)
		 option1 += score;
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
		bool square[n*n+1];
		for(int i = 0; i <= n*n+1; i++)
		    square[i] = false;
		for(int i = 0; i <= p; i++){
			int tmp;
			cin >> tmp;
			square[tmp] = true;
			prince.push_back(tmp);
		}
		bool newsquare[n*n+1];
		for(int i = 0; i <= n*n+1; i++)
		    newsquare[i] = false;
		for(int i = 0; i <= q; i++){
			int tmp;
			cin >> tmp;
			if(square[tmp]){
		    	queen.push_back(tmp);
				newsquare[tmp] = true;
			}
		}
		vector<int> newprince;
		for(int i =0; i < prince.size(); i++){
			if(newsquare[prince[i]]){
				newprince.push_back(prince[i]);
			}
		}
		for(int i = 0; i < newprince.size(); i++){
			cout << newprince[i] << ' ';
		}
		cout << endl;
		for(int i = 0; i < queen.size(); i++){
			cout << queen[i] << ' ';
		}
		cout << endl;
		mem.clear();
		for(int i = 0; i <= p; i++){
			mem.push_back(vector<int>());
			for(int j = 0; j <= q; j++){
				mem[i].push_back(NAN);
			}
		}
		cout << "Case " << t+1<< ": " << lcs(newprince.size()-1, queen.size()-1, newprince, queen) << endl;
	}
}
