#include <iostream>
#include <list>
#include <math.h>

using namespace std;

int n;
list<unsigned int> li;

unsigned int maxi;

struct node{
 	node* l;
	node* r;
	node(): l(NULL), r(NULL){}
	void add_node(unsigned int &goal, unsigned int a, unsigned int b){
		if(a == b)
				return;
		unsigned int mid = (a+b)>>1;
		//cout << a << ' ' << mid << ' ' << b << endl;
		if(goal > mid){
			if(r == NULL)
				r = new node();
			r->add_node(goal, mid+1, b);
		}else{
			if(l == NULL)
				l = new node();
			l->add_node(goal, a, mid);
		}
	}

	void log_special(unsigned int c = 1, int level = 0){
		int _level = level;
		while(_level--)
				cout << ' ';
		cout << c << endl;
		c<<=1;
		if(l != NULL)
			l->log_special(c, level+1);
		if(r != NULL)
			r->log_special(c+1, level+1);
	}

	void log_tree(int level = 0,unsigned int c = 1){
		c<<=1;
		if(l == NULL && level + 1 <= n)
			li.push_back(c);
		if(r == NULL && level+1 <= n)
			li.push_back(c+1);
		if(l != NULL && level+1 <= n)
			l->log_tree(level+1, c);
		if(r != NULL && level+1 <= n) 
			r->log_tree(level+1, c+1);
	}
};

node root;

int main(){
	int r;
	cin >> n >> r;
	unsigned int R;
	for(int i = 0; i < r; i++){
		cin >> R;
		int level = log2(R);
		root.add_node(R, 1<<level, (1<<(level+1)) - 1);		
	}
	root.log_tree();
	li.sort();
	for(auto it = li.begin(); it != li.end(); ){
		cout << *it ;
		cout << (++it == li.end()? "\n" : " "); 
	}
}
