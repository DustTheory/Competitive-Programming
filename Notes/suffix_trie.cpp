#include <iostream>
#include <map>
#include <utility>
#include <stack>

using namespace std;

struct node{
	map<char, node*> children;
	node(){};
	node* add_child(char c){
		return children.insert(pair<char, node*>(c, new node())).first->second;
	}	
	node* get_child(char c){
		auto child = children.find(c);
		if(child == children.end())
			return NULL;
		return child->second;
	}
	void log(int level = 0){
		for(auto child: children){
			for(int i = 0; i < level; i++){
				cout << ' ';
			}
			cout << child.first << endl;
			child.second->log(level+1);
		}
	}
};

// Implemented: building the trie, loggingi
// 	Check whether string is a substring of trie
// 	Check whether string is a suffix of trie
//
// To be implemented:
// 	Count the number of occurences of string in trie
// 	Find the longest repeat in trie
// 	Find the lexicographically first suffix

class Suffix_trie{
	private:
		node root_node;
	public:
		Suffix_trie(){
			root_node = node();
		}
		void insert_string(string s){
			root_node.add_child('$');
			for(int i = 0; i < s.length(); i++){	
				node* curr_node = &root_node;
				for(int j = i; j < s.length(); j++){
					curr_node = curr_node->add_child(s[j]);
				}
				curr_node->add_child('$');
			}
		}
		void log_tree(){
			root_node.log();
		}
		bool is_substring(string s){
			node* curr_node = &root_node;
			for(int i = 0; i < s.length(); i++){
				curr_node = curr_node->get_child(s[i]);
				if(curr_node == NULL)
					return false;
			}
			return true;
		}
		bool is_suffix(string s){
			node* curr_node = &root_node;
			for(int i = 0; i < s.length(); i++){
				curr_node = curr_node->get_child(s[i]);
				if(curr_node == NULL)
					return false;
			}
			return curr_node->get_child('$') != NULL;
		}
		int count(string s){
				
		}

};

int main(){
	Suffix_trie st;
	st.insert_string("abaaba");
	st.log_tree();
	cout << st.is_substring("baa") << endl;
	cout << st.is_suffix("abaab") << endl;

}
