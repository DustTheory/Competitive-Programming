#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
struct Node{
	Node *l, *r, *u, *d;
	int x, y;
	Node(int x, int y): x(x), y(y){
		l = r = u = d = nullptr;
	}
};

void dfs(Node* curr){
	
}
		Node* curr = new Node(r, c);
		nodelist.push_back(curr);		
		for(list<Node*>::iterator it = nodelist.begin(); it != nodelist.end(); i++){
			if(abs(r-(*it)->x) + abs(c-(*it)->y) == 1){
				if((*it)->x > r){
					curr->u = *it;
					(*it)->d = curr;	
				}else if((*it)->x < r){
					curr->d = *it;
					(*it)->u = curr;	
				}else if((*it)->y > c){
					curr->r = *it;
					(*it)->l = curr;	
				}else if((*it)->y < c){
					curr->l = *it;
					(*it)->r = curr;	
				}		

			}
		}
*/

struct Vec4{
	int a, b, c, d;
};


vector<vector<int>> rows;
vector<vector<int>> cols;
vector<vector<bool>> r_in;
vector<vector<bool>> c_in;
vector<bool> c_f;
vector<bool> r_f;

queue<Vec4> q;

bool addable(int x, int e, bool col){
	if(col){
		if(c_f[x]){	
 			bool blocked_before = false, blocked_after = false;
			for(int i = e+1; i < cols[x].size(); i++){
				if(c_in[x][i]){
					blocked_after = true;
					break;
				}
			}
			for(int i = e-1; i >= 0; i--){
				if(c_in[x][i]){
					blocked_before = true;
					break;
				}
			}
			if(blocked_before && blocked_after)
				return false;
			//if(!blocked_before && !blocked_after){
			//	c_f[x] = true;
			//	return true;
			//}
			if(e-1 >= 0 && c_in[x][e-1]){
				c_f[x] = true;
				return true;
			}
			if(e+1 < cols[x].size() && c_in[x][e+1]){
				c_f[x] = true;
				return true;
			}
		}else{
			c_f[x] = true;
			return true;
		}
	}else{
		if(r_f[x]){
 			bool blocked_before = false, blocked_after = false;
			for(int i = e+1; i < rows[x].size(); i++){
				if(r_in[x][i]){
					blocked_after = true;
					break;
				}
			}
			for(int i = e-1; i >= 0; i--){
				if(r_in[x][i]){
					blocked_before = true;
					break;
				}
			}
			if(blocked_before && blocked_after){
				return false;
			}
			//if(!blocked_before && !blocked_after){
		//		r_f[x] = true;
		//		return true;
		//	}
			if(e-1 >= 0 && r_in[x][e-1]){
				r_f[x] = true;
				return true;
			}
			if(e+1 < rows[x].size() && r_in[x][e+1]){
				r_f[x] = true;
				return true;
			}
		}else{
			r_f[x] = true;
			return true;
		}
	}
	//cout << "WUH?" << endl;
	return false;
}

stringstream ss;
//define ss cout

int solve(){	
	int added = 1;
	int since_last_change = 0;
	while(!q.empty()){
		Vec4 c = q.front();
		//cout << c.a << ' ' << c.b << ' ' << c.c << ' ' << c.d << endl;
		q.pop();
		bool change = false;
		if(c.c + 1 < rows[c.a].size() && rows[c.a][c.c+1] == rows[c.a][c.c]+1 && c.b+1 < cols.size() && !r_in[c.a][c.c+1]){
			int e = (int)(lower_bound(cols[c.b+1].begin(), cols[c.b+1].end(), c.a) -  cols[c.b+1].begin());
			if(addable(c.b+1, e, true)){
				ss << "< " << c.a << endl;
				q.push({c.a, c.b+1, c.c+1, e});
				r_in[c.a][c.c+1] = true;
				c_in[c.b+1][e] = true;
				change = true;
			}else{
				q.push(c);
			}
		}
		if(c.c - 1 > 0 && rows[c.a][c.c-1] == rows[c.a][c.c]-1 && c.b-1 > 0 && !r_in[c.a][c.c-1]){
			int e = (int)(lower_bound(cols[c.b-1].begin(), cols[c.b-1].end(), c.a) -  cols[c.b-1].begin());
			if(addable(c.b-1, e, true)){
				ss << "> " << c.a << endl;
				q.push({c.a, c.b-1, c.c-1, e});
				r_in[c.a][c.c-1] = true;
				c_in[c.b-1][e] = true;
				change = true;
			}else{
				q.push(c);
			}
		}
		if(c.d + 1 < cols[c.b].size() && cols[c.b][c.d+1] == cols[c.b][c.d]+1 && c.a+1 < rows.size() && !c_in[c.b][c.d+1]){
			int e = (int)(lower_bound(rows[c.a+1].begin(), rows[c.a+1].end(), c.b) - rows[c.a+1].begin());	
			if(addable(c.a+1, e, false)){
				ss << "^ " << c.b << endl;
				q.push({c.a+1, c.b, e, c.d+1});
				r_in[c.a+1][e] = true;
				c_in[c.b][c.d+1] = true;
				change = true;
			}else{
				q.push(c);
			}
		}
		if(c.d - 1 > 0 && cols[c.b][c.d-1] == cols[c.b][c.d]-1 && c.a-1 > 0 && !c_in[c.b][c.d-1]){
			int e = (int)(lower_bound(rows[c.a-1].begin(), rows[c.a-1].end(), c.b) - rows[c.a-1].begin());	
			if(addable(c.a-1, e, false)){
				ss << "v " << c.b << endl;
				q.push({c.a-1, c.b, e, c.d-1});
				r_in[c.a-1][e] = true;
				c_in[c.b][c.d-1] = true;
				change = true;
			}else{
				q.push(c);
			}
		}
		added++;
		if(!change)
			since_last_change++;
		else
			since_last_change = 0;
		if(since_last_change > q.size())
			break;
		//cout << since_last_change << endl;
	}
	return added-1;
}

int main(){
	int m, n, b, r, c;
	cin >> m >> n >> b;

	int x, y;

	for(int i = 0; i <= m; i++)
		rows.push_back(vector<int>()), r_in.push_back(vector<bool>());
	for(int i = 0; i <= n; i++)
		cols.push_back(vector<int>()), c_in.push_back(vector<bool>());

	for(int i = 0; i < b; i++){
		cin >> r >> c;
		if(i == 0)
			x = r, y = c;
		rows[r].push_back(c);
		cols[c].push_back(r);
		r_in[r].push_back(false);
		c_in[c].push_back(false);
	}
	for(int i = 0; i <= m; i++){
		r_f.push_back(0);
		sort(rows[i].begin(), rows[i].end());
	}
	for(int i = 0; i <= n; i++){
		c_f.push_back(0);
		sort(cols[i].begin(), cols[i].end());
	}
	/*
	cout << "ROWS" << endl;
	for(int i = 0; i <= m; i++){
		cout << i << ": ";
		for(int j = 0; j < rows[i].size(); j++)
			cout << rows[i][j] << ' ';
		cout << endl;
	}
	cout << "COLS" << endl;
	for(int i = 0; i <= n; i++){
		cout << i << ": ";
		for(int j = 0; j < cols[i].size(); j++)
			cout << cols[i][j] << ' ';
		cout << endl;
	}
	*/
	int sx, sy;
	sx = (int)(lower_bound(rows[x].begin(), rows[x].end(), y) - rows[x].begin());
	sy = (int)(lower_bound(cols[y].begin(), cols[y].end(), x) - cols[y].begin());

	q.push({x, y, sx, sy});
//	cout << "SOLVING" << endl;	
	if(solve() == b){
		cout << "possible" << endl;
		cout << ss.str();
	}else{
		cout << "impossible" << endl;
	}
}
	//	int x = q.front().x, y = q.front().y;
	//	q.pop();
	//	if(y+1 < rows[x].size() && rows[x][y+1] == rows[x][y]+1){
	//		bool good = 0;
	//		lower_bound(cols[y+1].begin(), cols[y+1].end(), )
	//	}
	//	if(y-1 >= 0 && rows[x][y-1] == rows[x][y]-1){}
	//	if(x+1 < cols[y].size() && cols[y][x+1] == cols[y][x]+1){}
	//	if(x-1 >= 0 && cols[y][x-1] == rows[y][x]-1){}
