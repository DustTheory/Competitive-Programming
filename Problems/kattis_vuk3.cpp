#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

char mat[510][510];
int dists[510][510];

struct idfk{
	int x, y, d;
	const bool operator<(const idfk &a) const{
		return this->d < a.d;
	}
};

int mem[510][510];
bool visited[510][510];

int dirs[4][2] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

	int n, m;
bool valid(int x, int y){
	return x >= 0 && y >= 0 && x < n && y < m;
}

int bfs(idfk start, idfk end){
	priority_queue<idfk> q;	
	q.push(start);
	for(int i = 0; i < 510; i++)
		for(int j = 0; j < 510; j++){
			mem[i][j] = -1;
		}
	mem[start.x][start.y] = dists[start.x][start.y];
	visited[start.x][start.y] = true;
	while(!q.empty()){
		idfk tmp = q.top();	
		q.pop();
		int x, y;
		for(int i = 0; i < 4; i++){
			x = tmp.x+dirs[i][0];
			y = tmp.y+dirs[i][1];
			if(valid(x, y) && !visited[x][y] && min(mem[tmp.x][tmp.y], dists[x][y]) > mem[x][y]){
				mem[x][y] = min(mem[tmp.x][tmp.y], dists[x][y]) ;
				q.push({x, y, mem[x][y]});
			}	
		}
		visited[x][y] = true;
	}
	return mem[end.x][end.y];
}

struct Tree{
	int x, y;
};


int main(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
		scanf("%s", mat[i]);

	idfk start, end;	

	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++){
			dists[i][j] = -1;
		} 

	queue<idfk> q;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(mat[i][j] == '+')
				q.push({i, j}), dists[i][j] = 0;
			else if(mat[i][j] == 'V')
				start.x = i, start.y = j;
			else if(mat[i][j] == 'J')
				end.x = i, end.y = j;


	while(!q.empty()){
		int a = q.front().x;
		int b = q.front().y;
		int c = q.front().d;
		q.pop();
		for(int i = 0; i < 4; i++){
			int a1 = a+dirs[i][0];
			int b1 = b+dirs[i][1];
			int c1 = c+1;
			if(valid(a1, b1) && dists[a1][b1] == -1){
				dists[a1][b1] = c1;
				q.push({a1, b1, c1});
			}
		}
	}


//	cout << "STARTING TREE SHIT" << endl;

	//for(int i = 0; i < n; i++)
	//	for(int j = 0; j < m; j++){
	//		dists[i][j] = 1 << 29;
	//		for(auto tree : trees)
	//			dists[i][j] = min(dists[i][j], abs(i - tree.x) + abs(j-tree.y));
//		}
//	cout << "FINISHED TREE SHIT" << endl;
/*	
	for(int i = start.x-10; i < start.x + 10; i++){
		for(int j = start.y-10; j < start.y+10; j++){
			cout << dists[i][j] << ' ';
		}
		cout << endl;
	}
*/
//	cout << dists[start.x][start.y] << endl;
	cout << bfs(start, end) << endl;		
	
}
