#include <iostream>

using namespace std;

char mat[510][510];
int dists[510][510];

int main(){
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
		scanf("%s", mat[i]);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(mat[i][j] == '+')
				trees.push_back({i, j});
		
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(auto tree : trees)
				dists[i][j] = max(dists[i][j], abs(i - tree.x) + abs(j-tree.y));
			
		
	
}
