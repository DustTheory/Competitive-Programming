#include <iostream>

using namespace std;

int main() {
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t++){
    unsigned long long n;
    cin >> n;
    cout << "Case " << t+1 << ": ";
    if(n == 1)
    	cout << 0 << endl;
    else{
    unsigned long long res = n*n - (n+1)*n/2;
    if(res%2==0)
      cout << res/2 << endl;
    else 
      cout << res << '/' << 2 << endl;
    }
  }
}