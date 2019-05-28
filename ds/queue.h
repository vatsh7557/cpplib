#ifndef _queue_h_
#define _queue_h_
#include <iostream>
#include <vector>
//linked list implementation
struct qnode {
	int data;
	qnode * next;
	qnode(int d) : data {d}, next {nullptr} {}
};

class queue {
	qnode * front_;
	qnode * rear;
	int items;
	int limit;
	qnode * get_node(int d) { return new qnode(d); }
	public : 
	queue(int size) : limit { size}, front_ { nullptr},
		rear { nullptr } , items {0}
	{}

	bool full() ;
	bool empty() ;
	int size();
	int front();
	void push(int d);
	void pop();
	void print();
};
bool queue::full()  {
	return items >= limit;
}

bool queue::empty()  {
	return !items;
}

int queue::size() {
	return items;
}

int queue::front() {
	if(full()) return -1;
	return front_->data;
}

void queue::push(int d) {
	if(full()) return;
	if(!rear) {
		rear = front_ = get_node(d);
	}
	else {
		rear->next = get_node(d);
		rear = rear->next;
	}
	++items;
}

void queue::pop() {
	if(empty()) return;
	if(front_ == rear) {
		delete front_;
		front_ = rear = nullptr;
	}
	else {
		qnode * t = front_;
		front_ = front_->next;
		delete t;
	}
	--items;
}

void queue::print() {
	qnode * t = front_;
	while(t) {
		std::cout << t->data << " ";
		t = t->next;
	}
	std::cout << std::endl;
}

//Vector Implementation
class dqueue {
	std::vector<int> container; 
	int front_;
	int rear;
	int next_pos(int a) { return (a+1)%container.size(); }
	int prev_pos(int a) { return (a + container.size() - 1)%container.size();}
	public:
	dqueue(int size) : container { std::vector<int> (size+1,0) },
		front_ { 0 },
		rear { 0 } 
	{}

	bool full() ;
	bool empty() ;
	int size();
	int front();
	int back();
	void push_back(int d);
	void push_front(int d);
	void pop_back();
	void pop_front();
	void print();
};

int dqueue::size() {
	if(rear >= front_)
		return rear - front_;
	else
		return container.size() - front_ + rear;
}

bool dqueue::full() {
	return next_pos(rear) == front_;
}

bool dqueue::empty() {
	return rear == front_;
}

int dqueue::front() {
	if(empty()) return -1;
	return container[next_pos(front_)];
}

int dqueue::back() {
	if(empty()) return -1;
	return container[rear];
}

void dqueue::push_back(int d) {
	if(full()) return;
	rear = next_pos(rear);
	container[rear] = d;
}

void dqueue::push_front(int d) {
	if(full()) return;
	container[front_] = d;
	front_ = prev_pos(front_);
}

void dqueue::pop_back() {
	if(empty()) return;
	rear = prev_pos(rear);
}

void dqueue::pop_front() {
	if(empty()) return;
	front_ = next_pos(front_);
}

void dqueue::print() {
	for(int i = front_+1; i < container.size() or i <= rear; ++i)
		std::cout << container[i] << " ";
	if(rear < front_)
		for(int i = 0; i <= rear; ++i)
			std::cout << container[i] << " ";
	std::cout << std::endl;
}

#endif
