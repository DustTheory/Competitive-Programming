#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
	int a,b,c,d,k;
	cin >> a >> b >> c >> d >> k;
	int h = ceil((double)a/c);
	int o = ceil((double)b/d);
	if(h+o <= k)
		cout << h << ' ' << o << endl;
	else
		cout << -1 << endl;
	}
}
