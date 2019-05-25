#ifndef _linkedlist_h_
#define _linkedlist_h_
#include <iostream>

struct lnode {
	int data;
	lnode * next;
	lnode(int d) : data {d}, next {nullptr} {}
};

class list {
	lnode * root;
	
	lnode * get_node(int d) { return new lnode(d); }

	public:
	list() : root {nullptr} {}
	~list() { clear(); }

	

	list(const list & ) = delete;
	list & operator=(const list &) = delete;

	list(list&& l) { 
		root = l.root;
		l.root = nullptr;
	}

	list & operator=(list&& l) {
		root = l.root;
		l.root = nullptr;
		return *this;
	}

	void push_back(int d);
	void push_front(int d);
	void push_pos(int d, int pos);
	void push_after(lnode * node, int d);
	void pop_back();
	void pop_front();
	void pop_pos(int pos);
	void pop_after(lnode * node);
	int front();
	int back();
   	bool find(int key);
	lnode * find_node(int key);
	bool empty();
	void print();
	void clear();
};


void list::push_back(int d) {
	if(!root) root = get_node(d);
	else {
		lnode * t = root;
		while(t->next) t = t->next;
		t->next = get_node(d);
	}
}

void list::push_front(int d) {
	if(!root) root = get_node(d);
	else {
		lnode * t = get_node(d);
		t->next = root;
		root = t;
	}
}

void list::push_pos(int d, int pos) {
	if(pos < 0) return;
	if(!root) {
		if(pos == 0) root = get_node(d);
		return;
	}
	if(pos == 0) {
		lnode * nn = get_node(d);
		nn->next = root;
		root = nn;
		return;
	}
	lnode * t = root;
	for(int i = 1; i < pos; ++i) {
		t = t->next;
		if(!t) return;
	}
	push_after(t,d);
}

void list::push_after(lnode * node, int d) {
	if(!node) return;
	lnode * t = get_node(d);
	t->next = node->next;
	node->next = t;
}

void list::pop_back() {
	if(!root) return;
	if(!root->next) {
		delete root;
		root = nullptr;
		return;
	}
	lnode * t = root;
	while(t->next->next)
		t = t->next;
	delete t->next;
	t->next = nullptr;
}

void list::pop_front() {
	if(!root) return;
	lnode * t = root;
	root = root->next;
	delete t;
}

void list::pop_pos(int pos) {
	if(pos < 0) return;
	if(!root) return;
	if(pos == 0) {
		pop_front();
		return;
	}
	lnode * t = root;
	for(int i = 1; i < pos; ++i) {
		t = t->next;
		if(!t) return;
	}
	pop_after(t);
}

void list::pop_after(lnode * node) {
	if(!node) return;
	lnode * t = node->next;
	node->next = t->next;
	delete t;
}

int list::front() {
	if(root) return root->data;
	else return -1;
}

int list::back() {
	if(!root) return -1;
	lnode * t = root;
	while(t->next) t = t->next;
	return t->data;
}

bool list::find(int key) {
	return find_node(key);
}

lnode * list::find_node(int key) {
	lnode * t = root;
	while(t) {
		if(t->data == key) return t;
		t = t->next;
	}
	return nullptr;
}

bool list::empty() {
	return !root;
}

void list::print() {
	std::cout << "list : ";
	lnode * t = root;
	while(t) {
		std::cout << t->data << " ";
		t = t->next;
	}
	std::cout << std::endl;
}

void list::clear() {
	while(root) {
		lnode * t = root;
		root = root->next;
		delete t;
	}
}

#endif
