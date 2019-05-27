
#ifndef _stack_h_
#define _stack_h_
#include <vector>
#include <iostream>

#include <linkedlist.h> //custom ; ds/linkedlist.h

//Linked list implementation
class lstack {
	list container;
	int items;
	int limit;
	public:
	lstack(int size) : limit {size} , items{0} {}

	lstack(const lstack & ) = delete;
	lstack & operator= (const lstack & ) = delete;

	bool empty();
	bool full() const;
	void push(int d);
	void pop();
	int top();
	void print();
};

bool lstack::empty() {
	return container.empty();
}

bool lstack::full() const {
	return items == limit;
}

void lstack::push(int d) {
	if(full()) return;
	++items;
	container.push_front(d);
}

void lstack::pop() {
	if(empty()) return;
	--items;
	container.pop_front();
}

int lstack::top() {
	return container.front();
}

void lstack::print() {
	container.print();
}




//vector implementation
class vstack {
	std::vector<int> arr;
	int _top;
	public:
	vstack(int size) : _top { -1 } , arr { std::vector<int> (size,0) } {}
	vstack(const vstack & ) = delete;
	vstack & operator= ( const vstack & ) = delete;

	bool empty() const;
	bool full() const;
	void push(int d);
	void pop();
	int top();
	void print();
};


bool vstack::empty() const {
	return _top == -1;
}

bool vstack::full() const {
	return arr.size() == _top+1;
}

void vstack::push(int d) {
	if(full()) return;
	arr[++_top]= d;
}

void vstack::pop() {
	if(empty()) return;
	--_top;
}

int vstack::top() {
	if(empty()) return -1;
	return arr[_top];
}

void vstack::print() {
	std::cout << "top -> ";
	for(int i = _top; i >= 0; --i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

#endif
