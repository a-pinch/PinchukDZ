#include "List.h"
#include <iostream>

using namespace std;

//резервируем место под статическое поле
int List::junk;

List& List::push_front(int data){
	Node *node = new Node;
	if (node == nullptr){
		throw 3;	// can't create node
	}
	node->data = data;
	node->next = first;
	first = node;
	++size;
	return *this;
}

List& List::pop_front(){
	if (first == nullptr){
		throw 1;    //empty stack
	}

	Node *tmp = first;
	first = first->next;
	delete tmp;
	--size;
	
	return *this;
}

int& List::operator[](size_t index){
	if (index >= size){
		throw 2;    // index out of bouds
	//	cout << "ERROR";
	//	return junk;
	}

	Node *tmp = first;
	for (size_t i = 0; i<index; i++){
		tmp = tmp->next;
	}
	return tmp->data;
}

List::~List(){
	while (size > 0){
		pop_front();
	}
}