#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<unsigned long long> L;
vector<unsigned long long> H;
vector<unsigned long long> O;
unsigned long long n;


vector<unsigned long long> last_bigger;

#define BEGINNING 1 << 29

void calc_last_bigger(int p){
	for(int i = p; i < n; i++){
		if(H[i] > H[i-1]){
			int j = i-1;
			while(j != BEGINNING && H[i] > H[j]){
				 	j = last_bigger[j];
			}
			last_bigger[i] = j;
		}else{
			last_bigger[i] = i-1; 
		}
	}
}

void calculate_overflow(){
	vector<unsigned long long> W;
	for(int i = 0; i < H.size(); i++)
		if(i == 0)
				W.push_back(H[i]);
		else
				W.push_back(H[i] + W[i-1]);

	last_bigger[0] = BEGINNING;

	calc_last_bigger(1);

	//cout << endl;
	unsigned long long max = 0;
	unsigned long long curr = 0;
	for(int i = 0; i < n; i++){
		if(i == 0 || H[i] >= H[max]){
			curr = H[i] * L[i] - (i == 0 ? 0 : W[i-1]);
			max = i;
		}else if(H[i] > H[i-1]){
			unsigned long long last = last_bigger[i];
			curr = O[last] + ((H[i] * (L[i] - L[last] - 1)) - (W[i-1] - W[last]));
			//printf(" %llu + (%llu -  %llu) = %llu + %llu = %llu\n", O[last], (H[i] * (L[i] - L[last] - 1)), (W[i-1] - W[last]), O[last],((H[i] * (L[i] - L[last] - 1)) - (W[i-1] - W[last])), curr); 
		}else
			curr += H[i] * (L[i] - L[i-1] - 1);
		//cout << curr << ' ';
		O.push_back(curr);
	}
	//cout << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--){
	L.clear();
	H.clear();
	O.clear();
	last_bigger.clear();
	cin >> n;
	if(n!=0){
	L.resize(n);
	H.resize(n);
	last_bigger.resize(n);
	
	for(unsigned long long i = 0; i < n; i++)
		cin >> L[i];
	
	for(unsigned long long i = 0; i < n; i++)
		cin >> H[i];

	calculate_overflow();

	/*cout << endl;
	for(int i = 0; i < n; i++)
		cout << O[i] << ' ';
	cout << endl;

	cout << "LAST BIGGER" << endl;
	for(int i = 0; i < n; i++)
			cout << last_bigger[i] << ' ';
	cout << endl << "#####################" << endl;
*/
	unsigned long long q, k;
	cin >> q;
	unsigned long long l, h, m;
	while(q--){
		cin >> k;
		//l = 0, h = n-1;
		/*while(l <= h){
			m = (h+l)/2;
			if(k <= O[m]){
				h = m-1;
			}else{
				ans = m+1;
				l = m+1;
			}
		}*/
		/*for(int i = 0; i < n; i++){
			if(k > O[i]){
				ans = i + 1;
			}else{
				break;
			}
		}*/
		auto low = lower_bound(O.begin(), O.end(), k, [](unsigned long long a, unsigned long long b){
			return a < b;				
		});
		cout << (low - O.begin()) << endl;
	}
	}else{
		unsigned long long q, k;
		cin >> q;
		while(q--){
			cin >> k;
			cout << 0 << endl;
		}
	}}
}
