#include <vector>
#include <iostream>

using namespace std;

int V[2010];
int W[2010];
int c, n;

int mem[2010][2010];

int dp(int a, int b){
	if(b < 0)
		return 0;
	if(a>=n)
		return mem[a][b] = 0;
	if(mem[a][b] != -1)
		return mem[a][b];
	return mem[a][b] =  max(dp(a+1, b), (b >= W[a] ? dp(a+1, b-W[a]) + V[a] : 0));
}

void clearmem(){
	for(int i = 0; i < 2010; i++)
		for(int j = 0; j < 2010; j++)
			mem[i][j] = -1;
}

vector<int> res;

int opti;

void backtrack(int a, int b){
	if(a > n || b < 0)
		return;
	if(a+1 <= n && b-W[a] >= 0 && mem[a][b] == V[a] + mem[a+1][b-W[a]])
		backtrack(a+1, b-W[a]), res.push_back(a);
	else if(a+1 <= n)
		backtrack(a+1, b);
}

int main(){
	while(cin >> c >> n){

	for(int i = 0; i < n; i++)
		cin >> V[i] >> W[i];
	clearmem();
	opti = dp(0, c);
	res.clear();
//	for(int i = 0; i <= n; i++){
//		cout << V[i] << ' ' << W[i] << " : ";
//		for(int j = 0; j <= c; j++)
//			cout << mem[i][j] << ' ';
//		cout << endl;
//	}
	res.clear();
	backtrack(0, c);
	cout << res.size() << endl;
	for(int j = 0; j < res.size(); j++)
		cout << res[j] << (j == res.size()-1 ? "\n" : " ");
	}
}
