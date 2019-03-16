#include <iostream>
#include <cstring>

using namespace std;

char mat[60][60];
int goldcnt = 0;
int w, h;

void count_gold(int a, int b){
	if(mat[a][b] == 'G')
		goldcnt++;

	mat[a][b] = 'V';	
	
	//cout << a << ' ' << b << endl;
	bool trapclose = false;

	if(a+1 < h && mat[a+1][b] == 'T')
		trapclose = true;

	if(b+1 < w && mat[a][b+1] == 'T')
		trapclose = true;

	if(a-1 >= 0 && mat[a-1][b] == 'T')
		trapclose = true;

	if(b-1 >= 0 && mat[a][b-1] == 'T')
		trapclose = true;
	if(!trapclose){
		if(a+1 < h && mat[a+1][b] == '.' || mat[a+1][b] == 'G' || mat[a+1][b] == 'P')
			count_gold(a+1, b);

		if(b+1 < w && mat[a][b+1] == '.' || mat[a][b+1] == 'G' || mat[a][b+1] == 'P')
			count_gold(a, b+1);

		if(a-1 >= 0 && mat[a-1][b] == '.' || mat[a-1][b] == 'G' || mat[a-1][b] == 'P')
			count_gold(a-1, b);

		if(b-1 >= 0 && mat[a][b-1] == '.' || mat[a][b-1] == 'G' || mat[a][b-1] == 'P')
			count_gold(a, b-1);
	}
}

int main(){
	cin >> w >> h;
	char tmp[60];
	int x = 0, y = 0;
	for(int i = 0; i < h; i++){
		scanf("%s", tmp);
		char* p = strchr(tmp, 'P');
		if(p != NULL){
			y = i;
			x = (int)(p-tmp);
		}	
		strcpy(mat[i], tmp);
	}
	
	count_gold(y, x);

	cout << goldcnt << endl;
}
