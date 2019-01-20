#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int board[10][10];

#define INF 1<<29

void cleanup(){
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			board[i][j] = INF;
}

void dijkstra(int a, int b){
	queue<pair<int, int>> q;
	q.push({a, b});
	board[a][b] = 0;
	int m = 0;
	while(!q.empty()){
		int a = q.front().first, b = q.front().second;
		q.pop();
		vector<pair<int, int>> moves = {	{2, 1},
											{2, -1},
											{-2, 1},
											{-2, -1},
											{1, 2},
											{1, -2},
											{-1, -2},
											{-1, 2}
										};
		for(int i = 0; i < moves.size(); i++){
			int na = a + moves[i].first, nb = b + moves[i].second;
			if(na > 0 && na <= 8 && nb > 0 && nb <= 8 && board[a][b] + 1 < board[na][nb]){
				board[na][nb] = board[a][b] + 1;
				m = max(m, board[na][nb]);
				q.push({na, nb});
			}
		}
	}

	vector<pair<int, int>> result;

	//cout << a << ' ' << b << endl;

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(board[i][j] == m)
				result.push_back({i, j});
	//		cout << board[i][j] << ' ';
		}
	//	cout << endl;
	}


	sort(result.begin(), result.end(), [](pair<int, int> &a, pair<int, int> &b){
		if(a.second == b.second)
			return a.first< b.first;
		return a.second > b.second;
	});

	cout << m << ' ';
	for(int i = 0; i < result.size(); i++)
		if(!(result[i].first == a && result[i].second == b))
			cout << char('a'-1+result[i].first) << result[i].second << ' ';
	cout << endl;
}


int main(){
	int T;
	cin >> T;
	while(T--){
		cleanup();
		string s;
		int a, b;
		cin >> s;
		a = s[0] - 'a' + 1;
		b = s[1] - '0';
		dijkstra(a, b);
	}	
}