#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool sieve[2000000000] = {};

void create_sieve(){
    for(int i = 2; i < sqrt(2000000000); i++){
        if(!sieve[i])
            for(int j = i*2; j < 2000000000; j += i){
                sieve[j] = true;
            }
    }
}

bool is_prime(int n){
    return !sieve[n];
}

bool is_humble(int n){
    if(n <= 10)
        return true;
    if(is_prime(n))
        return false;
    for(int i = 2; i < n; i++){
        if(n % i == 0 && is_prime(i)){
            if(i != 2 && i != 3 && i != 5 && i != 7)
                return false;
        }
    }
    return true;
}

vector<int> humble_nums;

void generate_humble(){
    int cnt = 0, i = 0;
    cout << '{';
    while(cnt < 5842){
        i++;
        if(is_humble(i)){
            cout << i << ',';
        }
    }
    cout << '}';
}

int main(){
  //  create_sieve();
  //  generate_humble();
    ios_base::sync_with_stdio(false);
    for(int i = 1; i < 5842; i++){
        cout << i << endl;
    }
    int n;
   /* while(1){
        cin >> n;
        if(n == 0)
            break;
        char* suffix = "th";
        if(n%10 == 1)
            suffix = "st";
        else if(n%10 == 2)
            suffix = "nd";
        else if(n%10 == 3)
            suffix = "rd";
        printf("The %d%s humble number is %d.\n", n, suffix, humble_nums[n]);
    }*/
    return 0;
}
