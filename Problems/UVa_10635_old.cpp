#include <iostream>
#include <vector>

using namespace std;
#define MAX 255*255+1

vector<vector<int>> mem;

int lcs2(vector<int> &a, vector<int> &b){
	for(int i = 0; i <= a.size(); i++){
		for(int j = 0; j <= b.size(); j++){
			if(i == 0 || j == 0)
				mem[i][j] = 0;
			else{
				if(a[i-1] == b[j-1])
					mem[i][j] = mem[i-1][j-1] + 1;
				else
					mem[i][j] = max(mem[i-1][j], mem[i][j-1]);
			}
		}
	}
	//for(int i = 0; i <= al; i++){
	//	for(int j = 0; j <= bl; j++)
	//		cout << mem[i][j] << ' ';
	//	cout << endl;
	//}
	return mem[a.size()][b.size()];
}

int main(){
	int tc;
	cin >> tc;
	for(int t = 0; t < tc; t++){
		int n, p, q;
		cin>> n >> p >> q;
		vector<int> prince;
		vector<int> queen;
		bool square[n*n+2];
		for(int i = 0; i <= n*n+2; i++)
	       		square[i] = false;
		for(int i = 0; i <= p; i++){
			int tmp;
			cin >> tmp;
			square[tmp] = true;
			prince.push_back(tmp);
		}
		bool newsquare[n*n+2];
		for(int i = 0; i <= n*n+2; i++)
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
		for(int i = 0; i < prince.size(); i++){
			if(newsquare[prince[i]]){
				newprince.push_back(prince[i]);
			}
		}
		mem.clear();
		for(int i = 0;  i <= newprince.size(); i++){
			mem.push_back(vector<int>());
			for(int j = 0; j <= queen.size(); j++){
				mem[i].push_back(0);
			}
		}
		cout << "Case " << t+1<< ": " << lcs2(newprince, queen) << endl;
	}
}


