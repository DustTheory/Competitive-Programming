#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define ll long long

bool compare(pair<ll, ll> a, pair<ll, ll> b){
    return a.first < b.first;
}

long long gcd(long long a, long long b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(false);
    ll t, n, x; // kek
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        cin >> n;
        vector<ll> arr;
        for(int i = 0; i < n; i++){
            cin >> x;
            arr.push_back(x);
        }
        ll maxi = arr[n-1];
        for(int j = n-1; j >= 0; j--){
            pair<ll, ll> last = pair<ll, ll>(arr[j], 1);
            for(int i = j-1; i >= 0; i--){
                cout << i << ' ' << j << ' ' << last.first << ' ' << last.second << endl;
                last = max(pair<ll, ll>(gcd((last.first/last.second), arr[i]) * (last.second+1), last.second+1),
                           pair<ll, ll>(arr[i], 1),
                           compare);
                maxi = max(maxi, last.first);
            }
        }
        cout << maxi << endl;
    }
}

