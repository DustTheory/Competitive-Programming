#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define WALL 1<<19
#define UNVISITED 1<<20
#define FIRE 1<<18
#define INF 1<<29

int w, h, starta, startb;
int mat[1010][1010];

int dist[1010][1010];
int fire[1010][1010];

void reset(){
	for(int i = 0; i < 1010; i++){
		for(int j = 0 ; j < 1010; j++){
			dist[i][j] = INF;
			fire[i][j] = INF;
			mat[i][j] = 0;
		}
	}
}

void dijkstra(){
	queue<pair<int, int>> q;
	q.push({starta, startb});
	dist[starta][startb] = 0;
	vector<pair<int, int>> exits;
	while(!q.empty()){
		int a = q.front().first, b = q.front().second;	
		if(a  == 0 || b == 0 || a == h+1 || b == w+1)
			exits.push_back({a, b});
	//		q.pop();
	//	}else{
			q.pop();
			if(a > 0 && dist[a][b] + 1 < dist[a-1][b] && mat[a-1][b] != FIRE && mat[a-1][b] != WALL){
				dist[a-1][b] = dist[a][b] + 1;
				q.push({a-1, b});
			}
			if(b > 0 && dist[a][b] + 1 < dist[a][b-1]&& mat[a][b-1] != FIRE && mat[a][b-1] != WALL)	{
				dist[a][b-1] = dist[a][b] + 1;
				q.push({a, b-1});
			}
			if(a + 1 <= h + 1 && dist[a][b] + 1 < dist[a+1][b] && mat[a+1][b] != FIRE && mat[a+1][b] != WALL)	{
				dist[a+1][b] = dist[a][b] + 1;
				q.push({a+1, b});
			}
			if(b + 1 <= w + 1 && dist[a][b] + 1 < dist[a][b+1] && mat[a][b+1] != FIRE && mat[a][b+1] != WALL)	{
				dist[a][b+1] = dist[a][b] + 1;
				q.push({a, b+1});
			}
	//	}
	}

	queue<pair<int, int>> stek;
	for(int i = 0; i <= h; i++){
		for(int j = 0; j <= w; j++){
			if(mat[i][j] == FIRE){
				fire[i][j] = 0;
				stek.push({i, j});
			}
		}
	}
	while(!stek.empty()){
		int a = stek.front().first, b = stek.front().second;	
		stek.pop();
		if(a > 0 && fire[a][b] + 1 < fire[a-1][b] && mat[a-1][b] != WALL){
			fire[a-1][b] = fire[a][b] + 1;
			stek.push({a-1, b});
		}
		if(b > 0 && fire[a][b] + 1 < fire[a][b-1] && mat[a][b-1] != WALL)	{
			fire[a][b-1] = fire[a][b] + 1;
			stek.push({a, b-1});
		}
		if(a + 1 <= h + 1 && fire[a][b] + 1 < fire[a+1][b] && mat[a+1][b] != WALL)	{
			fire[a+1][b] = fire[a][b] + 1;
			stek.push({a+1, b});
		}
		if(b + 1 <= w + 1 && fire[a][b] + 1 < fire[a][b+1] && mat[a][b+1] != WALL)	{
			fire[a][b+1] = fire[a][b] + 1;
			stek.push({a, b+1});
		}
	}
	
	int mini = 99999999;
	for(int i = 0; i < exits.size(); i++)
		if(dist[exits[i].first][exits[i].second] < fire[exits[i].first][exits[i].second])
			mini = min(mini, dist[exits[i].first][exits[i].second]);

	if(mini != 99999999)
		cout << mini << endl;
	else
		cout << "IMPOSSIBLE" << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		reset();
		cin >> w >> h;
		char c;
		string s;
		for(int i = 1; i <= h; i++){
			cin >> s;
			for(int j = 1; j <= w; j++){
				c = s[j-1];
				if(c == '.')
					mat[i][j] = UNVISITED;
				if(c == '#')
					mat[i][j] = WALL;
				if(c == '@'){
					mat[i][j] = 0;
					starta = i;
					startb = j;
				}
				if(c == '*')
					mat[i][j] = FIRE;
			}
		}
		dijkstra();
	}
}