#ifndef _tree_h_
#define _tree_h_
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <initializer_list>
#include <limits>
using std::vector;
using std::queue;
using std::stack;

struct tnode {
	int data;
	tnode * left;
	tnode * right;
	tnode(int d) : data {d}, left{nullptr}, right{nullptr} {}
};

//Common Functions ; which uses tnode class
inline tnode * get_node(int d) { return new tnode(d); }
inline bool leaf(tnode * p) { return p and !p->left and !p->right; }
void inorder(tnode * root);
void preorder(tnode * root);
void postorder(tnode * root);
void levelorder(tnode * root);
void zigzagorder(tnode * root);
void delete_tree(tnode * root);
int height(tnode * root);
int max_element(tnode * root);
int size(tnode * root);

struct binarytree {
	tnode * root;

	binarytree() : root {nullptr} {}
	void clear() { delete_tree(root); }

};

struct bst {
	tnode * root;

	bst() : root { nullptr } {};
	bst(const vector<int> & items) : root {nullptr} {
		for(auto x: items) add_node(x);
	}
	bst(const std::initializer_list<int> &items) : root {nullptr} {
		for(auto x: items) add_node(x);
	}

	void add_node(int d);
	void clear() { delete_tree(root); }
	int max_element();
};

//Implementation
int size(tnode * root) {
	if(!root) return 0;
	return size(root->left) + size(root->right) + 1;
}

int max_element(tnode * root) {
	int max_elem = std::numeric_limits<int>::min();
	if(root) {
		max_elem = std::max(max_elem,root->data);
		max_elem = std::max(max_elem,max_element(root->left));
		max_elem = std::max(max_elem,max_element(root->right));
	}
	return max_elem;
}

int bst::max_element() {
	if(!root) return -1;
	tnode * t = root;
	while(t->right) t = t->right;
	return t->data;
}

int height(tnode * root) {
	if(!root) return 0;
	if(leaf(root)) return 0;
	return std::max(height(root->left),height(root->right)) + 1;
}

void bst::add_node(int d) {
	if(!root) {
		root = get_node(d);
		return;
	}
	tnode * t = root;
	while(1) {
		if(t->data < d) {
		   if(!t->right) break;
		   else t = t->right;
		}
		if(t->data > d) {
			if(!t->left) break;
			else t = t->left;
		}
		if(t->data == d)
			break;
	}
	if(t->data < d and !t->right) t->right = get_node(d);
	if(t->data > d and !t->left) t->left = get_node(d);
}


void inorder(tnode * root) {
	if(root) {
		inorder(root->left);
		std::cout << root->data << " ";
		inorder(root->right);
	}
}

void preorder(tnode * root) {
	if(root) {
		std::cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(tnode * root) {
	if(root) {
		postorder(root->left);
		postorder(root->right);
		std::cout << root->data << " ";
	}
}

void levelorder(tnode * root) {
	std::queue<tnode *> q;
	q.push(root);
	while(!q.empty()) {
		root = q.front(); q.pop();
		std::cout << root->data << " ";
		if(root->left) q.push(root->left);
		if(root->right) q.push(root->right);
	}
}

void zigzagorder(tnode * root) {
	queue<tnode*> src;
	stack<tnode*> dest;
	src.push(root);
	src.push(nullptr);
	while(!src.empty()) {
		root = src.front(); src.pop();
		if(!root) {
			if(!dest.empty()) {
				while(!dest.empty()) {
					src.push(dest.top());
					dest.pop();
				}
				src.push(nullptr);
			}
		}
		else {
			std::cout << root->data << " ";
			if(root->left) dest.push(root->left);
			if(root->right) dest.push(root->right);
		}
	}
}

void delete_tree(tnode * root) {
	if(!root) return;
	delete_tree(root->left);
	delete_tree(root->right);
	delete root;
}
#endif
