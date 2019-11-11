#include <algorithm>
#include <iostream>
#include <utility>
#include <math.h>
#include <vector>

using namespace std;

vector<int> primes;
void generate_primes(int limit){
	bool sieve[limit+1];
	for(int i = 2; i <= sqrt(limit); i++){
		if(!sieve[i])
			for(int j = i*2; j < limit; j+=i)
				sieve[j] = true;
	}
	for(int i = 2; i < limit; i++)
		if(!sieve[i])
			primes.push_back(i);
}

vector<pair<int, int>> pfactors[600];

void generate_prime_factors(int limit){
	for(int i = 2; i < limit; i++){
		int ci = i;
		for(int prime : primes){
			int cnt = 0;
			while(ci%prime == 0)
				cnt++, ci/=prime;
			if(cnt > 0)
				pfactors[i].push_back({prime, cnt});
		}
	}
}

int main(){
	int n, k;
	generate_primes(450);
	generate_prime_factors(450);
	
	while(cin >> n >> k){
		if(k >= n/2)
			k = n-k;
		
		int in[500] = {};
	
		for(int i = n; i > (n-k); i--)
			for(auto p : pfactors[i])
				in[p.first]+=p.second;
	
		for(int i = k; i >= 2; i--)
			for(auto p : pfactors[i])
				in[p.first]-=p.second;
		
		unsigned long long res = 1;
		for(int i = 0; i < 450; i++){
			if(in[i] != 0)
				res *= (unsigned long long)(in[i]+1);
		}
		cout << res << endl;
	}
}
