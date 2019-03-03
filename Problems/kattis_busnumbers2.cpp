#include <iostream>

using namespace std;

int is_bus[400000];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < 80; i++){
		for(int j = i; j < 80; j++){
			int id = i*i*i + j*j*j;
			if(id <= 400000)
    				is_bus[id]++;	
		}
	}
	bool found = false;
	//cout << n << endl;
	for(int i = n; i >= 0; i--){
		//cout << i << ' ' << is_bus[i] << endl;
		if(is_bus[i] > 1){
			found = true;
			cout << i << endl;
			break;
		}
	}
	if(!found)
		cout << "none" << endl;
}
