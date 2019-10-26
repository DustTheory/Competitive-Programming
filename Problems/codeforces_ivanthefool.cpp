#include <iostream>

using namespace std;

long long mem[100010][2];

const long long TOMOD = 1000000007;

long long solve(long long x, int last){
	long long res = 0;
	if(x < 0)
		return 0;
	if(x == 0)
		return 1;
	
	if(last != -1 && mem[x][last] != 0)
		return mem[x][last];
	if(last == 0){
		res = ((res % TOMOD) + (solve(x-1, 1) % TOMOD) ) % TOMOD;//01
		res = ((res % TOMOD) + (solve(x-2, 1) % TOMOD) ) % TOMOD;//011
	}else if(last == 1){
		res = ((res % TOMOD) + (solve(x-1, 0) % TOMOD) ) % TOMOD;
		res = ((res % TOMOD) + (solve(x-2, 0) % TOMOD) ) % TOMOD;
	}else if(last == -1){
		res = ((res % TOMOD) + (solve(x-1, 0) % TOMOD) ) % TOMOD;
		res = ((res % TOMOD) + (solve(x-1, 1) % TOMOD) ) % TOMOD;
		res = ((res % TOMOD) + (solve(x-2, 0) % TOMOD) ) % TOMOD;
		res = ((res % TOMOD) + (solve(x-2, 1) % TOMOD) ) % TOMOD;
	}
	mem[x][last] = res;
	return res;
}

int main(){
	long long n, m;
	cin >> n >> m;
	long long a = solve(max(n, m), -1);
	for(int i = 0; i <= 100010; i++)
		mem[i][0] = mem[i][1] = 0;
	long long b = solve(min(n, m), -1) - 2;
	cout << ((a % TOMOD) + (b%TOMOD))%TOMOD << endl;
}
