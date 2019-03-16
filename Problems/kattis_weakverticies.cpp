#include <iostream>

using namespace std;

int mat[21][21];

int main(){
	while(true){
	int n;
	cin >> n;
	if(n == -1)
		break;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> mat[i][j];
	for(int i = 0; i < n; i++){
		bool yee = false;
		for(int j = 0; j < n; j++){
			if(mat[i][j] == 1){
				for(int k = 0; k < n; k++){
					if(mat[i][k] && mat[k][j]){
						yee = true;
						break;
						}	
				}
				if(yee)
					break;
			}
		}
		if(!yee)
			cout << i << ' ';
	}
	cout << endl;
	}
}
