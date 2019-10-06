#include <iostream>

using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		string a, b;
		cin >> a >> b;
		bool c[256] = {};
		bool possible = false;
		for(int i = 0; i < a.length(); i++)
			c[a[i]] = true;
		for(int i = 0; i < b.length(); i++)
			if(c[b[i]]){
				possible = true;
				break;
			}
		if(possible)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
