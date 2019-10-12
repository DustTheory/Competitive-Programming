#include <unistd.h>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int dirs[4][2] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

struct Edge{
	int f, t, d;
};

int r, c;
int mat[20][20];
int dists[500];
list<Edge> edgelist;

bool valid(int x, int y){
	return x >= 0 && y >= 0  && x < r && y < c;
}

int to_flat(int x, int y){
	return x*c+y;
}

#define INF 1<<29

bool bellman_ford(int start, int end){
	for(int i = 0; i < r*c+10; i++)
		dists[i] = INF;
	dists[start] = 0;

	for(int phase = 0; phase < 6; phase++){
		cout << "PHASE: " << phase << endl;
		cout << dists[end] << endl;
		for(int i = 0; i < r*c; i++){
			cout << dists[i] << ' ';
			if((i+1) % c == 0)
				cout << endl;
		}
		cout << dists[start] << endl;
		if(phase != 5)
			cout << "\033[2J\033[1;1H";
		usleep(1000000);		
		bool found_shortcut = false;
		for(Edge &edge : edgelist){
//			if(dists[edge.f] != INF && dists[edge.f]+edge.d < dists[edge.t]){
				dists[edge.t] = max(0, min(dists[edge.t], dists[edge.f]+edge.d));
				found_shortcut = true;
//			}
		}
		cout << found_shortcut << endl;
	//	if(!found_shortcut)
	//		break;
	}	


	for(Edge &edge : edgelist){
		if(dists[edge.f] != INF && dists[edge.f]+edge.d < dists[edge.t]){
			dists[edge.t] = dists[edge.f]+edge.d;
			cout << "FOUND NEGATIVE CYCLE NODE ";
			cout << dists[edge.t] << ' ' << edge.f << ' ' << edge.t << endl;
		}
	}

	cout << dists[end] << endl;
	for(int i = 0; i < r*c; i++){
		cout << dists[i] << ' ';
		if((i+1) % c == 0)
			cout << endl;
	}
	cout << dists[start] << endl;

	return dists[end];
}

int main(){
	char dump;
	cin >> r >> c;

	for(int i = 0; i < c; i++)
		cin >> dump;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			cin >> mat[i][j];
	for(int i = 0; i < c; i++)
		cin >> dump;

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			for(int k = 0; k < 4; k++){
				int x = i+dirs[k][0], y = j+dirs[k][1];	
				if(valid(x, y)){
					edgelist.push_back({to_flat(x, y), to_flat(i, j), mat[x][y]});			
				}	
			}
		}
	}

	int start_v = r*c;
	int end_v = r*c+1;	
	for(int i = 0; i < c; i++)
		edgelist.push_back({start_v, to_flat(r-1, i), mat[r-1][i]});

	for(int i = 0; i < c; i++)
		edgelist.push_back({to_flat(0, i), end_v, 0});

//	for(Edge &edge : edgelist)
//		cout << edge.f << ' ' << edge.t << ' ' << edge.d << endl;

	cout << bellman_ford(start_v, end_v) << endl;
}
