#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
vector<int> b;

int main(){
	int n;
	cin >> n;
	int x;
	a.resize(n+1);
	for(int i = 1; i <= n; i++){
		cin >> x;
		a[x] = i;
	}
	b.push_back(0);
	for(int i = 1; i <= n; i++){
		cin >> x;
		b.push_back(x);
	}
	vector<int> novi;
	novi.push_back(0);
	
	for(int i = 1; i <= n; i++)
		novi.push_back(a[b[i]]);

	int cnt = 0;

	for(int i = 1; i <= n; ){
	for(int j = 1; j <= n; j++)
		cout << novi[j] << ' ';
	cout << endl;
		if(novi[i] == i){
			i++;
			continue;
		}else{
			int k = novi[i];
			cnt++;
			for(int j = i; j < k; j++){
				cout << j << endl;
				swap(novi[j], novi[j+1]);
			}
		}
	}

	cout << cnt << endl;

}
