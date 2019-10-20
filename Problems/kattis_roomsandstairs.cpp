#include <iostream>

using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
	int n;
	cin >> n;
	string s;
	cin >> s;
:q
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			mini = min(mini, min(i, n-i-1));
		}
	}
	if(mini == 1<<29)
		cout << n << endl;
	else
		cout << (n-mini)*2 << endl;
	}
}
