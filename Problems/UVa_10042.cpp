#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> prime;
vector<int> prime_digits;

int sum_of_digits(int n){
    int sum = 0;
    while(n > 0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

void generate_prime(){
    int n = 1000000; // up to 100k
    bool not_prime[n] = {0};
    for(int i = 2; i <= sqrt(n); i++)
        for(int j = i*2; j <= n; j+=i)
            not_prime[j] = true;
    
    prime.clear();
    for(int i = 1; i <= n; i++)
        if(!not_prime[i]){
            prime.push_back(i);
            prime_digits.push_back(sum_of_digits(i));
        }
    
}

int factorize(int n){
    if(n <= 1000000 && prime[n])
        return -1;
    int sum = 0;
    int i = 1;
    int c = n;
    while(c!=1){
        while(c%prime[i] == 0){
            sum += prime_digits[i];
            c /= prime[i];
        }
        i++;
    }
    return sum;
}

int main(){
    generate_prime();
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t++){
        int n;
        cin >> n;
        while(1){
            n++;
            if(sum_of_digits(n) == factorize(n)){
                cout << n << endl;
                break;    
            }
        }
    }
}
