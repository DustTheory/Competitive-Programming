#include <iostream>
#include <vector>
#include <math.h>
#include <bitset>
using namespace std;

#define N 100000

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

bool is_prime(int n){
    for(int i = *(prime.end()-1); i <= sqrt(n); i++)
        if(n%i == 0)
            return false;
    return true;
}

void generate_prime(){
    bitset<N> not_prime;
    not_prime.reset();
    for(int i = 2; i <= sqrt(N); i++)
        for(int j = i*2; j < N; j+=i)
            not_prime.set(j);

    prime.clear();
    for(int i = 1; i < N; i++)
        if(!not_prime.test(i)){
            prime.push_back(i);
            prime_digits.push_back(sum_of_digits(i));
        }

}

int factorize(int n){
    int sum = 0;
    int i = 1;
    int c = n;
    int cnt = 0;
    while(c!=1 && i < prime.size()){
        while(c%prime[i] == 0){
            sum += prime_digits[i];
            c /= prime[i];
            cnt++;
        }
        i++;
    }
    if(c != n && c!=1 && is_prime(c)){
        sum += sum_of_digits(c);
    }else if(cnt == 1)
        return -1;
    return sum;
}

int main(){
    generate_prime();
 //   cout << factorize(4) << endl;
 //   cout << sum_of_digits(4) << endl;
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
