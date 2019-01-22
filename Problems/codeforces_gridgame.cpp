#include <iostream>
#include <vector>

using namespace std;
string s;

bool solved = false;

void rek(int pos, vector<vector<bool>> tiles, vector<pair<int, int>> res){
	if(solved)
		return;
	vector<int> rowstodelete;
	vector<int> columnstodelete;

	for(int i = 0; i < 4; i++)
		if(tiles[i][0] && tiles[i][1] && tiles[i][2] && tiles[i][3])
			rowstodelete.push_back(i);
	
	for(int i = 0; i < 4; i++)
		if(tiles[0][i] && tiles[1][i] && tiles[2][i] && tiles[3][i])
			columnstodelete.push_back(i);

	for(int i = 0; i < rowstodelete.size(); i++){
		int j = rowstodelete[i];
		tiles[j][0] = tiles[j][1] = tiles[j][2] = tiles[j][3] = 0; 
	}

	for(int i = 0; i < columnstodelete.size(); i++){
		int j = columnstodelete[i];
		tiles[0][j] = tiles[1][j] = tiles[2][j] = tiles[3][j] = 0; 
	}


	if(pos == s.length()){
		if(res.size() == s.length()){
			for(int i = 0; i < res.size(); i++){
				cout << res[i].first + 1 << ' ' << res[i].second + 1 << endl;
			}
			solved = true;
		}
		return;
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(s[pos] == '0' && i < 3 && !tiles[i][j] && !tiles[i+1][j]){
				tiles[i][j] = 1;
				tiles[i+1][j] = 1;
				res.push_back({i, j});
				rek(pos+1, tiles, res);
				res.pop_back();
				tiles[i][j] = 0;
				tiles[i+1][j] = 0;
			}else if(s[pos] == '1' && j < 3 && !tiles[i][j] && !tiles[i][j+1]){
				tiles[i][j] = 1;
				tiles[i][j+1] = 1;
				res.push_back({i, j});
				rek(pos+1, tiles, res);
				res.pop_back();
				tiles[i][j] = 0;
				tiles[i][j+1] = 0;
			}
		}
	}
}

int main(){
	cin >> s;
	vector<vector<bool>> tiles(4, vector<bool>(4, 0));	
	rek(0, tiles, vector<pair<int, int>>());
 }
  