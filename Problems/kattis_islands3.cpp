#include <iostream>

using namespace std;

string mat[110];
int n, m;

void color_islands(int a, int b){
    mat[a][b] = '#';
    if(a > 0 && mat[a-1][b] == 'L' || mat[a-1][b] == 'C')
        color_islands(a-1, b);
    if(b > 0 && mat[a][b-1] == 'L' || mat[a][b-1] == 'C')
        color_islands(a, b-1);
    if(b < m && mat[a][b+1] == 'L' || mat[a][b+1] == 'C')
        color_islands(a, b+1);
    if(a < n && mat[a+1][b] == 'L' || mat[a+1][b] == 'C')
        color_islands(a+1, b);
}

int main(){
    string s;
    cin >> n >> m;

    for(int i = 0; i <= 100; i++)
        for(int j = 0; j <= 100; j++)
            mat[i] += 'W';
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++)
            mat[i+1][j+1] = s[j];
    }

    int cnt = 0;
    for(int i = 0; i <= 51; i++)
        for(int j = 0; j <= 51; j++)
            if(mat[i][j] == 'L'){
                cnt++;
                color_islands(i, j);
                   // for(int k = 0; k < n; k++){
                  //      for(int l = 0; l < m; l++)
                   //         cout << mat[k][l];
                   //     cout << endl;
                   // }
            }
    cout << cnt << endl;
}
