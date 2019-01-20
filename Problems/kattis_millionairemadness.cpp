#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

const unsigned long long INF = ULONG_MAX;

#define ull unsigned long long

int n, m;

ull mat[1010][1010];

ull dijkstra(){
	ull dist[1010][1010];
	for(int i = 0; i < 1010; i++)
		for(int j = 0; j < 1010; j++)
			dist[i][j] = INF;
	queue<pair<int, int>> q;
	q.push({0, 0});
	dist[0][0] = 0;
	while(!q.empty()){
		int a = q.front().first, b = q.front().second;
		q.pop();
		if(a > 0 && mat[a-1][b] >= mat[a][b] && max(dist[a][b], mat[a-1][b] - mat[a][b]) < dist[a-1][b]){
			dist[a-1][b] = max(dist[a][b], mat[a-1][b] - mat[a][b]) ;
			q.push({a-1, b});
		}else if(a > 0 && mat[a][b] > mat[a-1][b] && dist[a-1][b] > dist[a][b]){
			dist[a-1][b] = dist[a][b];
			q.push({a-1, b});
		}
		if(b > 0 && mat[a][b-1] >= mat[a][b] && max(dist[a][b], mat[a][b-1] -  mat[a][b]) < dist[a][b-1]){
			dist[a][b-1] =  max(dist[a][b], mat[a][b-1] -  mat[a][b]);
			q.push({a, b-1});
		}else if(b > 0 && mat[a][b] > mat[a][b-1] && dist[a][b-1] > dist[a][b]){
			dist[a][b-1] = dist[a][b];
			q.push({a, b-1});
		}
		if(a < m-1 && mat[a+1][b] >= mat[a][b] && max(dist[a][b], mat[a+1][b] - mat[a][b]) < dist[a+1][b]){
			dist[a+1][b] = max(dist[a][b], mat[a+1][b] - mat[a][b]);
			q.push({a+1, b});
		}else if(a < m-1 && mat[a][b] > mat[a+1][b] && dist[a+1][b] > dist[a][b]){
			dist[a+1][b] = dist[a][b];
			q.push({a+1, b});
		}
		if(b < n-1 && mat[a][b+1] >= mat[a][b] && max(dist[a][b], mat[a][b+1] - mat[a][b]) < dist[a][b+1]){
			dist[a][b+1] = max(dist[a][b], mat[a][b+1] - mat[a][b]);
			q.push({a, b+1});
		}else if(b < n-1 && mat[a][b] > mat[a][b+1] && dist[a][b+1] > dist[a][b]){
			dist[a][b+1] = dist[a][b];
			q.push({a, b+1});
		}
	}
//	for(int i = 0; i < m; i++){
//		for(int j = 0; j < n; j++){
//			cout << dist[i][j] << ' ';
//		}
//		cout << endl;
//	}
	return dist[m-1][n-1];
}

int main(){

	cin >> m >> n;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> mat[i][j];
	cout << dijkstra() << endl;
}