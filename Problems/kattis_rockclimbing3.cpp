#include <iostream>
#include <queue>

using namespace std;

int r, c;
int mat[20][20];
int dists[20][20];
bool isfinish[20][20];
int dirs[4][2] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};
struct Vec3{
	int x, y, z;
	bool operator<(const Vec3 &a) const{
		return z < a.z;
	}
};

bool valid(int x, int y){
	return x >=0 && y >= 0 && x < r && y < c;
}

int main(){
	scanf("%d %d", &r, &c);
	for(int i = 0; i < c; i++){
		char dump; cin >> dump;
		mat[0][i] = 0;
		isfinish[0][i] = true;
	}
	for(int i = 1; i <= r; i++)
		for(int j = 0; j < c; j++)
			cin >>  mat[i][j];	
	for(int i = 0; i < c; i++){
		char dump; cin >> dump;
		mat[r+1][i] = 0;
	}
	r+=2;
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(j+1 < c && mat[i][j] + mat[i][j+1] < 0){
				isfinish[i][j+1] = isfinish[i][j] = true;
			}
			if(i+1 < r && mat[i][j] + mat[i+1][j] < 0){
				isfinish[i+1][j] = isfinish[i][j] = true;
			}
		}
	} 	
	

	priority_queue<Vec3> q;

	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++)
			dists[i][j] = 1<<29;
	
	for(int i = 0; i < c; i++){
		q.push({r-1, i, 0});
		dists[r-1][i] = 0;
	}


	while(!q.empty()){
		int x = q.top().x, y = q.top().y, z = q.top().z;
		q.pop();
			for(int i = 0; i < 4; i++){
				int x1 = x+dirs[i][0], y1 = y+dirs[i][1];
				if(valid(x1, y1)){
					if(z + mat[x1][y1] < dists[x1][y1]){
						dists[x1][y1] = isfinish[x1][y1] ? z + max(0, mat[x1][y1]): z + mat[x1][y1];
						if(!isfinish[x1][y1])
							q.push({x1, y1, dists[x1][y1]});
					}	
			}
		}
	}

	int mini = 1 << 29;

///	cout << r << ' ' << c << endl;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
		//	cout << dists[i][j] << (j == c-1 ? "\n" : " ");
			if(isfinish[i][j])
				mini = min(mini, dists[i][j]);
		}
	}

	cout << mini << endl;

}
