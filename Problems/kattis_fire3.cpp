#include <iostream>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;

char mat[1000][1000];
int fir[1000][1000];
int joe[1000][1000];
int r, c;

int simulate(){
	// find fire and starting pos
	int a, b;
	queue<pair<int, int>> fire;
	queue<pair<int, int>> joey;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++){
			fir[i][j] = 1 << 29;
			joe[i][j] = 1 << 29;
			if(mat[i][j] == 'J'){
				a = i;
				b = j;
				joe[i][j] = 0;
			}else if(mat[i][j] == 'F'){
				fire.push({i, j});
				fir[i][j] = 0;
			}
		}
	joey.push({a, b});
	while(!fire.empty()){
		a = fire.front().first, b = fire.front().second;
		fire.pop();
		// up
		if(a-1 >= 0 && mat[a-1][b] != '#' && fir[a-1][b] > fir[a][b] + 1){
			fir[a-1][b] = min(fir[a-1][b], fir[a][b] +1);
			fire.push({a-1, b});
		}
		if(a+1 < r && mat[a+1][b] != '#' && fir[a+1][b] > fir[a][b] + 1){
			fir[a+1][b] = min(fir[a+1][b], fir[a][b] +1);
			fire.push({a+1, b});
		}
		if(b-1 >= 0 && mat[a][b-1] != '#' && fir[a][b-1] > fir[a][b] + 1){
			fir[a][b-1] = min(fir[a][b-1], fir[a][b] +1);
			fire.push({a, b-1});
		}
		if(b+1 < c && mat[a][b+1] != '#'  && fir[a][b+1] > fir[a][b] + 1){
			fir[a][b+1] = min(fir[a][b+1], fir[a][b] +1);
			fire.push({a, b+1});
		}	
	}
//	for(int i = 0; i < r; i++){
//		for(int j = 0; j < c; j++)
//			cout << fir[i][j] << ' ';
//		cout << endl;
//	}
	int m = 1 << 29;
	while(!joey.empty()){
		a = joey.front().first, b = joey.front().second;
		joey.pop();
		// up
		if(a-1 >= 0 && mat[a-1][b] != '#' && joe[a][b] + 1 < fir[a-1][b] && joe[a-1][b] > joe[a][b] + 1){
			joe[a-1][b] = joe[a][b] +1;
			joey.push({a-1, b});
		}
		if(a-1 < 0|| a+1 >= r || b-1 < 0 || b+1 >= c)
			m = min(m, joe[a][b] + 1);
		if(a+1 < r && mat[a+1][b] != '#' && joe[a][b] + 1 < fir[a+1][b] && joe[a+1][b] > joe[a][b] + 1){
			joe[a+1][b] = joe[a][b] +1;
			joey.push({a+1, b});
		}
		if(b-1 >= 0 && mat[a][b-1] != '#'  && joe[a][b] + 1 < fir[a][b-1] && joe[a][b-1] > joe[a][b] + 1){
			joe[a][b-1] = joe[a][b] +1;
			joey.push({a, b-1});
		}
		if(b+1 < c && mat[a][b+1] != '#'  && joe[a][b] + 1 < fir[a][b+1]  && joe[a][b+1] > joe[a][b] + 1){
			joe[a][b+1] = joe[a][b] +1;
			joey.push({a, b+1});
		}	
	}
//	for(int i = 0; i < r; i++){
//		for(int j = 0; j < c; j++)
//			cout << joe[i][j] << ' ';
//		cout << endl;
//	}
	return m;

}

int main(){
	cin >> r >> c;
	char tmp[c];
	for(int i = 0; i < r; i++){
		scanf("%s", tmp);
		strcpy(mat[i], tmp);
	} 
	int res = simulate();
	if(res == (1 << 29))
		cout << "IMPOSSIBLE" << endl;
	else
		cout << res << endl;
}
