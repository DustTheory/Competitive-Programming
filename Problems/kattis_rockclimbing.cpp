#include <iostream>
#include <queue>

using namespace std;

int r, c;
int mat[20][20];

int dirs[4][2] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

bool visited[20][20];

bool valid(int x, int y){
	return x > 0 && y > 0 && x < r && y < c && !visited[x][y];
}

#define INF 1<<29

struct Vec2{
	int x, y;
};

bool _dfs(int x, int y, int energy){
	if(r == 0)
		return true;	
	cout << x << ' ' << y  << ' ' << energy << ' ' << mat[x][y] << endl;
	// if in negative and it's possible to loop you win
	if(mat[x][y] < 0){
		for(int i = 0; i < 4; i++){
			int x1 = x+dirs[i][0], y1 = y+dirs[i][1];
			if(valid(x1, y1)){
				if(mat[x1][y1]+mat[x][y] < 0)
					return true;
			}
		}
	}
/*
	// if in 0, search for negative or for goal
	if(mat[x][y] == 0){
		// flood fill bfs
		queue<Vec2> q;
		q.push({x, y});
		while(!q.empty()){
			int x2 = q.front().x, y2 = q.front().y;
			q.pop();
			mat[x2][y2] = INF;
			for(int i = 0; i < 4; i++){
				int x1 = x2+dirs[i][0], y1 = y2+dirs[i][1];
				if(valid(x1, y1)){
					if(mat[x1][y1] == 0)
						q.push({x1, y1});
					else if(energy-mat[x1][y1] >= 0){
						visited[x1][y1] = true;
						if(_dfs(x1, y1, energy-mat[x1][y1]))
							return true;
						visited[x1][y1] = false;
					}
				}
			}
		}
	}
*/

	for(int i = 0; i < 4; i++){
		int x1 = x+dirs[i][0], y1 = y+dirs[i][1];
		if(valid(x1, y1) && energy-mat[x1][y1]>=0){
			visited[x1][y1] = true;
			if(_dfs(x1, y1, energy-mat[x1][y1]))
				return true;
			visited[x1][y1] = false;
		}
		
	}

	return false;	
}

bool dfs(int e){
	for(int i = 0; i < c; i++)	
		if(e-mat[r-1][i] >= 0){
			visited[r-1][i] = true;
			if(_dfs(r-1, i, e))
				return true;
			visited[r-1][i] = false;	
		}
	return false;
}


/*
int bfs(){
	priority_queue<Vec3> q;
	
	for(int i = 0; i < 16; i++)
		for(int j = 0; j < 16; j++)
			mem[i][j] = i == 0 ? 0 : INF;

	for(int i = 0; i < c; i++)
		q.push({r-1, i, 0});

	while(!q.empty()){
		int x = q.top().x, y = q.top().y, z = q.top().z;	
		q.pop();
		for(int i = 0; i < 4; i++){
			int x1 = x+dirs[i][0], y1 = y+dirs[i][1];
			if(!valid(x1, y1))
				continue;
			int z1 = mat[x1][y1];
			if(z1+z < mem[x1][y1])
				q.push({x1, y1, z1+z}), mem[x1][y1] = z1+z;
		}	
	}

	int mini = 1<<29;
	for(int i = 0; i < c; i++)
		mini = min(mem[0][i], mini);

	return mini;
}
*/
int main(){
	int x;
	char dump;

	cin >> r >> c;

	for(int i = 0; i < c; i++)
		cin >> dump;

	for(int i = 1; i <= r; i++)
		for(int j = 0; j < c; j++)
				scanf("%d", &mat[i][j]);

	for(int i = 0; i < c; i++)
		cin >> dump;
	
	r+=2;
	for(int i = 4999; i < 5000; i++){
		cout << i << endl;
		if(dfs(i)){
			cout << i << endl; 
			break;
		}
	}

}
