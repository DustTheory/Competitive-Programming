#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct P{
    long x, y;
};

int of[12][2] = { //offsets
	{0, 2018},
	{0, -2018},
	{2018, 0},
	{-2018, 0},
	{1118, 1680},
	{1118, -1680},
	{-1118, 1680},
	{-1118, -1680},
	{1680, 1118},
	{1680, -1118},
	{-1680, 1118},
	{-1680, -1118}
};

vector<P> p;

const long DIST = 2018*2018;

bool cmp(const P &a, const P &b){
	if(a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}

int main(){
    long n, x, y;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        p.push_back({x, y});
    }
	int cnt = 0;
	sort(p.begin(), p.end(), cmp);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 12; j++){
			P np = {p[i].x+of[j][0], p[i].y+of[j][1]};
			if(binary_search(p.begin(), p.end(), np, cmp))
				cnt++;
		}
	}
	cout << cnt/2 << endl;
}


