#include <iostream>

using namespace std;

int ways(string &s){
	int r = 0;
	int pow26 = 1;
	bool possible = true;
	cout << "##############################" << endl;
	cout << s << endl;
	for(int i = 0; i < s.length()/2; i++){
		cout << s[i] << ' ' << s[s.length()-i-1] << endl;
		if(s[i] == '.'){
			if(s[s.length()-i-1] == '.'){
				pow26 *= 26*26;
			}else{
				if(s[s.length()-i-1] == s[i])
					r++;
				else{
					possible = false;
				}
			}
		}
	}
	cout << "##########################" << endl;
	if(!possible)
		return 0;
	else{
		return r*pow26;	
	}
}

int main(){
	int n;
	cin >> n;
	string a;
	cin >> a;
	int res = 0;
	for(int i = 0; i <= n; i++){
		int freecnt;
		string curr_str = "";
		for(int j = 0; j < i; j++)
			curr_str += '.';
		curr_str+=a;	
		for(int j = 0; j < n-i; j++)
			curr_str += '.';
		cout << ways(curr_str) << endl;
		//cout << curr_str << endl;
		res += ways(curr_str);
	}
	cout << res << endl;
}
