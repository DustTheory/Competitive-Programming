#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, a, b, x, y, xy, nab, na, nb;
long k;

int solve(int p[]){
		sort(p, p+n, greater<int>());
		long sum = 0;
		int i = 0;
		for(int j = 0; j < nab; j++){
			if(sum >= k)
				return i;
			if(i >= n)
				return -1;
			sum += (p[i]*(xy));	
			cout << p[i] << ' ' << p[i]*xy << endl;
			i++;
		//	cout << sum << endl;	
		}
		for(int j = 0; j < na; j++){
			if(sum >= k)
				return i;
			if(i >= n)
				return -1;
			sum += (p[i]*x);	
			cout << p[i] << ' ' << p[i]*x << endl;
			i++;
		//	cout << sum << endl;	
		}
		for(int j = 0; j < nb; j++){
			if(sum >= k)
				return i;
			if(i >= n)
				return -1;
			sum += (p[i]*y);	
			cout << p[i] << ' ' << p[i]*y << endl;
			i++;
		//	cout << sum << endl;	
		}
		return -1;
}

int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n;
		int p[n];
		for(int i = 0; i < n; i++){
			cin >> p[i];
			p[i] /= 100;
		}
		
		cin >> x >> a >> y >> b;
		xy = x+y;
		cin >> k;
		nab = n/(a*b), na = n/a, nb = n/b;
		cout << x << ' '  << y << ' ' << xy << endl;
		int sol1 = solve(p);
	   	swap(na, nb);
		swap(x, y);
		cout << "@@@2@@@" << endl;
		int sol2 = solve(p);
		cout << "     " << min(sol1, sol2) << endl;	
	}
}
