#include <iostream>

using namespace std;

int main(){
	int da, db;
	cin >> da >> db;
	int a, b;
	if(da == 9 && db == 1){
		cout << 9 << ' ' << 10 << endl;
		return 0;
	}
	if(da == db)
		b = db*10, a = b+1;
	else if(db == da+1)
		a = db*10, b = a-1;
	else{
		cout << -1 << endl;
	   	return 0;
	}
	cout << b << ' ' << a << endl;
	return 0;
}
