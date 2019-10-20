#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<map<int, int>> rows;
vector<map<int, int>> cols;

int has(map<int, int> &s, int x){
	auto it = s.find(x);
	return it != s.end() ? it->second : -1;
}

struct Vec2{
	int x, y;
};

Vec2 operator-(Vec2 &a, Vec2&b){
	return {a.x - b.x, a.y - b.y};
}

enum Dir{
	U = 0,
	D,
	L,
	R
};

int dirs[4][2] = {
	{-1, 0},
	{+1, 0},
	{0, -1},
	{0, +1}
};

vector<Vec2> nodes;
vector<vector<int>> graph;
vector<vector<int>> tree;
vector<bool> visited;
vector<int> par;
vector<Dir> dir;
vector<int> ns;
queue<int> q;

void dfs(int p){
	visited[p] = true;
	for(int v : tree[p]){
		if(!visited[v]){
			par[v] = p;
			//determine dir
			Vec2 d = nodes[p]-nodes[v];
			//find d in dirs
			if(d.x == -1 && d.y == 0)
				dir[v] = Dir::U;
			if(d.x == +1 && d.y == 0)
				dir[v] = Dir::D;
			if(d.x == 0 && d.y == -1)
				dir[v] = Dir::L;
			if(d.x == 0 && d.y == +1)
				dir[v] = Dir::R;
			if(dir[v] == Dir::U){
				auto it = cols[nodes[v].y].upper_bound(nodes[v].x);
				if(it == cols[nodes[v].y].end())
					ns[v] = -1;
				else{
					ns[v] = it->second;
				}
			}
			if(dir[v] == Dir::D){
				auto it = cols[nodes[v].y].lower_bound(nodes[v].x);
				if(it == cols[nodes[v].y].begin())
					ns[v] = -1;
				else{
					it--;
					ns[v] = it->second;
				}
			}
			if(dir[v] == Dir::L){
				auto it = rows[nodes[v].x].upper_bound(nodes[v].y);
				if(it == rows[nodes[v].x].end())
					ns[v] = -1;
				else{
					ns[v] = it->second;
				}
			}
			if(dir[v] == Dir::R){
				auto it = rows[nodes[v].x].lower_bound(nodes[v].y);
				if(it == rows[nodes[v].x].begin())
					ns[v] = -1;
				else{
					it--;
					ns[v] = it->second;
				}
			}
			dfs(v);
		}	
	}
}

vector<int> S;

bool toposort(){
	vector<int> in;
	for(int i = 0; i < graph.size(); i++)
		in.push_back(0);
	for(int i = 0; i < graph.size(); i++){
		for(int v : graph[i])
			in[v]++;
	}
	queue<int> q;
	for(int i = 0; i < in.size(); i++){
		if(in[i] == 0){
			q.push(i);
		}
		//cout << in[i] << endl;
	}

	while(!q.empty()){
		int v = q.front();
		q.pop();
		S.push_back(v);
		for(int u : graph[v]){
			in[u]--;
			if(in[u] == 0)
				q.push(u);
		}
	}
	for(int x : in)
		if(x != 0)
			return false;
	return true;
}

char dirch[4] = {'^', 'v', '<', '>'};

int main(){
	int m, n, b;
	cin >> m >> n >> b;
	tree.assign(b, vector<int>());
	graph.assign(b, vector<int>());
	par.assign(b, 0);
	ns.assign(b, -1);
	dir.assign(b, Dir::U);
	rows.assign(m+1, map<int, int>());
	cols.assign(n+1, map<int, int>());	
	for(int i = 0; i < b; i++){
		int r, c;
		cin >> r >> c;
		
		nodes.push_back({r, c});
		rows[r].insert({c, i});
		cols[c].insert({r, i});
		int n;
	   	
		n = has(rows[r], c+1);
		if(n != -1){
			tree[i].push_back(n);
			tree[n].push_back(i);	
		}
		
		n = has(rows[r], c-1);
		if(n != -1){
			tree[i].push_back(n);
			tree[n].push_back(i);	
		}

		n = has(cols[c], r-1);
		if(n != -1){
			tree[i].push_back(n);
			tree[n].push_back(i);	
		}
		
		n = has(cols[c], r+1);
		if(n != -1){
			tree[i].push_back(n);
			tree[n].push_back(i);	
		}
	}
	
	visited.clear();
	for(int i = 0; i < tree.size(); i++)
		visited.push_back(false);
	dfs(0);
	//for(int i = 0; i < tree.size(); i++){
	//	cout << i << ' ' << par[i] << ' ' << dirch[dir[i]]  <<  ' ' << ns[i] << endl;
	//}
	for(int i = 0; i < tree.size(); i++){
		if(par[i] != i && find(graph[par[i]].begin(), graph[par[i]].end(), i) == graph[par[i]].end())
			graph[par[i]].push_back(i);
		if(ns[i] != -1){
			if(ns[i] != i && find(graph[i].begin(), graph[i].end(), ns[i]) == graph[i].end())
				graph[i].push_back(ns[i]);
		}
	}
	/*
	for(int i = 0; i < graph.size(); i++){
		cout << i << ": ";
		for(int j = 0; j < graph[i].size(); j++){
			cout << graph[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	bool possible = toposort();
	if(possible){
	cout << "possible" << endl;
	for(int i = 1; i < S.size(); i++){
//		cout << S[i] << endl;

		cout << dirch[dir[S[i]]] << ' ';
		if(dir[S[i]] == Dir::U || dir[S[i]] == Dir::D){
			cout << nodes[S[i]].y;
		}else
			cout << nodes[S[i]].x;
		cout << endl;

	}
	}else
		cout << "impossible" << endl;
}
