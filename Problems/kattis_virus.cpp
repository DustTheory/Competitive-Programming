#include <iostream>

using namespace std;

int main(){
	string a, b;
	cin >> a >> b;
	int l = 0, r = a.length()-1;
	for(int i = 0; i < a.length(); i++){
		if(a[i] != b[i])
			break;
		l++;
	}
	int j = b.length()-1;
	for(int i = a.length()-1; i >= l && j >= l; i--){
		if(a[i] != b[j])
			break;
		r--;
		j--;
	}

//	for(int i = l; i <= j; i++){
//		cout << b[i];
	//}
	//cout << endl;
	if(j-l+1 < 0)
		cout << 0 << endl;
	else
		cout << j-l+1 << endl;

}
