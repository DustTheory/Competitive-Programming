#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct s{
    int x, y;
    char c;
    int cnt;
    s(int _y, int _x, int _c, int _cnt){
        x = _x;
        y = _y;
        c = _c;
        cnt = _cnt;
    }
};

bool in_bounds(int x, int y, int maxx, int maxy){
    return x >= 0 && x < maxx && y >= 0 && y < maxy;
}

int dirs[4][2] ={{0, 1},
                {1, 0},
                {0, -1},
                {-1, 0}};

void draw(int n, int y, int x, vector<string> &matrix){

    queue<s> q;
    q.push(s (y, x, 'a', 0));
    while(!q.empty()){
        matrix[q.front().y][q.front().x] = q.front().c;
        char next_c = q.front().c == 'z' ? 'a' : q.front().c+1;
        for(int i = 0; i < 4; i++){
            int nx = q.front().x+dirs[i][0], ny = q.front().y+dirs[i][1];
            if(in_bounds(nx, ny, matrix[0].size(), matrix.size()) && matrix[ny][nx] == '.' && q.front().cnt+1 < n){
                matrix[ny][nx] = ',';
                q.push(s(ny, nx, next_c, q.front().cnt+1));
            }
        }
        q.pop();
    }
    return;
}


int main(){
    int tc = 1;
    int n, row1, col1, row2, col2;
    while(1){
        cin >> n >> row1 >> col1 >> row2 >> col2;
        if(n == 0)
            break;
        int w = col2-col1+1, h = row2-row1+1;
        if(n == 1){
            cout << "Case " << tc << ":" << endl;
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++)
                    cout << 'a';
                cout << endl;
            }
        }else{
            string dummy = "";
            for(int i = 0; i < max(w*2, n*2); i++)
                dummy += ".";
            vector<string> matrix(max(w*2, n*2), dummy);
            int startingPoint_x = n - 1 + ((col1-n)/(2*n))*(2*n);
            if(startingPoint_x < col1)
                startingPoint_x += + 2*n - 2;
            int startingPoint_y = n - 1 + ((row1-n)/(2*n))*(2*n);
            if(startingPoint_x < col1)
                startingPoint_x += 2*n - 2;
            for(int i = startingPoint_y; i <= row2*2; i+=2*n-1){
                for(int j = startingPoint_x; j <= col2*2; j+=2*n-1){
                    draw(n, i-row1, j-col1, matrix);
                }
            }
            cout << "Case " << tc << ":" << endl;
            for(int k = 0; k < h; k++){
                for(int l = 0; l < w; l++)
                    cout << matrix[k][l];
                cout << endl;
            }
        }
        tc++;
    }
    return 0;
}
