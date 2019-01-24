#include <iostream>
#include <vector>
using namespace std;

int n;
string s;

int memo[110][110][110];

int rek(int m, int w, vector<bool> taken, string str){
	if(m+w > s.length()-1 && abs(w-m) <= n){
	//	cout << str << endl;
		return m+w;
	}
	if(abs(w-m) > n){
	//	cout << str << endl;
		return w+m-1;
	}
	int first = -1, second = -1;
	int cnt = 0;
	for(int i = 0; i < s.length(); i++){
		if(cnt == 2)
			break;
		if(!taken[i]){
			if(cnt == 0)
				first = i;
			else if(cnt == 1)
				second = i;
			cnt++;
		}
	}
	if(memo[first+1][second+1][abs(m-w)] != -69)
		return memo[first+1][second+1][abs(m-w)];
//	cout << first << ' ' << second << endl;
	int option1 = -99999999, option2 = -99999999;
	if(first != -1){
		taken[first] = true;
		if(s[first] == 'W')
			option1 = rek(m, w+1, taken, str+"W");
		else if(s[first] == 'M')
			option1 = rek(m+1, w, taken, str+"M");
		taken[first] = false;
	}
	if(second != -1 && s[first] != s[second]){
		taken[second] = true;
		if(s[second] == 'W')
			option2 = rek(m, w+1, taken, str+"W");
		else if(s[first] == 'M')
			option2 = rek(m+1, w, taken, str+"M");
		taken[second] = false;
	}
	memo[first+1][second+1][abs(m-w)] = max(option1, option2);
	return memo[first+1][second+1][abs(m-w)];
}

int main(){

	
	vector<bool> taken(110, 0);
	for(int i = 0; i < 110; i++)
		for(int j = 0; j < 110; j++)
			for(int k = 0; k < 110; k++)
				memo[i][j][k] = -69;
	cin >> n;
	cin >> s;
	int res = rek(0, 0, taken, "");
	if(res < 0)
		cout << 0 << endl;
	else
		cout << res << endl;
}