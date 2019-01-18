#include <iostream>

using namespace std;

char matrix[110][110];
int matrix2[110][110];
int n, m;

bool is_amoeba(int i, int j, int color){
 //   cout << i << ' ' << j << endl;
    matrix2[i][j] = color;
    int diri[3] = {1, 0, -1};
    int dirj[3] = {1, 0, -1};
    for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++){
            int ni = i + diri[k];
            int nj = j + dirj[l];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m)
                if(matrix2[ni][nj] == 0)
                    is_amoeba(ni, nj, color);
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];
    int cnt = 2;
    int cnt2 = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(matrix[i][j] == '.')
                matrix2[i][j] = 1;
            else
                matrix2[i][j] = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(matrix2[i][j] == 0 && is_amoeba(i, j, cnt)){
                cnt++;
                cnt2++;
              //  cout << i << ' ' << j << endl;
            }
   /* for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            if(matrix2[i][j] == 1)
                cout << ' ';
            else
                cout << matrix2[i][j];
        cout << endl;
    }*/
    cout << cnt2 << endl;
}
