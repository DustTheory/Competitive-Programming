#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <utility>
#include <set>

using namespace std;

bool is_injective(map<string, string> &m, vector<string> &d, vector<string> &cd){
	map<string, int> mappsto;
	map<string, int> mappsfrom;
	for(auto mapping : m){
		mappsto[mapping.first]++;
		mappsfrom[mapping.second]++;
	}
	for(auto i : mappsto)
		if(i.second > 1)
			return false;
	for(auto i: mappsfrom)
		if(i.second > 1)
			return false;
	return true;
}

bool is_surjective(map<string, string> &m, vector<string> &d, vector<string> &cd){
	set<string> mappedto;
	for(auto mapping : m)
		mappedto.insert(mapping.second);
	if(cd.size() - 1 == mappedto.size())
		return true;
	return false;
}

bool is_afunction(map<string, string> &m, vector<string> &d, vector<string> &cd){
	set<string> mappedfrom;
	for(auto mapping : m)
		mappedfrom.insert(mapping.first);
	if(d.size() - 1 == mappedfrom.size())
		return true;
	return false;
}

int main(){
	string domain, codomain;
	while(getline(cin, domain)){	
		//getline(cin , domain);
		getline(cin, codomain);
		stringstream ez(domain);
		
		vector<string> codomains;
		vector<string> domains;

		string tmp;
		while(ez >> tmp)
			domains.push_back(tmp);
		
		ez = stringstream(codomain);
		while(ez >> tmp)
			codomains.push_back(tmp);
		
		map<string, string> mappings;

		int n;
		cin >> n;
		//cout << n << endl;
		string a, b, c;
		bool isafunction = true;
		for(int i = 0; i < n; i++){
			cin >> a >> b >> c;
			if(mappings.find(a) != mappings.end())
				isafunction = false;
			mappings.insert({a, c});
		}
		bool injective = is_injective(mappings, domains, codomains);
		bool surjective = is_surjective(mappings, domains, codomains);
		//bool isfunction = is_afunction(mappings, domains, codomains);
		if(!isafunction)
			cout << "not a function" << endl;
		else{
			if(injective && surjective)
				cout << "bijective" << endl;
			else if(injective)
				cout << "injective" << endl;
			else if(surjective)
				cout << "surjective" << endl;
			else
				cout << "neither injective nor surjective" << endl;
		}
		cin.ignore();
	}
}
