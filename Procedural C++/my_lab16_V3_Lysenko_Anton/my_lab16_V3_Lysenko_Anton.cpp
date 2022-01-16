#include <iostream>
#include <iomanip>

using namespace std;

struct stack {
	int data;
	stack* next;
}*head;

struct Tree {
	int data;
	Tree* left;
	Tree* right;
}*Root;

int Pop(stack**);
void QuickSort(int*, int);
void Push(stack**, int);
Tree* AddTree(int, int, int*);
void PreOrder(Tree*);
void PostOrder(Tree*);
void InOrder(Tree*);
int ListCount(Tree*);
void DeleteTree(Tree*);

int main() {
	int n, result, k;
	cout << "Enter the number of tree elements: ";
	cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter " << i + 1 << " element: ";
		cin >> array[i];
	}
	cout << "Unsorted array: ";
	for (int i = 0; i < n; i++) {
		cout << array[i] << setw(5);
	}
	cout << endl;
	QuickSort(array, n);
	cout << "Sorted array: ";
	for (int i = 0; i < n; i++) {
		cout << array[i] << setw(5);
	}
	Root = AddTree(0, n - 1, array);
	cout << endl << "Choose a way to crawl the tree: " << endl << "1.Direct bypass" << endl << "2.Reverse crawl" << endl << "3.Symmetric traversal" << endl;
	cin >> k;
	switch (k) {
		case 1: PreOrder(Root); break;
		case 2: PostOrder(Root); break;
		case 3: InOrder(Root); break;
		default : cout << "Error!";
	}
	result = ListCount(Root);
	cout << endl;
	cout << "Number of leaves: " << result << endl;
	delete[] array;
	DeleteTree(Root);
	return 0;
}

void QuickSort(int array[], int n) {
	int base, left, right, i, j;
	base = left = right = i = j = 0;
	Push(&head, n - 1);
	Push(&head, 0);
	while (head != NULL) {
		left = Pop(&head);
		right = Pop(&head);
		if (((right - left) == 1) && (array[left] > array[right]))
			swap(array[left], array[right]);
		else {
			base = array[(left + right) / 2];
			i = left;
			j = right;
			while (i <= j) {
				while (base > array[i])
					i++;
				while (base < array[j])
					j--;
				if (i <= j)
					swap(array[i++], array[j--]);
			}
		}
		if (j > left) {
			Push(&head, j);
			Push(&head, left);
		}
		if (i < right) {
			Push(&head, right);
			Push(&head, i);
		}
	}
}

void Push(stack** head, int data) {
	stack* p = new stack;
	p->data = data;
	p->next = *head;
	*head = p;
}

int Pop(stack** head) {
	int data = (*head)->data;
	stack* t = new stack;
	t = *head;
	*head = (*head)->next;
	delete t;
	return data;
}

Tree* AddTree(int L, int R, int* array) {
	Tree* tNode;
	int mid;
	if (L > R) return NULL;
	mid = (L + R) / 2;
	tNode = new Tree;
	tNode->data = array[mid];
	tNode->left = AddTree(L, mid - 1, array);
	tNode->right = AddTree(mid + 1, R, array);
	return tNode;
}

void PreOrder(Tree* Root) {
	if (Root != NULL) {
		cout << Root->data << setw(5);
		PreOrder(Root->left);
		PreOrder(Root->right);
	}
}

void PostOrder(Tree* Root) {
	if (Root != NULL) {
		PostOrder(Root->left);
		PostOrder(Root->right);
		cout << Root->data << setw(5);
	}
}

void InOrder(Tree* Root) {
	if (Root != NULL) {
		InOrder(Root->left);
		cout << Root->data << setw(5);
		InOrder(Root->right);
	}
}

int ListCount(Tree* Root) {
	int result;
	if (Root == NULL) {
		result = 0;
	}
	else if ((Root->left == NULL) && (Root->right == NULL)) {
		result = 1;
	}

	else {
		result = ListCount(Root->left) + ListCount(Root->right);
	}
	return result;
}

void DeleteTree(Tree* Root) {
	if (Root != NULL) {
		DeleteTree(Root->left);
		DeleteTree(Root->right);
		delete Root;
	}
}