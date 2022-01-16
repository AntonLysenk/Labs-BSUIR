#include <iostream>

using namespace std;

struct stack {
	int data;
	stack* next;
}*head, *r_head;

void push(stack**, int);
void view(stack*);
void swap(stack**, stack**);

int main() {
	int size, info;
	stack* res;
	cout << "Enter the stack size: ";
	cin >> size;

	for (int i = 0; i < size; i++) {
		cout << "Enter " << i + 1 << " stack element: ";
		cin >> info;
		push(&head, info);
	}

	while (head != NULL) {
		push(&r_head, head->data);
		head = head->next;
	}

	swap(&head, &r_head);

	view(head);

	while (head != NULL) {
		res = head;
		head = head->next;
		delete res;
	}

	return 0;
}

void push(stack** head, int data) {
	stack* p = new stack;
	p->data = data;
	p->next = *head;
	*head = p;
}

void view(stack* head) {
	while (head != NULL) {
		cout << endl << head->data;
		head = head->next;
	}
}

void swap(stack** head, stack** r_head) {
	*head = *r_head;
}