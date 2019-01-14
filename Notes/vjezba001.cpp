#include <iostream>

using namespace std;

struct BST{
	BST *left = nullptr, *right = nullptr;
	int number = NULL;
	BST(){}

	BST(int _number){
		number = _number;
	}
	void add(int n){
		if(number == NULL){
			number = n;
			return;
		}
		if(n > number){
			if(right == nullptr)
				right = new BST(n);
			else
				right->add(n);
		}else if(n < number){
			if(left == nullptr)
				left = new BST(n);
			else
				left->add(n);
		}
	}

	void log(int level = 0){
		for(int i = 0; i < level; i++)
			cout << ' ' << endl;
		cout << number << endl;
		if(left != nullptr)
			left->log();
		if(right != nullptr)
			right->log();
	}
};

int main(){
	BST bst;
	bst.add(5);	
	bst.add(2);
	bst.add(6);
	bst.add(3);
	bst.log();
}
