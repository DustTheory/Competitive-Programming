#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Vec2{
	int x, y;
};
int offset = 100;
vector<Vec2> rez;
vector<vector<bool>> mem;

bool valid(Vec2 &v){
	int g = __gcd(v.x, v.y);
	while(abs(g) != 1){
		v.x/=g;
		v.y/=g;
		g = __gcd(v.x, v.y);
	}
	if(v.y < 0)
		v.y *= -1, v.x *=-1;
	cout << v.x << ' ' << v.y << endl;
	return !mem[offset+v.x][v.y];
}

Vec2 skrati(Vec2 v){
	return v;
}

int main(){
//	cout << __gcd(7, 1) << endl;
	int krug=1, curr=0, x = 0, y = 0;
	int dir = 1;
	vector<int> queries;
	int n;
//	while(cin >> n)
//		if(n == -1)
//			break;
//		else
//			queries.push_back(n);
//	int najv = *max_element(queries.begin(), queries.end()) + 10;
int najv = 100;
	for(int i = 0; i <=najv; i++){
		mem.push_back(vector<bool>());
		for(int j = 0; j <=najv; j++){
			mem[i].push_back(0);
		}
	}
	while(1){
		bool quit = false;
		for(int i = 0; i < krug; i++){
			y+=dir;
			Vec2 v = {y, x};
			if(valid(v)){
				mem[offset+v.x][v.y] = true;
				rez.push_back(v);
			}
			curr++;
			if(rez.size() >= najv){
				quit = true;
				break;
			}
		}
		for(int i = 0; i < krug; i++){
			x+=dir;
			Vec2 v = {y, x};
			if(valid(v)){
				mem[offset+v.x][v.y] = true;
				rez.push_back(v);
			}
			curr++;
			if(rez.size() >= najv){
				quit = true;
				break;
			}
		}
		if(quit)
			break;
		dir*=-1;
		krug++;
	}
	for(Vec2 v : rez)
		cout << v.x << " / " << v.y << endl;
	for(int q : queries)
		cout << rez[q].x << " / " << rez[q].y << endl;
}
