#ifndef _tree_h_
#define _tree_h_
#include <iostream>
#include <queue>

struct tnode {
	int data;
	tnode * left;
	tnode * right;
	tnode(int d) : data {d}, left{nullptr}, right{nullptr} {}
};

//Common Functions ; only used tnode class
inline tnode * get_node(int d) { return new tnode(d); }
void inorder(tnode * root);
void preorder(tnode * root);
void postorder(tnode * root);
void levelorder(tnode * root);
void zigzagorder(tnode * root);
void delete_tree(tnode * root);

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

	void add_node(int d);
	void clear() { delete_tree(root); }
};

//Implementation
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
		std::cout << root->>data << " ";
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
	
}

void delete_tree(tnode * root) {
	if(!root) return;
	delete_tree(root->left);
	delete_tree(root->right);
	delete root;
}
#endif
