#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Vec2{
	int x, y;
};

Vec2 arr[1010];

#define INF 99999
#define EPS 1e-9

inline double grad(Vec2 &a, Vec2 &b){
	int dx = a.x-b.x, dy = a.y-b.y;
	if(dx == 0)
		return INF;
	if(dy == 0)
		return 0;
	return (double)dy/(double)dx;
}

int max_doop(vector<double> &grads){
		sort(grads.begin(), grads.end());
		double last = grads[0], curr_d = 1, max_d = 1;
		for(int i = 1; i < grads.size(); i++){
			if(abs(grads[i] - last) < EPS){
				curr_d++;
			}else{
				max_d = max(max_d, curr_d);
				last = grads[i];
				curr_d = 1;
			}	
		}
		max_d = max(max_d, curr_d);
		return max_d;
}

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

		int max_d = 0;

		for(int i = 0; i < n; i++){
			vector<double> grads;
			for(int j = 0; j < n; j++)
				if(i != j)
					grads.push_back(grad(arr[i], arr[j]));
			max_d = max(max_d, max_doop(grads));
		}
		cout << max_d+1 << endl;
	}
}
