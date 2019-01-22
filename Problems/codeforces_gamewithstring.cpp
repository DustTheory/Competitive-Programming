#include <iostream>

using namespace std;

int main(){
	string s;
	cin >> s;
	int turn = 1;
	while(1){
		bool success = false;
		for(int i = 1; i < s.length(); i++){
			if(s[i-1] == s[i]){
				success = true;
				s.erase(i-1, 2);
				break;
			}
		}
		if(!success)
			break;
		turn++;
	}
	if(turn % 2 == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
 }
  