#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Vec2{
	int x, y;
};

bool equal(Vec2 &a, Vec2 &b){
	return a.x == b.x && a.y == b.y;
}

vector<vector<Vec2>> P;
map<int, vector<vector<Vec2>>*> mapa;
vector<Vec2> pts;

#define EPS 0.1

bool colinear(int p, Vec2 v){
	if(P[p].size() == 0)
		return false;
	Vec2 a = P[p][0];
	Vec2 b = P[p][1];
	if(equal(v, a) || equal(v, b))
		return false;
	Vec2 c = {b.x-a.x, b.y-a.y};
	Vec2 d = {v.x-a.x, v.y-a.y};
	if(c.x == 0)
		return c.y == d.y;
	if(c.y == 0)
		return c.x == d.x;
	double k1 = (double)c.y/(double)c.x;
	double k2 = (double)v.y/(double)v.x;
	return abs(k2-k1) <= EPS;
}

int main(){
	int n, x, y;
	while(1){
	pts.clear();
	P.clear();
	cin >> n;
	if(n == 0)
		break;
	for(int i = 0; i < n; i++)
		cin >> x >> y, pts.push_back({x, y});

	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			P.push_back(vector<Vec2>{pts[i], pts[j]});
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < P.size(); j++)
			if(colinear(j, pts[i]))
				P[j].push_back(pts[i]);
	}

	int mx = 0, mxi;

	for(int i = 0; i < P.size(); i++)
		if(P[i].size() > mx)
			mx = P[i].size(), mxi = i;

	if(n < 3)
		cout << n << endl;
	else
		cout << mx << endl;

	}
}
