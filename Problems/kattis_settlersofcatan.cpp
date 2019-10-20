#include <iostream>
#include <set>
#include <vector>
using namespace std;

int board[10010][10010];

struct Vec2{
	int x, y;
	bool operator<(const Vec2 &v) const{
		if(y == v.y)
			return x < v.x;
		return y < v.y;
	}
};

set<Vec2> times;

int at_coords(int x, int y){
	x+=5000;
	y+=5000;
	if(y % 2 == 0)
		x++;
	return board[x][y];
}

bool ok_with_neighbours(int a, int b, int x){
	if(at_coords(a, b+1) == x)
		return false;
	if(at_coords(a, b-1) == x)
		return false;
	if(at_coords(a-1, b-1) == x)
		return false;
	if(at_coords(a-1, b) == x)
		return false;
	if(at_coords(a+1, b-1) == x)
		return false;
	if(at_coords(a+1, b) == x)
		return false;
	return true;
}

void set_at_coords(int a, int b, int x){
	a += 5000;
	b += 5000;
	if(a % 2 == 0)
		b++;
	board[a][b] = x;
}

void generate_board(){
	int ca = 0, cb = 0;
	int ring = 1;
	vector<Vec2> ringpath;
	for(int i = 0; i <= 10; i++){
		// once right
		ca = ca, cb = cb+1;
		ringpath.push_back({ca, cb});
		//up and left
		for(int j = 0; j < ring; j++){
			ca--;
			cb--;
			if(abs(ca) % 2 != 0 && ca != 0)
				cb++;
			else
				cb--;
			ringpath.push_back({ca, cb});
		}

		//left
		for(int j = 0; j < ring; j++){
			cb--;
			if(abs(ca) % 2 != 0 && ca != 0)
				cb++;
			else
				cb--;
			ringpath.push_back({ca, cb});
		}
		
		//down and left

		for(int j = 0; j < ring; j++){
			ca++;
			cb--;
			if(abs(ca) % 2 != 0 && ca != 0)
				cb++;
			else
				cb--;
			ringpath.push_back({ca, cb});
		}

		// down and right

		for(int j = 0; j < ring; j++){
			cout << "DR " << ca <<  ' ' << cb << ' ';
			ca++;
			cb++;
			if(abs(ca) % 2 != 0 && ca != 0)
				cb++;
			else
				cb--;
			cout << ca << ' ' << cb << endl;
			ringpath.push_back({ca, cb});
		}

		// right
		
		for(int j = 0; j < ring; j++){
			cb++;
			if(abs(ca) % 2 != 0 && ca != 0)
				cb++;
			else
				cb--;
			ringpath.push_back({ca, cb});
		}


		// up and right
		
		for(int j = 0; j < ring; j++){
			ca--;
			cb++;
			if(abs(ca) % 2 != 0 && ca != 0)
				cb++;
			else
				cb--;
			ringpath.push_back({ca, cb});	
		}
		ring++;
	}
	for(int i = 0; i < 20; i++){
		cout << ringpath[i].x << ' ' << ringpath[i].y << endl;
	}
}

		/*
		for(auto c : ringpath){
			a = c.x, b = c.y;
			for(set<Vec2>::iterator it = times.begin(); it != times.end(); it++){
				if(ok_with_neighbours(a, b, it->x)){
					int x = it->x, y = it->y;
					times.erase(it);
					times.insert({x, y});
					set_at_coords(x, y, it->x);
				}
			}
   			if(!ok){
				cout << "FUUUCK "  <<  i << endl;
				return ;
			}	
		}*/
int main(){
	generate_board();
}
