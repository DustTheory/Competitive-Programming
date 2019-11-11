#include <iostream>
#include <vector>

using namespace std;

struct Vec2{
	int x, y;
};

Vec2 arr[2000];

#define INF 999999
#define EPS 1e-3

struct grad{
	Vec2 s;
	double g;
	int cnt;
	grad(Vec2 a, Vec2 b){
		s.x = a.x, s.y = a.y;
		cnt = 2;
		Vec2 c = {b.x-a.x, b.y-a.y};
		if(c.x == 0)
			g = INF;
		else if(c.y == 0)
			g = 0;
		else
			g = (double)c.y/(double)c.x;
	}
	bool matches(Vec2 a){
		Vec2 c = {s.x-a.x, s.y-a.y};
		double g2;
		if(c.x == 0)
			g2 = INF;
		else if(c.y == 0)
			g2 = 0;
		else
			g2 = (double)c.y/(double)c.x;
		return abs(g2-g) <= EPS;
	}
};

vector<grad> G;

int main(){
	while(1){
	int n, x, y;
	cin >> n;
	if(n == 0)
		break;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		arr[i] = {x, y};
	}
	
	if(n < 3){
		cout << n << endl;
	   	continue;	
	}
	G.clear();
	G.push_back(grad(arr[0], arr[1]));	
	for(int i = 2; i < n; i++){
		int mj = G.size();
		for(int j = 0; j < mj; j++){
			if(G[j].matches(arr[i])){
				G[j].cnt++;	
			}else{
				G.push_back(grad(G[j].s, arr[i]));	
			}
		}
	}
	int maxcnt = 0;
	for(grad &g : G)
		if(g.cnt > maxcnt)
			maxcnt = g.cnt;
	cout << maxcnt << endl;
	}
}
