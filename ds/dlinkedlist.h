#ifndef _dlinkedlist_h_
#define _dlinkedlist_h_
#include <iostream>

struct dlnode {
	int data;
	dlnode * prev;
	dlnode * next;
	dlnode(int d) : data { d}, prev { nullptr } , next { nullptr} {}
};

class dlist {
	dlnode * head;
	dlnode * get_node(int d) { return new dlnode(d); }
	public:
	dlist() : head { nullptr} {}
	void push_back(int d);
	void push_front(int d);
	void push_pos(int d, int pos);
	void pop_back();
	void pop_front();
	void pop_pos(int pos);
	void print();
	void clear();
	bool empty();
	bool find(int key);
};

void dlist::push_back(int d) {
	if(!head) head = get_node(d);
	else {
		dlnode * t = head;
		while(t->next) t = t->next;
		dlnode * tmp = get_node(d);
		tmp->prev = t;
		t->next = tmp;
	}
}

void dlist::push_front(int d) {
	if(!head) head = get_node(d);
	else {
		dlnode * tmp = get_node(d);
		tmp->next = head;
		head->prev = tmp;
		head = tmp;
	}
}

void dlist::push_pos(int d, int pos) {
	if(pos < 0 ) return;
	if(!head) {
		if(pos == 0) head = get_node(d);
		return;
	}
	if(pos == 0) {
		push_front(d);
		return;
	}
	dlnode * t = head;
	for(int i = 1; i < pos; ++i) {
		t = t->next;
		if(!t) return;
	}
	dlnode * nn = get_node(d);
	dlnode * u = t->next;
	nn->prev = t;
	nn->next = u;
	t->next = nn;
	if(u) u->prev = nn;
}

void dlist::pop_back() {
	if(!head) return;
	if(!head->next) {
		pop_front();
		return;
	}
	dlnode * t = head;
	while(t->next->next) t = t->next;
	delete t->next;
	t->next = nullptr;
}

void dlist::pop_front() {
	if(!head) return;
	dlnode * t = head;
	head = head->next;
	delete t;
}

void dlist::pop_pos(int pos) {
	if(pos < 0) return;
	if(!head) return;
	if(pos == 0) {
		pop_front();
		return;
	}
	dlnode * t = head;
	for(int i = 1; i < pos; ++i) {
		t = t->next;
		if(!t) return;
	}
	dlnode * tmp = t->next;
	t->next = tmp->next;
	if(tmp->next) tmp->next->prev = t;
	delete tmp;
}

void dlist::print() {
	std::cout << "list: ";
	dlnode * t = head;
	while(t) {
		std::cout << t->data << " ";
		t = t->next;
	}
	std::cout << std::endl;
}

void dlist::clear() {
	while(head) {
		dlnode * t = head;
		head = head->next;
		delete t;
	}
}

bool dlist::empty() {
	return !head;
}

bool dlist::find(int key) {
	dlnode * t = head;
	while(t) {
		if(t->data == key) return true;
		t = t->next;
	}
	return false;
}

#endif
