#include <iostream>

using namespace std;

void n_choose_k(int n, int k, unsigned long long &res){
	res = 1;
	int N = n;
	for(int i = n; i >= N-k+1; i--)
    		res*=i;
	unsigned long long f = 1;
	for(int i = 1; i <= k; i++)
    		f*=i;
	res /= f;
}

int main(){
	int T;
//	cin >> T;
	int n, k, x;
	//while(T--){
		cin >> n >> k;
		int black = 0, white;
		for(int i = 0; i < k; ++i){
			cin >> x;
			black += x;
		}
		white = n - black+1;
		unsigned long long res;
		cout << white << ' ' << k-1 << endl;
		n_choose_k(white, black, res);
		cout << res << endl;
		
    	//}
}
