#include <iostream>

using namespace std;

int matrix[1010][1010];
int matrix2[1010][1010];
int n, m;
int coast = 0;

void paint(int i, int j, int color){
    matrix[i][j] = color;
    int c = 0;
    if(i > 0 && matrix[i-1][j] == 1)
        paint(i-1, j, color);
    else if(i > 0 && matrix[i-1][j] == 2)
        c++;

    if(j > 0 && matrix[i][j-1] == 1)
        paint(i, j-1, color);
    else if(j > 0 && matrix[i][j-1] == 2)
        c++;

    if(j < m && matrix[i][j+1] == 1)
        paint(i, j+1, color);
    else if(j <= m && matrix[i][j+1] == 2)
        c++;

    if(i < n && matrix[i+1][j] == 1)
        paint(i+1, j, color);
    else if(i <= n && matrix[i+1][j] == 2)
        c++;

    matrix2[i][j] = c;
    coast+=c;
}

void paint_water(int i, int j){
    matrix[i][j] = 2;
    int cnt = 0;
    if(i > 0 && matrix[i-1][j] == 0)
        paint_water(i-1, j);

    if(j > 0 && matrix[i][j-1] == 0)
        paint_water(i, j-1);

    if(j <= m && matrix[i][j+1] == 0)
        paint_water(i, j+1);

    if(i <= n && matrix[i+1][j] == 0)
        paint_water(i+1, j);

}

int main(){
    cin >> n >> m;
    string s;
    for(int i = 1; i <= n; i++){
        cin >> s;
        for(int k = 1; k <= s.length(); k++)
            matrix[i][k] = s[k-1]-'0';
    }

    // water is colored 2
    for(int i = 0; i <= n+1; i++)
        for(int j = 0; j <= m+1; j++)
            if(matrix[i][j] == 0 && (i == 0 || j == 0 || i == n+1 || j == m+1))
                paint_water(i, j);


    int cnt = 3;
    for(int i = 0; i <= n+1; i++)
        for(int j = 0; j <= m+1; j++)
            if(matrix[i][j] == 1){
                paint(i, j, cnt);
                cnt++;
            }
/*
    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j <= m+1; j++)
            cout << matrix[i][j]%10;
        cout << endl;
    }
    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j <= m+1; j++)
            cout << matrix2[i][j];
        cout << endl;
    }
*/
    cout << coast << endl;
}
