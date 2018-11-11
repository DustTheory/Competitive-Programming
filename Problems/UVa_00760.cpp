#include <iostream>
#include <vector>

using namespace std;

int char_to_int(char a){
	if(a == 'a')
		return 0;
	if(a == 't')
		return 1;
	if(a == 'c')
		return 2;
	if(a == 'g')
		return 3;
}

struct suffix_tree{
	vector<suffix_tree*> children;
	suffix_tree(){
		for(int i = 0; i < 4; i++)
			children.push_back(NULL);
	}
	void add_child(string &s, int i = 0){
		if(i == s.length())
			return;
		char c = char_to_int(s[i]);
		if(children[i] == NULL)
			children[i] = new suffix_tree();
		children[i]->add_child(s, i+1);
	}
	void do_the_thing(){
		cout << "THING" << endl;
	}
};

int main(){
	suffix_tree st; 
	string s;
	while(1){
		if(cin.eof())
			break;
		getline(cin, s);
		if(s == ""){
			st.do_the_thing();
			st = suffix_tree();
		}
		st.add_child(s);
	}
}
