#include <vector>
#include <iostream>

using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> p;
		vector<int> q;
		int x;
		long long pp = 0, pn = 0;
		for(int i = 0; i < n; i++){
			cin >> x;
			if(x%2==0)
				pp++;
			else
				pn++;
			p.push_back(x);
		}
		int m;
		cin >> m;
		long long qp = 0, qn = 0;
		for(int j = 0; j < m; j++){
			cin >> x;
			q.push_back(x);
			if(x%2==0)
				qp++;
			else
				qn++;
		}
		long long cnt = 0;
		//for(int i = 0; i < n; i++){
		//	for(int j = 0; j < m; j++){
		//		if(abs(p[i] - q[j]) % 2 == 0)
		//			cnt++;
		//	}
	//	}
		cnt += pp*qp;
		cnt += pn*qn;
		cout << cnt << endl;
	}
}
