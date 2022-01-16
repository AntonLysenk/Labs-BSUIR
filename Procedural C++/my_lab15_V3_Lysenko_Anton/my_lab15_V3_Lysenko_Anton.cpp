#include <iostream>

using namespace std;

struct list {
    int data;
    list* next;
    list* prev;
}*head, *tail, *head1, *tail1;

void Create(list**, list**, int);
void Push(list**, list**, int);
list* DeleteElem(list**);
void View(list*, list*);
void Find(list*, list*);

int main() {
    int n, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    Create(&head, &tail, 5);
    Create(&head1, &tail1, 5);
    for (int i = 0; i < n; i++) {
        cout << "Enter [" << i + 1 << "] list item: ";
        cin >> key;
        Push(&head, &tail, key);
    }
    DeleteElem(&head);
    cout << "Initial doubly linked list:" << endl;
    View(head, tail);
    cout << endl;
    Find(head, tail);
    if (head1->prev != NULL) {
        DeleteElem(&tail1);
        cout << "A list with duplicate elements: " << endl;
        View(head1, tail1);
        cout << endl;
    }
    cout << "Initial list with no duplicate elements: " << endl;
    View(head, tail);
    while (tail != NULL) {
        list* t = tail;
        tail = tail->prev;
        delete t;
    }
    while (head1 != NULL) {
        list* t = head1;
        head1 = head1->prev;
        delete t;
    }
    return 0;
}

void Create(list** head, list** tail, int key) {
   list* t = new list;
   t->data = key;
   t->next = NULL;
   t->prev = NULL;
   *head = *tail = t;
}

void Push(list** head, list** tail, int key) {
    list* t = new list;
    (*tail)->next = t;
    t->data = key;
    t->prev = *tail;
    *tail = t;
}

list* DeleteElem(list** res1) {
    list* t = *res1, *prev, *next;
    prev = (*res1)->prev;
    next = (*res1)->next;
    if (next != NULL)
        next->prev = prev;
    if (prev != NULL)
        prev->next = next;
    delete t;
    return prev;
}

void View(list* head, list* tail) {
    while (tail != NULL) {
        cout << tail->data << endl;
        tail = tail->prev;
    }
}

void Find(list* head, list* tail) {
    list* res, *res1;
    int tmp;
    res1 = res = tail;
    while (res != NULL) {
        tmp = res->data;
        res1 = res->prev;
        while (res1 != NULL) {
            if (res1->data == tmp) {
                Push(&head1, &tail1, tmp);
                res1 = DeleteElem(&res1);
            }
            if (res1 != NULL)
                res1 = res1->prev;
        }
        res = res->prev;
    }
}
