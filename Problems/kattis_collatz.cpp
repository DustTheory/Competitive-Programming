#include <iostream>
#include <vector>

using namespace std;

int main(){
	while(true){
		unsigned long long a, b;
		cin >> a >> b;
		if(a == b && b == 0)
			break;
		unsigned long long a_org = a, b_org = b;
		vector<int> apath;
		vector<int> bpath;
		while(a != 1){
			apath.push_back(a);
			if(a%2 == 0)
				a/=2;
			else
				a = a*3+1;
		}
		while(b != 1){
			bpath.push_back(b);
			if(b%2 == 0)
				b/=2;
			else
				b = b*3+1;
		}
		bool found = false;
		for(int i = 0; i < apath.size(); i++){
			for(int j = 0; j < bpath.size(); j++){
				if(apath[i] == bpath[j]){
					cout << a_org << " needs " << i << " steps, " << b_org << " needs " << j << " steps, they meet at " << apath[i] << endl; 
					found = true;
					break;
				}
			}
			if(found)
				break;
		}
		int as = apath.size(), bs = bpath.size();		
		if(!found)
			cout << a_org << " needs " << as << " steps, " << b_org << " needs " << bs << " steps, they meet at " << 1 << endl; 
	}	
}
