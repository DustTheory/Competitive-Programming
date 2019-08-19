#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

bool reachable[100]; 
bool reachable2[100];
bool mat[100][100];
bool res[100][100];

void dfs(int s, int v){
	if(s == v)
		return;
	reachable2[s] = true;
	for(int i = 0; i < 100; i++)
		if(mat[s][i] && !reachable2[i]){
			dfs(i, v);
		}

}

void dfs2(int s){
	reachable[s] = true;
	for(int i = 0; i < 100; i++)
		if(mat[s][i] && !reachable[i])
			dfs2(i);
}

int main(){
	int T;
	cin >> T;
	int c = 1;
	while(T--){
		for(int i = 0; i < 100; i++){
			fill(mat[i], mat[i]+100, false);
			fill(res[i], res[i]+100, false);
		}
		int N;
		cin >> N;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				cin >> mat[i][j];
		fill(reachable, reachable+N, false);
		int s = 0;
		dfs2(s);
		for(int i = 0; i < N; i++){
			if(s != i || i == 0){
				fill(reachable2, reachable2+N, false);
				dfs(s, i);
				for(int j = 0; j < N; j++){
					if(reachable[j] && !reachable2[j]){
						res[i][j] = true;
					}
				}
			}
		}	
		cout << "Case " << c << ':' << endl;
		for(int i = 0; i < N; i++){
			cout << '+';
			for(int j = 0; j < 2*N-1; j++)
				cout << '-';
			cout << "+\n";
			for(int j = 0; j < N; j++){
				cout << '|' << (res[i][j] ? 'Y' : 'N');
			}
			cout << "|\n";
		}

			cout << '+';
			for(int j = 0; j < 2*N-1; j++)
				cout << '-';
			cout << "+\n";
		c++;
	}
	return 0;
}
