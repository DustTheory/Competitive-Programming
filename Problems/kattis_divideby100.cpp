#include <iostream>

using namespace std;

int main(){
	string n;
	string m;
	cin >> n >> m;
	int k = m.length()-1;
	string result;
	if(k < n.length()){
		int i;
		for(i = 0; i < n.length()-k; i++)
			result+=n[i];
		result+='.';
		for(; i < n.length(); i++)
			result+=n[i];	
	}else{
		result = "0.";
		for(int i = 0; i < k-n.length(); i++)
			result+= '0';
		result+=n;
	}
	int until = result.length();
	for(int i = result.length()-1; i >= 0; i--){
		if(result[i] == '0'){
			until = i;
		}else if(result[i] == '.'){
			until = i;
			break;
		}else{
			until = i+1;
			break;
		}
	}
	//if(!comma)
	//else{
		for(int i = 0; i < until; i++){
			cout << result[i];
		}
		cout << endl;
	//}
}
