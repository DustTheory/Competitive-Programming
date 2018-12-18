#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> humble;

int i2, i3, i5, i7 = i5 = i3 = i2 = 0;
int next2 = 2, next3 = 3, next5 = 5, next7 = 7;
int i = 1;
void init_humble(){
    humble.clear();
    humble.push_back(1);
}

int min(int a, int b, int c, int d){
    return min(a, min(b, min(c, d)));
}

void generate_humble(int n){
    for(i; i < n; i++){
        int next = min(next2, next3, next5, next7);
        humble.push_back(next);
        if(next == next2){
            i2++;
            next2 = humble[i2]*2;
        }
        if(next == next3){
            i3++;
            next3 = humble[i3]*3;
        }
        if(next == next5){
            i5++;
            next5 = humble[i5]*5;
        }
        if(next == next7){
            i7++;
            next7 = humble[i7]*7;
        }
    }
}

int main(){
    init_humble();
    int n;
    while(1){
        cin >> n;
        if(n == 0)
            break;
        generate_humble(n);
        char* suffix = "th";
        if((n/10)%10 != 1)
            if(n%10 == 1)
                suffix = "st";
            else if(n%10 == 2)
                suffix = "nd";
            else if(n%10 == 3)
                suffix = "rd";
        printf("The %d%s humble number is %d.\n", n, suffix, humble[n-1]);
    }
    return 0;
}
