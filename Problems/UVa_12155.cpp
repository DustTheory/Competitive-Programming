#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct s{
    int x, y;
    char c;
    s(int _y, int _x, int _c){
        x = _x;
        y = _y;
        c = _c;
    }
};

void draw(int n, int y, int x, vector<string> &matrix){

    queue<s> q;
    q.push(s (y, x, 'a'));
    while(!q.empty()){
        cout << x << ' ' << y << endl;
        matrix[q.back().y][q.back().x] = q.back().c;
        char next_c = q.back().c == 'z' ? 'a' : q.back().c;
        q.pop();
        if(y-1 >= 0 && matrix[y-1][x] == '.')
            q.push(s(y-1, x, next_c));
        if(y+1 < matrix.size() && matrix[y+1][x] == '.')
            q.push(s(y+1, x, next_c));
        if(x-1 >= 0 && matrix[y][x-1] == '.')
            q.push(s(y, x-1, next_c));
        if(x+1 < matrix[0].size() && matrix[y][x+1] == '.')
            q.push(s(y, x+1, next_c));
    }


    return;
}


int main(){
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    int w = x2-x1, h = y2-y1;
    string dummy = "";
    for(int i = 0; i <= w; i++)
        dummy += ".";
    vector<string> matrix(h, dummy);
    int startingPoint_x = n + ((x1-n)/n)*n - 1;
    int startingPoint_y = n + ((y1-n)/n)*n - 1;
    cout << startingPoint_x << ' ' << startingPoint_y << endl;

    for(int i = startingPoint_y; i <= y2; i+=n){
        for(int j = startingPoint_x; j <= x2; j+=n){
            draw(n, i-y1, j-x1, matrix);
            for(int k = 0; k < w; k++){
                for(int l = 0; l < h; l++)
                    cout << matrix[l][w];
                cout << endl;
            }
            cout << endl;
            break;
        }
    }
    return 0;
}
