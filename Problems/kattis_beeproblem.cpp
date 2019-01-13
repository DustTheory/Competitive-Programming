#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int flood_fill(vector<vector<char>> &matrica, int i, int j, int n, int m){
    bool shift = (i+1) % 2 != 0 ? 0 : 1;
    matrica[i][j] = '#';
 //   cout << i << j << endl;
    int sum = 0;
    if(j-1 >= 0 && matrica[i][j-1] == '.'){
        sum += flood_fill(matrica, i, j-1, n, m) + 1;
    }
    if(j+1 <= m && matrica[i][j+1] == '.'){
        sum += flood_fill(matrica, i, j+1, n, m) + 1;
    }
    if(i-1 >= 0 && j - shift >= 0 && matrica[i-1][j-shift] == '.'){
        sum += flood_fill(matrica, i-1, j-shift, n, m) + 1;
    }
    if(i-1 >= 0 && j + 1 - shift <= m && matrica[i-1][j+1-shift] == '.'){
        sum += flood_fill(matrica, i-1, j+1-shift, n, m) + 1;
    }
    if(i+1 < n && j - shift >= 0 && matrica[i+1][j-shift] == '.'){
        sum += flood_fill(matrica, i+1, j-shift, n, m) + 1;
    }
    if(i+1 < n && j + 1 - shift <= m && matrica[i+1][j+1-shift] == '.'){
        sum += flood_fill(matrica, i+1, j+1-shift, n, m) + 1;
    }
    return sum;
}

int main(){
    int h, n, m;
    cin >> h >> n >> m;
    vector<vector<char>> matrica;
    for(int i = 0; i < n; i++){
        matrica.push_back(vector<char>());
        for(int j = 0; j <= m; j++)
            matrica[i].push_back(' ');
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrica[i-1][j + !(i % 2 != 0)];
        }
    }
   // for(int i = 0; i < n; i++){
  //      for(int j = 0; j <= m; j++){
   //             cout << matrica[i][j];
  //      }
  //  cout << endl;
  //  }
    vector<int> sizes;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= m; j++){
            if(matrica[i][j] == '.'){
      //          cout << i << ' ' << j << endl;
                sizes.push_back(1+flood_fill(matrica, i, j, n, m+1));
            }
        }
    }
    sort(sizes.rbegin(), sizes.rend());
    //for(int i = 0; i < sizes.size(); i++)
     //   cout << sizes[i] << endl;
    int ch = h;
    int cnt = 0;
    for(int i = 0; i < sizes.size(); i++){
        if(ch <= 0)
            break;
        ch-=sizes[i];
        cnt ++;
        if(ch <= 0)
            break;
    }
    cout << cnt << endl;
}
