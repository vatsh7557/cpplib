#ifndef _circularlist_h_
#define _circularlist_h_
#include <iostream>

struct lnode {
	int data;
	lnode * next;
	lnode(int d) : data {d}, next {nullptr} {}
};

class clist {
	lnode * tail;
	lnode * get_node(int d) { return new lnode(d); }
	public:
	clist() : tail{nullptr} {}
	clist(const clist & ) = delete;
	clist & operator=(const clist &) = delete;

	int node_count();
	void print();
	void push_back(int d);
	void push_front(int d);
	void pop_back();
	void pop_front();
	int front();

};
	
int clist::node_count() {
	if(!tail) return 0;
	int count = 0;
	lnode * t = tail;
	do {
		++count;
		t = t->next;
	}while(t != tail);
	return count;
}

void clist::print() {
	std::cout << "List: ";
	if(tail) {
		lnode * t = tail->next;
		do {
			std::cout << t->data << " ";
			t = t->next;
		}while(t != tail->next);
	}
	std::cout << std::endl;
}

void clist::push_back(int d) {
	if(!tail) {
		tail = get_node(d);
		tail->next = tail;
	}
	else {
		lnode * nn = get_node(d);
		nn->next = tail->next;
		tail->next = nn;
		tail = nn;
	}
}

void clist::push_front(int d) {
	if(!tail) {
		tail = get_node(d);
		tail->next = tail;
	}
	else {
		lnode * nn = get_node(d);
		nn->next = tail->next;
		tail->next = nn;
	}
}

void clist::pop_back() {
	if(!tail) return;
	if(tail == tail->next) {
		delete tail;
		tail = nullptr;
		return;
	}
	lnode * t = tail->next;
	while(t->next != tail) t = t->next;
	t->next = tail->next;
	delete tail;
	tail = t;
}

void clist::pop_front() {
	if(!tail) return;
	if(tail == tail->next) {
		delete tail;
		tail = nullptr;
		return;
	}
	lnode * t = tail->next;
	tail->next = t->next;
	delete t;
}

int clist::front() {
	if(!tail) return -1;
	return tail->next->data;
}

#endif
