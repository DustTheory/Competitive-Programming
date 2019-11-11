#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int arr[100010];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	set<int> thing;
	int lastgcd = arr[0];
	thing.insert(lastgcd);
	for(int i = 1; i < n; i++){
		thing.insert(__gcd(arr[i], lastgcd));
		lastgcd = __gcd(arr[i], arr[i-1]);
		thing.insert(lastgcd);
		thing.insert(arr[i]);
	}
	cout << thing.size() << endl;
	
}
