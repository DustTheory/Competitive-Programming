#include <iostream>
#include <map>
#include <vector>

using namespace std;

int lastvisited[50];
int visits[50];

int main(){
	int n, m;
	cin >> n >> m;
	map<string, int> friends;
	int id = 0;
	vector<pair<int, int>> vek;
	for(int i = 0; i < n; i++){
		int a;
		string f;
		cin >> a;
		if(a == 1){
			vek.push_back({1, 0});
		}
		if(a == 2){
			cin >> f;
			if(friends.insert({f, id}).second)
				id++;
			vek.push_back({2, friends[f]});
		}
	}

	int cnt = 1;

	for(int i = 0; i < vek.size(); i++){
		if(vek[i].first == 1){
			cnt++;
		}else{
			if(lastvisited[vek[i].second] != cnt){
				lastvisited[vek[i].second] = cnt;
				visits[vek[i].second]++;
			}
		}
	}

	bool unhappy[50] = {0};
	vector<int> friends2;
	for(int i = vek.size()-1; i >= 0 ; i--){
		if(vek[i].first == 1){
			int mini = 99999999;
			int mini_id = 0;
			for(int j = 0; j < friends2.size(); j++){
				if(visits[friends2[j]] < mini && !unhappy[friends2[j]]){
					mini = visits[friends2[j]];
					mini_id = friends2[j];
				}
				if(!unhappy[friends2[j]])
					unhappy[friends2[j]] = true;
			}
			unhappy[mini_id] = false;
			friends2.clear();
		}else{
			friends2.push_back(vek[i].second);
		}
	}
	int cnt2 = 0;
	for(int i = 0; i < m; i++){
		cnt2 += unhappy[i];
	//	cout << i << ' ' << unhappy[i] << endl;
	}
	cout << m-cnt2 << endl;
}
