#include <iostream>

using namespace std;

char remapto(char c1, char c2, char c){
	if(c1 == c2){
		if(c == 'R' || c == 'B')
			return 'G';
		else
			return 'R';
	}
	string arr[6] = {"RGB", "RBG", "BGR", "BRG", "GRB", "GBR"};
	for(int i = 0; i < 6; i++){
		if(c1 == arr[i][0] && c2 == arr[i][2])
			return arr[i][1];
	}
}

int main(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	int changes = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == s[i-1] && s[i+1] != s[i]){
			changes++;
			s[i] = remapto(s[i-1], s[i+1], s[i]);
		}
	}
	cout << changes << endl;
	cout << s << endl;
	return 0;
 }
  