#include <iostream>

using namespace std;

bool N[210];
bool M[210];

int main(){
	int n, m, x;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		N[x] = true;
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> x;
		M[x] = true;
	}

	for(int i = 0; i <= 200; i++){
		for(int j = 0; j <= 200; j++){
			if(N[i] == true && M[j] == true && N[i+j] == false && M[i+j] == false){
				cout << i << ' ' << j << endl;	
				return 0;
			}
		}
	}
return 0;
}
