#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

int n, m;
char mat[110][110];

void floodfill(int a, int b){
	mat[a][b] = '+';
	if(a+1 < n && mat[a+1][b] == '-')
		floodfill(a+1, b);
	if(b+1 < m && mat[a][b+1] == '-')
		floodfill(a, b+1);
	if(a-1 >= 0 && mat[a-1][b] == '-')
		floodfill(a-1, b);
	if(b-1 >= 0 && mat[a][b-1] == '-')
		floodfill(a, b-1);
}

int main(){
	int tc = 1;
	while(cin >> n >> m){
		char tmp[110];
		for(int i = 0; i < n; i++){
			scanf("%s", tmp);
			strcpy(mat[i], tmp);
		}
		int cnt = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(mat[i][j] == '-'){
					cnt++;
					floodfill(i, j);
				}
		cout << "Case " << tc << ": " << cnt << endl;
		tc++;
	}
}