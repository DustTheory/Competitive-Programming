#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

struct Stop{
    int to, first_depart, depart_interval, len;
    Stop(int _to, int _fd, int _di, int _len){
    to = _to;
    first_depart = _fd;
    depart_interval = _di;
    len = _len;
    }
};

int n, m, s;
vector<vector<Stop>> graph;

int dijkstra(int start){
    queue<int> q;
    q.push(start);
    vector<int> dists(graph.size(), 1<<29);
    vector<bool> visited(graph.size(), false);
    dists[start] = 0;
    visited[start] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i = 0; i < graph[curr].size(); i++){
		int to = graph[curr][i].to;
		int len = graph[curr][i].len, first_depart = graph[curr][i].first_depart, depart_interval = graph[curr][i].depart_interval;
		int curr_time = dists[curr] + len;	
		int wait_time;
	
		if(curr_time <= first_depart){
			wait_time = (first_depart - curr_time);  
		}else if((curr_time - first_depart) % depart_interval == 0){
			wait_time = 0;
		}else{
			wait_time = depart_interval - ((curr_time - first_depart) % depart_interval);
		}
	
		curr_time += wait_time;
		if(curr_time < dists[to]){
			dists[to] = curr_time;
			q.push(to);
		}
	}
         visited[curr] = true;
    }
    return dists[0];
}

int main(){
    cin >> n >> m >> s;
    graph.resize(n);
    int from, to, first_depart, depart_interval, len;
    for(int i = 0; i < m; i++){
    	cin >> from >> to >> first_depart >> depart_interval >> len;
    	int reverse_depart = first_depart + len;
	graph[to].push_back(Stop(from, reverse_depart, depart_interval, len));
    }
    int t = dijkstra(n-1);
   // cout << t << endl;
    if(t > s)
    	cout << "impossible" << endl;
    else
    	cout << s - t << endl;
}


