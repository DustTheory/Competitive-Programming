#include <iostream>
#include <queue>
#include <utility>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int mat[1000][1000];
int n;

void display_mat(){
	system("clear");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << mat[i][j];
		}
		cout << endl;
	}
	usleep(10000);
	//cout << "\032[2J\033[1;1H";
}

void floodfill2(int x, int y){
	mat[x][y] = 1;
	display_mat();
	if(x+1<n && mat[x+1][y] == 0)
		floodfill2(x+1, y);
	if(x-1>=0 && mat[x-1][y] == 0)
		floodfill2(x-1, y);
	if(y+1<n && mat[x][y+1] == 0)
		floodfill2(x, y+1);
	if(y-1>=0 && mat[x][y-1] == 0)
		floodfill2(x, y-1);
}

void floodfill(int a, int b){
	queue<pair<int, int>> q;
	q.push({a, b});
	int step = 1;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		mat[x][y] = 1;
		q.pop();
		if(x+1<n && mat[x+1][y] == 0)
			q.push({x+1, y});
		if(x-1>=0 && mat[x-1][y] == 0)
			q.push({x-1, y});
		if(y+1<n && mat[x][y+1] == 0)
			q.push({x, y+1});
		if(y-1>=0 && mat[x][y-1] == 0)
			q.push({x, y-1});
		display_mat();
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			mat[i][j] = 0;

	floodfill2(n/2, n/2);
}
//mat[10][10]
