#include <iostream>
#include <queue>

using namespace std;

int mat[510][510];
int dist[510][510];
int n, m;

#define INF 1<<29

int dijkstra(){
	queue<pair<int, int>> q;
	q.push({0, 0});
	dist[0][0] = 0;
	while(!q.empty()){
		int a = q.front().first, b = q.front().second;
	//	cout << a << ' ' << b << endl;
		q.pop();
		if(a - mat[a][b] >= 0 && dist[a][b] + 1 < dist[a-mat[a][b]][b])	{
			dist[a-mat[a][b]][b] = dist[a][b] + 1;
			q.push({a-mat[a][b], b});
		}
		if(b - mat[a][b] >= 0 && dist[a][b] + 1 < dist[a][b-mat[a][b]])	{
			dist[a][b-mat[a][b]] = dist[a][b] + 1;
			q.push({a, b-mat[a][b]});
		}
		if(a + mat[a][b] < n && dist[a][b] + 1 < dist[a+mat[a][b]][b])	{
			dist[a+mat[a][b]][b] = dist[a][b] + 1;
			q.push({a+mat[a][b], b});
		}
		if(b + mat[a][b] < m && dist[a][b] + 1 < dist[a][b+mat[a][b]])	{
			dist[a][b+mat[a][b]] = dist[a][b] + 1;
			q.push({a, b+mat[a][b]});
		}
	}
	return dist[n-1][m-1];
}

int main(){
	cin >> n >> m;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++)
			mat[i][j] = s[j] - '0';
	}

	for(int i = 0; i < 510; i++)
		for(int j = 0; j < 510; j++)
			dist[i][j] = INF;

	int d = dijkstra();
	if(d == INF)
		cout << -1 << endl;
	else
		cout << d << endl;

}