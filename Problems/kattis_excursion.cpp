#include <iostream>

using namespace std;

int main(){
	string s;
	cin >> s;
	long l = 0;
	long cnt = 0;
	string s2;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '0'){
			cnt+=(i-l);
			l++;
		}else{
			s2+=s[i];
		}
	}
//	cout << cnt << ' ' << s2 << endl;
	long r = s2.length()-1;
	for(int i = s2.length()-1; i >= 0; i--){
		if(s2[i] == '2'){
			cnt+=(r-i);
//			for(int j = i; j < r;  j++){
//				swap(s[j], s[j+1]);
//				cnt++;
//			}
			r--;
		}
	}
	cout << cnt << endl;
}
