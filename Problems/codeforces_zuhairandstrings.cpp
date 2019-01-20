#include <iostream>

using namespace std;

int n, k;

int count(string &s, char c){
	int cnt = 0;
	int curr = 0;
	s+="#";
	for(int i = 0; i < s.length(); i++){
		if(s[i] == c){
			curr++;
		}else{
			cnt += curr/k;
			curr = 0;
		}
	}
	return cnt;
}
int main(){
	string s;
	cin >> n >> k;
	cin >> s;
	int maxi = 0;
	for(char i = 'a'; i <= 'z'; i++){
		maxi = max(maxi, count(s, i));
	}
	cout << maxi << endl;
}
