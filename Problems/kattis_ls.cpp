#include<regex>
#include <iostream>

using namespace std;

int main(){
	string p;
	cin >> p;
	string exp;
	exp+='^';
	for(int i = 0; i < p.length(); i++){
		if(p[i] == '*')
			exp+="[a-z \\.]*";
		else if(p[i] == '.')
			exp+="\\.";
		else
			exp+=p[i];
	}
	exp+='$';
	regex r(exp);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if(regex_match(s, r))
			cout << s << endl;
	}
}
