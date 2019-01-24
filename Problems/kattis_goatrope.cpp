#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    double dist;
    if(x <= x1 && y >= y1 && y <= y2){
        dist = x1 - x;
    }else if(x >= x1 && x <= x2 && y <= y1){
        dist = y1 - y;
    }else if(x >= x2 && y >= y1 && y <= y2){
        dist = x - x2;
    }else if(x >= x1 && x <= x2 && y >= y2){
        dist = y - y2;
    }else if(x < x1 && y > y2){
        dist = sqrt((x-x1)*(x-x1) + (y-y2)*(y-y2));
    }else if(x < x1 && y < y1){
        dist = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
    }else if(x > x2 && y < y1){
        dist = sqrt((x-x2)*(x-x2) + (y-y1)*(y-y1));
    }else if(x > x2 && y > y2){
        dist = sqrt((x-x2)*(x-x2) + (y-y2)*(y-y2));
    }
    cout << dist << endl;   
}
