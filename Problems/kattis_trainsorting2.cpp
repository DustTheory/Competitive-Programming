#include <iostream>
#include <vector>

using namespace std;

vector<int> T;

int beforemem[10010];
int aftermem[10010];

int before(int c, int l){
	if(beforemem[l] != 0)
		return beforemem[l];
	int res = 0;
	if(c + 1 < T.size() && T[c+1] < T[l])
		res = max(res, before(c+1, c+1)+1);
	if(c + 1 < T.size())
		res = max(res, before(c+1, l));
	beforemem[l] = res;
	return res;
}
int after(int c, int l){
	if(aftermem[l] != 0)
		return aftermem[l];
	int res = 0;
	if(c + 1 < T.size() && T[c+1] > T[l])
		res = max(res, after(c+1, c+1)+1);
	if(c + 1 < T.size())
		res = max(res, after(c+1, l));
	aftermem[l] = res;
	return res;
}

int solve(){
	int m = 0;
	for(int i = 0; i < T.size(); i++){
		m = max(m, before(i, i)+after(i, i)+1);	
	}
	return m;
}
int main(){
	//for(int i = 1; i <= 100; i++)
	//	T.push_back(i);
	int n, x;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x, T.push_back(x);
	cout << solve() << endl;
}
