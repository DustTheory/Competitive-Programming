#include <iostream>

using namespace std;
int n;

bool solve(char a, char b, char c){
	int t1 = 4, t2 = 4, t3 = 4;
	bool a1, b1, c1 = b1 = a1 = true;
	if(a == '*')
		t1 = 16;
	else if(a == '/')
		t1 = '1';
	else
		a1 = false;

	if(a == '*' || a == '/')
		if(b == '*')
			t2 = t1 * 4;
		else if(b == '/')
			t2 = t1 / 4;
		else 
			b1 =  false;
	else
		if(b == '*')
			t2 = 16;
		else if(b == '/')
			t2 = 1;
		else b1 = false;

	if(b == '*' || b == '/')
		if(c == '*')
			t3 = t2 * 4;
		else if(c == '/')
			t3 = t2 / 4;
		else
			c1 = false;
	else
		if(c == '*')
			t3 = 16;
		else if(c == '/')
			t3 = 1;
		else
			c1 = false;

	if(a1 && b1 && c1)
		return t3 == n;

	if(a1 && c1)
		if(b == '+')
			return (t1+t3) == n;
		else
			return (t1-t3) == n;
	if(a1 && b1)
		if(c == '+')
			return (t2 + 4) == n;
		else
			return (t2 - 4) == n;
	if(b1 && c1)
		if(a == '+')
			return (t1 + t3) == n;
		else
			return (t1 - t3) == n;
	int res = 4;
	if(a1){
		res = t1;
	}else{
		if(a == '+')
			res += 4;
		else
			res -= 4;
	}

	if(b1){
		if(a == '+')
			res = 4 + t2;
		else
			res = 4 - t2;
	}else{
		if(b == '+')
			res += 4;
		else
			res -= 4;
	}

	if(c1){
		if(b == '+')
				res = res - 4 + t3;
		else
				res = res + 4  - t3;

	}else{
		if(c == '+')
			res += 4;
		else
			res -= 4;
	}
	return res == n;
}

int main(){
	int m;
	cin >> m;
	while(m--){
		cin >> n;
		char ops[4] = {'*', '+', '-', '/'};
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				for(int k = 0; k < 4; k++){
					if(solve(ops[i], ops[j], ops[k])){
						printf("4 %c 4 %c 4 %c 4 = %d\n", ops[i], ops[j], ops[k], n);
						goto kek;
					}
				}
			}
		}
		cout << "no soultuion" << endl;
		kek: int badcode;
	}
}
