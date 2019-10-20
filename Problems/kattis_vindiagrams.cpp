#include <queue>
#include <iostream>
#include <unistd.h>

using namespace std;

int n, m;
char mat[110][110];
char mat2[110][110];
bool visited[110][110];

int dirs[4][2] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

bool valid(int a, int b){
	return a >= 0 && b >= 0 && a < n && b < m;
}

bool is_intersection(int a, int b){
	for(int dir = 0; dir < 4; dir++){
		int x1 = a+dirs[dir][0];
		int y1 = b+dirs[dir][1];
		if(!valid(x1, y1) || mat[x1][y1] == '.')
			return false;
	}
	return true;
}

void log_mat(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << mat2[i][j] << ' ';
		cout << endl;
	}
	usleep(1000000);
} 
void color(char c, int a, int b){
	int x = a, y = b;
	int last_dir = 0;
	while(1){
		visited[x][y] = true;
		if(is_intersection(x, y)){
			mat2[x][y] = '+';
			x+=dirs[last_dir][0],
			y+=dirs[last_dir][1];
		}else{
		mat2[x][y] = c;
		bool change = false;
		for(int dir = 0; dir < 4; dir++){
			int x1 = x+dirs[dir][0];
			int y1 = y+dirs[dir][1];
			if(valid(x1, y1) && !visited[x1][y1] && mat[x1][y1] != '.' && mat[x1][y1] != (c == 'A'? 'B' : 'A')){
				x=x1, y=y1, change = true;
				last_dir = dir;
				break;
			}
		}
		if(!change)
			break;
		}
	}	
}

struct Vec2{
	int x, y;
};

int flood_fill(int a, int b){
	queue<Vec2> q;
	q.push({a, b});
	int cnt = 0;
	visited[a][b] = true;
	while(!q.empty()){
		cnt++;
		int x = q.front().x, y = q.front().y;
		q.pop();
		for(int dir = 0; dir < 4; dir++){
			int x1 = x+dirs[dir][0];
			int y1 = y+dirs[dir][1];
			if(valid(x1, y1) && !visited[x1][y1] && mat[x1][y1] == '.'){
				q.push({x1, y1});	
				visited[x1][y1] = true;
			}		
		}
	}
	return cnt;
}

Vec2 is_corner(int a, int b){
	int x = 0, y = 0;
	if(mat[a][b] == '.')
		return {-1, -1}; //errcode not corner
	if(valid(a+1, b) && mat[a+1][b] == 'X')
		x=1;
	else if(valid(a-1, b) && mat[a-1][b] == 'X')
		x=-1;
	if(valid(a, b+1) && mat[a][b+1] == 'X')
		y=1;
	else if(valid(a, b-1) && mat[a][b-1] == 'X')
		y=-1;
	if(x == 0 || y == 0)
		return {-1, -1}; //errcode not corner
	return {a+x, b+y};
}

void flood_fill2(int a, int b, char c){
	queue<Vec2> q;
	q.push({a, b});
	if(mat2[a][b] == 'a' || mat2[a][b] == 'b'){
		if(mat2[a][b] != c)
			mat2[a][b] = 'c';
	}else
		mat2[a][b] = c;
	while(!q.empty()){
		int x = q.front().x, y = q.front().y;
		q.pop();
		for(int dir = 0; dir < 4; dir++){
			int x1 = x+dirs[dir][0];
			int y1 = y+dirs[dir][1];
			if(valid(x1, y1) && !visited[x1][y1]){
				if(mat2[x1][y1] == '.'){
					q.push({x1, y1});	
					mat2[x1][y1] = c;
				}else if(mat2[x1][y1] != c && (mat2[x1][y1] == 'a' || mat2[x1][y1] == 'b')){
					q.push({x1, y1});	
					mat2[x1][y1] = 'c';
				}
			}		
		}
	}	
}

void label_areas(){
	for(int i = 0; i < n; i++){
		if(mat2[i][0] == '.')
			flood_fill2(i, 0, 'o');
		if(mat2[i][m-1] == '.')
			flood_fill2(i, m-1, 'o');
	}
	for(int i = 0; i < m; i++){
		if(mat2[0][i] == '.')
			flood_fill2(0, i, 'o');
		if(mat2[n-1][i] == '.')
			flood_fill2(n-1, i, 'o');
	}
	log_mat();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			Vec2 c = is_corner(i, j);
			if(c.x == -1) // errcode not corner
				continue;
			if(is_intersection(i, j))
				continue; //  deal with this l8r
			char ch = mat2[i][j] == 'A' ? 'a' : 'b';
			if(mat2[c.x][c.y] != 'o')
				flood_fill2(c.x, c.y, ch);
		}
		cout << endl;
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		scanf("%s", mat[i]);
	int ai, aj, bi, bj;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			mat2[i][j] = mat[i][j];
			if(mat[i][j] == 'A')
				ai = i, aj = j;
			else if(mat[i][j] == 'B')
				bi = i, bj = j;
		}
	color('A', ai, aj);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) visited[i][j] = false;
	color('B', bi, bj);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) visited[i][j] = false;
	color('B', bi, bj);
	label_areas();
	log_mat();
	int a_area = 0, b_area = 0, ab_area = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] == '.'){
				if(mat2[i][j] == 'a')
					a_area++;
				else if(mat2[i][j] == 'b')
					b_area++;
				else if(mat2[i][j] == '.' || mat2[i][j] == 'c')
					ab_area++;
			}
		}
	}
	cout << a_area << ' ' << b_area << ' ' << ab_area << endl;
}
