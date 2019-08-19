#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string mat[110];
int mat2[110][110];
vector<int> sizes(10, 0);
int w, h;

int c = 1;

void _flood_fill(int a, int b){
	sizes[c]++;
	mat[a][b] = 'L';
	mat2[a][b] = c;
	if(a-1>= 0 && mat[a-1][b] == 'W')
		_flood_fill(a-1, b);
	
	if(a+1 < h && mat[a+1][b] == 'W')
		_flood_fill(a+1, b);
	
	if(b+1 < w && mat[a][b+1] == 'W')
		_flood_fill(a, b+1);
	
	if(b-1 >= 0 && mat[a][b-1] == 'W')
		_flood_fill(a, b-1);

	if(a-1 >= 0 && b-1>= 0 && mat[a-1][b-1] == 'W')
		_flood_fill(a-1, b-1);
	if(a+1 < h && b-1>= 0 && mat[a+1][b-1] == 'W')
		_flood_fill(a+1, b-1);
	if(a+1 < h && b+1 < w && mat[a+1][b+1] == 'W')
		_flood_fill(a+1, b+1);
	if(a-1 >= 0 && b+1 < w && mat[a-1][b+1] == 'W')
		_flood_fill(a-1, b+1);
}

void flood_fill(){
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(mat[i][j] == 'W'){
				_flood_fill(i, j);
				sizes.push_back(0);
				c++;
			}
		}
	}
}

void cleanup(){
	w = h = 0;
	fill(mat, mat+100, "");
	for(int i = 0; i <= 100; i++)
		for(int j = 0; j <= 100; j++)
			mat2[i][j] = 0;
	sizes.clear();
	sizes.push_back(0);
	sizes.push_back(0);
	c = 1;	
}

int main(){
	int T;
	cin >> T;
	cin.ignore();
	string s;
	getline(cin, s);
	while(T--){
		cleanup();
		bool queries = false;
		int i = 0;
		while(1){
			getline(cin, s);
			if(s == "")
				break;
			if(s[0] >= '0' && s[0] <= '9'){
				if(!queries){
					queries = true;
					flood_fill();
				}
				int a, b;
				sscanf(s.c_str(), "%d %d", &a, &b);
				a--;
				b--;	
				cout << sizes[mat2[a][b]] << endl;
			}else{
				if(queries){
					queries = false;
					cleanup();
					i = 0;
				}
				mat[i] = s;
				w = mat[i].length();
				h++;
				i++;
			}
		}
		if(T != 0) cout << endl;
	}
}
