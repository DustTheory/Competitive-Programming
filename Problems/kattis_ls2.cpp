#include<iostream>

using namespace std;

int n;
string s, p;

int mem[101][101];

bool dothething(int ps, int pp){
	if(ps >= s.length() && pp >= p.length())
		return true;
	if(ps >= s.length() || pp >= p.length())
		return false;
	if(mem[ps][pp] != -1)
		return mem[ps][pp];
	if(p[pp] == '*'){
		return mem[ps][pp] = dothething(ps+1, pp) || 
				dothething(ps, pp+1) ||
				dothething(ps+1, pp+1);	
	}else{
		if(s[ps] != p[pp])
			return mem[ps][pp] = false;
		return mem[ps][pp] = dothething(ps+1, pp+1);
	}
}

int main(){
	
	cin >> p >> n;
	while(n--){
		cin >> s;
		for(int i = 0; i <= 100; i++)
			for(int j = 0; j <= 100; j++)
				mem[i][j] = -1;
		if(dothething(0, 0))
			cout << s << endl;
	}
}

