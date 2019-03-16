#include <iostream>

using namespace std;

int f(string &s){
	int rjesenje = 0;
	int jed_do_sad = 0;
	for(int i = s.length(); i >= 0; i--){
		if(s[i] == '1'){
			rjesenje += (s.length()-i-1)-jed_do_sad;
			jed_do_sad++;
			cout << i << ' ' << jed_do_sad << ' ' << rjesenje << endl;
		}	
	}	
	return rjesenje;
}

int main(){
	string s;
	cin >> s;
	cout << f(s) << endl;
}
