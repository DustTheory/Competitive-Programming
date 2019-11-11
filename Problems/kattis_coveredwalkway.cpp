#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

vector<ull> C;
ull c;

ull dp(int a, int b){
	if(b == C.size()-1)
		return c + (C[b] - C[a])*(C[b] - C[a]);

	//keep moving
	ull mini = dp(a, b+1);
	
	//stop here and start new
	mini = min(mini, (c + (C[b] - C[a])*(C[b] - C[a]) + dp(b+1, b+1)));
	return mini;
}

int main(){
	int n, x;
	cin >> n >> c;
	for(int i = 0; i < n; i++)
		cin >> x,
		C.push_back(x);
	cout << dp(0, 0) << endl;
}
