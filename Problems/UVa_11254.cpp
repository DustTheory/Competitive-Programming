 #include <iostream>

 using namespace std;

 unsigned long long sum(unsigned long long a, unsigned long long b){
    if(b == 0)
        return 0;
    if(a == b)
        return a;
    return (a+b)*(b-a+1)/2;
 }

bool solution(int n){
     int s = sum(1, n);
     for(int i = 0; i <= n/2+1; i++){
        int f = sum(1, i);
        for(int j = i-1; j <= n/2+1; j++){
            int b = sum(j, n);
            //cout << s - f - b << endl;
            if(s - f - b == n){
                cout << n << " = " << i+1 << " + ... + " << j-1 << endl;
                return true;
            }
        }
    }
    return false;
 }

void solution2(int n){
    int arr[n/2];
    arr[0] = 0;
    for(int i = 1; i <= n/2; i++)
        arr[i] = arr[i-1] + i;
    for(int i = 0; i <= n/2; i++)
        for(int j = i; j <= n/2; j++){
            if(arr[j] - arr[i] == n){
                cout << n << " = " << i+1 << " + ... + " << j << endl;
                return;
            }
        }
    return;
 }

 int main(){
    int n;
    while(1){
        cin >> n;
        if(n == -1)
            break;
       solution2(n);
    }
 }
