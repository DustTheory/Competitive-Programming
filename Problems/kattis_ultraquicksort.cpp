#include <iostream>

using namespace std;

int _sort(long long* arr, int from, int to, int n){
    if(to >= n)
        return 0;
    if(from == to)
        return 0;
    if(to-from == 1){
        if(arr[from] > arr[to]){
            swap(arr[from], arr[to]);
            return 0;
        }
        return 0;
    }
    int mid = (1+from+to)/2;
    int r = 0;
    r += _sort(arr, from, mid, n);
    r += _sort(arr, mid+1, to, n);
    int k = from;
    int i = from;
    int j = mid+1;
    int cnt = 0;
    while( i < mid && j <= to){
        if(arr[i] < arr[j]){
            arr[k] = arr[i];
            i++;
        }else if(arr[j] <= arr[i]){
            arr[k] = arr[j];
            j++;
            cnt += mid+1-i;
        }
        k++;
    }
    if(i < mid){
        while(k < to){
            arr[k] == arr[i];
            k++;
            i++;
        }
    }
    if(j < to){
        while(k < to){
            arr[k] == arr[j];
            k++;
            j++;
        }
    }
    return r+cnt;
}

int main(){
    int n;
    cin >> n;
    long long* arr = new long long[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << _sort(arr, 0, n-1, n) << endl;
   // for(int i = 0; i < n; i++){
   //     for(int j = 0; j < n-1; j++){
   //         if(arr[j] > arr[j+1]){
   //             cnt++;
   //             swap(arr[j+1], arr[j]);
    //        }
  //      }
  //  }
   // cout << cnt << endl;
}
