#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int mat[110][110];

int main(){
	int r, c, n;
	cin >> r >> c >> n;
	queue<pair<int, int>> q;
	int x, y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		q.push({x, y});
		mat[x][y] = 1;
	}
	int cnt = 1;
	while(!q.empty()){
		int cx = q.front().first, cy = q.front().second; 
		q.pop();
		if(cx-1 > 0 && mat[cx-1][cy] == 0){
			q.push({cx-1, cy});
			mat[cx-1][cy] = mat[cx][cy]+1;
		}
		if(cy-1 > 0 && mat[cx][cy-1] == 0){
			q.push({cx, cy-1});
			mat[cx][cy-1] = mat[cx][cy]+1;
		}
		if(cx+1 <= r && mat[cx+1][cy] == 0){
			q.push({cx+1, cy});
			mat[cx+1][cy] = mat[cx][cy]+1;
		}
		if(cy+1 <= c && mat[cx][cy+1] == 0){
			q.push({cx, cy+1});
			mat[cx][cy+1] = mat[cx][cy]+1;;
		}
		// Another day passes
		cnt++;
	}
	int m = 1;
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
			m = max(m, mat[i][j]);
	cout << m << endl;
}
