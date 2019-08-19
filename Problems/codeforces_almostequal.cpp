#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int N = 2*n;
	int arr[N];
	arr[0] = N;
	arr[n] = N-1;
	bool turn = 0;
	int ar = 1, ard = 1;
	int al = N-1, ald = 1;
	int br = n+1, brd = 1;
	int bl = n-1, bld = 1;
	for(int i = 1; i <= N-2; i++){
		if(turn == 0){
			if(ard <= ald){
				ard++;
				arr[ar] = i;
				ar++;
			}else{
				ald++;
				arr[al] = i;
				al--;
			}
		}else{
			if(bld <= brd){
				bld++;
				arr[bl] = i;
				bl--;
			}else{
				brd++;
				arr[br] = i;
				br++;
			}
		}
		turn = !turn;
	}

	for(int i = 0; i < N; i++)
		cout << arr[i] << (i == N-1 ? "\n" : " ");
	int SUM = (N+1)*N/2;

	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += arr[i];
	}

	if(abs(sum - (SUM-sum)) > 1){
		cout << "NO" << endl;
		return 0;
	}
	
	int arr2[2*N];
	for(int i = 0; i < N; i++){
		arr2[i] = arr[i];
	}
	for(int i = N; i < N*2; i++){
		arr2[i] = arr[i-N];
	}

	int b = 0;
	int e = n;
	for(int e = n; e < N*2 ; e++){
		sum += arr2[e];
		sum -= arr2[b];
		if(abs(sum - (SUM-sum)) > 1){
			cout << "NO" << endl;
			return 0;
		}
		b++;
	}

	cout << "YES" << endl;	

	for(int i = 0; i < N; i++)
		cout << arr[i] << (i == N-1 ? "\n" : " ");
	return 0;
}
