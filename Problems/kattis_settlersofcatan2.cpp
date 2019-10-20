#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

enum{
	NE = 0,
	N,
	NW,
	SW,
	S,
	SE,
	NUM_DIRS
};

struct Vec2{
	int x, y;
	bool operator<(const Vec2 &v) const{
		if(y == v.y)
			return x < v.x;
		return y < v.y;
	}
};

vector<Vec2> path;

int dirmat_e[6][2] = {
	{-1, 1},
	{-1, 0},
	{-1, -1},
	{0, -1},
	{1, 0},
	{0, 1}
};

int dirmat_o[6][2] = {
	{0, 1},
	{-1, 0},
	{0, -1},
	{1, -1},
	{1, 0},
	{1, 1}
};

void set_neighbour_coords(int dir, int &a, int &b){
	if(b == 0 || b % 2 == 0){
		a += dirmat_e[dir][0];
		b += dirmat_e[dir][1];
	}else{
		a += dirmat_o[dir][0];
		b += dirmat_o[dir][1];
	}
}

Vec2 get_neighbour_coords(int dir, int a, int b){
	if(b == 0 || b % 2 == 0){
		return {a + dirmat_e[dir][0], b + dirmat_e[dir][1]};
	}else{
		return {a + dirmat_o[dir][0], b + dirmat_o[dir][1]};
	}
}

void generate_path(){
	path.clear();
	int a = 100, b = 100;
	int ring = 1;
	int step = 1;

	path.push_back({a, b});

	// once NE
	set_neighbour_coords(NE, a, b);
	path.push_back({a, b}), step++;
	
	while(step < 10010){

		// ring*NW
		for(int i = 0; i < ring; i++)
			set_neighbour_coords(NW, a, b), path.push_back({a, b}), step++;

		// ring*SW
		for(int i = 0; i < ring; i++)
			set_neighbour_coords(SW, a, b), path.push_back({a, b}), step++;

		// ring*S
		for(int i = 0; i < ring; i++)
			set_neighbour_coords(S, a, b), path.push_back({a, b}), step++;

		// ring*SE
		for(int i = 0; i < ring; i++)
			set_neighbour_coords(SE, a, b), path.push_back({a, b}), step++;
		
		// ring*NE
		for(int i = 0; i < ring+1; i++)
			set_neighbour_coords(NE, a, b), path.push_back({a, b}), step++;
		
		// ring*N
		for(int i = 0; i < ring; i++){
			set_neighbour_coords(N, a, b);
			path.push_back({a, b}), step++;
		}
		ring++;
	}

}

int mat[20000][20000];

bool ok_with_neighbours(int a, int b, int x){
	for(int dir = 0; dir < NUM_DIRS; dir++){
		Vec2 n = get_neighbour_coords(dir, a, b);
		if(mat[n.x][n.y] == x && mat[n.x][n.y] != 0)
			return false;
	}
	return true;
}

set<Vec2> times;

bool numerate_path(int p){
	if(p >= 10010)
		return true;
	//cout << "p: " << p << endl;
	int a = path[p].x, b = path[p].y; 
	for(set<Vec2>::iterator it = times.begin(); it != times.end(); it++){
		int x = it->x, y = it->y;
		if(ok_with_neighbours(a, b, x)){
			mat[a][b] = x;
			times.erase(it);
			times.insert({x, y+1});
			if(!numerate_path(p+1)){
				auto it2 = times.find({x, y+1});
				mat[a][b] = 0;	
				times.erase(it2);
				times.insert({x, y});
			}else{
				return true;
			}
		}
	}
	return false;	
}

void numerate_path2(){
	int times2[6] = {0};
	times2[0] = 1<<29;
	bool used[6] = {0};
	for(auto p : path){
		for(int i = 1; i <=5; i++)
			used[i] = false;
		for(int i = 0; i < NUM_DIRS; i++){
			Vec2 n = get_neighbour_coords(i, p.x, p.y);
			used[mat[n.x][n.y]] = 1;
		}
		int mini = 1<<28;
		for(int i = 1; i <= 5; i++){
			if(!used[i])
				mini = min(mini, times2[i]);
		}
		bool found = false;
		for(int i = 1; i <= 5; i++){
			if(times2[i] == mini && !used[i]){
				mat[p.x][p.y] = i;
				times2[i]++;
				found = true;
			   break;	
			}
		}
	}
}

int main(){
	times.insert({1, 0});
	times.insert({2, 0});
	times.insert({3, 0});
	times.insert({4, 0});
	times.insert({5, 0});

	generate_path();

	numerate_path2();

//	for(int i = 0; i < 15; i++){
//		cout << path[i].x-100 << ' ' << path[i].y-100 << endl;
//	}

//	for(int i = 0; i < 10; i++){
//		cout << mat[path[i].x][path[i].y] << endl;
//	}

	/*
	int mina = 1<<29, maxa=0, minb = 1 << 29, maxb = 0;
	for(auto p : path){
		mina = min(mina, p.x);
		minb = min(minb, p.y);
		maxa = max(maxa, p.x);
		maxb = max(maxb, p.y);	
	}	
	cout << mina << ' ' << maxa << ' ' << minb << ' ' << maxb << endl;
	*/
	int c, n;
	cin >> c;
	while(c--){
		cin >> n;
		cout << mat[path[n-1].x][path[n-1].y] << endl;
	}

//	int i = 1;
//	for(auto p : path){
//		if(mat[p.x][p.y] != 0 && !ok_with_neighbours(p.x, p.y, mat[p.x][p.y]))
//			cout << "CRAP " << i << endl;
//		i++;
//	}	

	//for(set<Vec2>::iterator it = times.begin(); it != times.end(); it++){
	//	cout << it->x << ' ' << it->y << endl;
	//}
}
