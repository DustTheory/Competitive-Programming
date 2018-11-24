#include <iostream> 

using namespace std;

int solution1(int n){
	int sum = 0;
	for(int i = 0; i <= n; i++){
		for(int j = i; j <=n; j++){
			sum += i+j;
		}
	}
	return sum;
}

int main(){
	cout << solution1(15) << endl;
}
