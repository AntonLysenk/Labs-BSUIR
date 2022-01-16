#pragma once
#pragma once

#include <iostream>

using namespace std;

template <typename type>
struct Node {
	type inf;
	Node<type>* next;
};

template <typename type>
class Stack {
	Node<type>* head;
	Node<type>* tmp;
public:
	Stack() : head(nullptr), tmp(nullptr) {}
	~Stack() {
		if (!head->next)
			delete head;
		else {
			while (head->next) {
				tmp = head;
				head = head->next;
				delete tmp;
			}
			delete head;
		}
	}
	Node<type>* getTmp();
	void push(type inf);
	type top();
	type top(Node<type>* top);
	bool next();
	type pop();
	bool isEmpty();
	void show();
};

template <typename type>
Node<type>* Stack<type>::getTmp() {
	return tmp;
}

template <typename type>
void Stack<type>::push(type inf) {
	if (!head) {
		head = new Node <type>;
		head->inf = inf;
		head->next = nullptr;
		tmp = head;
	}
	else {
		Node<type>* add = new Node <type>;
		add->inf = inf;
		add->next = head;
		head = add;
		tmp = head;
	}
}

template <typename type>
type Stack<type>::top() {
	return head->inf;
}

template <typename type>
type Stack<type>::top(Node<type>* top) {
	return top->inf;
}

template <typename type>
bool Stack<type>::next() {
	tmp = tmp->next;
	if (!tmp) {
		cout << "The end of stack!" << endl;
		tmp = head;
		return false;
	}
	return true;
}

template <typename type>
type Stack<type>::pop() {
	if (!head) {
		cout << "Stack is empty!" << endl;
	}
	Node <type>* del = head;
	head = head->next;
	type ret = del->inf;
	delete del;
	return ret;
}

template <typename type>
bool Stack<type>::isEmpty() {
	if (head)
		return false;
	else
		return true;
}

template <typename type>
void Stack<type>::show() {
	if (!head)
		cout << "Stack is empty!" << endl;
	else {
		Node<type>* t = head;
		while (t) {
			cout << t->inf << endl;
			t = t->next;
		}
	}
}