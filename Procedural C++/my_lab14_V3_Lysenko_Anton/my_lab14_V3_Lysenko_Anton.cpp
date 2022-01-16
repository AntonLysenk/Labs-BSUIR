#include <iostream>

using namespace std;

struct Students {
	char Surname[15];
	char Group[10];
	int Birth;
}Student[7];

char ToUpper(char);
char ToLower(char);
void DoubleHash(Students*, Students, int, int);
void HashTable(Students*, int, int, int);
void ViewHashTable(Students*, int);
int HashFun1(int, int);
int HashFun2(int, int);
int Find(Students*, int, int, int, int);

int main() {
	int n;
	const int M = 20;
	const int SIMPLE = 13;
	const int N = 7;
	Students hashTable[M];
	for (int i = 0; i < N; i++) {
		cout << "Enter the last name of " << i + 1 << " student: ";
		cin >> Student[i].Surname;
		Student[i].Surname[0] = ToUpper(Student[i].Surname[0]);
		for (int j = 1; j < strlen(Student[i].Surname); j++)
			Student[i].Surname[j] = ToLower(Student[i].Surname[j]);
		cout << "Enter the group of " << i + 1 << " subscriber: ";
		cin >> Student[i].Group;
		cout << "Enter the birth of " << i + 1 << " subscriber: ";
		cin >> Student[i].Birth;
		cout << endl;
	}
	HashTable(hashTable, N, M, SIMPLE);
	return 0;
}

char ToUpper(char ch) {
	if (ch >= 'a' && ch <= 'z')
		return (char)(ch - 32);
	return ch;
}

char ToLower(char ch) {
	if (ch >= 'A' && ch <= 'Z')
		return (char)(ch + 32);
	return ch;
}

void DoubleHash(Students* hashTable, Students key, int M, int SIMPLE) {

	int index = HashFun1(key.Birth, M);

	if (hashTable[index].Birth != -1)
	{
		int index2 = HashFun2(key.Birth, SIMPLE);
		int i = 1;
		while (1)
		{
			int newIndex = (index + i * index2) % M;
			if (hashTable[newIndex].Birth == -1)
			{
				hashTable[newIndex] = key;
				break;
			}
			i++;
		}
	}
	else
		hashTable[index] = key;
}

void HashTable(Students* hashTable, int N, int M, int SIMPLE) {
	int find;
	for (int i = 0; i < M; i++)
		hashTable[i].Birth = -1;
	for (int i = 0; i < N; i++) {
		DoubleHash(hashTable, Student[i], M, SIMPLE);
	}
	cout << "Enter the search element: ";
	cin >> find;
	cout << endl;
	ViewHashTable(hashTable, M);
	Find(hashTable, N, M, SIMPLE, find);
}

void ViewHashTable(Students* hashTable, int M) {
	cout << "Hash-Table:" << endl;
	for (int i = 0; i < M; i++)
		cout << "hashTable[" << i << "]: " << hashTable[i].Birth << endl;
	cout << endl;
}

int HashFun1(int key, int M) {
	return (key % M);
}

int HashFun2(int key, int SIMPLE) {
	return (SIMPLE - (key % SIMPLE));
}

int Find(Students* hashTable, int N, int M, int SIMPLE, int find) {
	int index1 = HashFun1(find, M); 
	int index2 = HashFun2(find, SIMPLE); 
	int i = 0;
	while (i < M) {
		if (hashTable[index1].Birth == find) {
			cout << "Item found: " << endl << hashTable[index1].Surname << endl << hashTable[index1].Group << endl << hashTable[index1].Birth << endl;
			return 0;
		}
		index1 = (index1 + i * index2) % M;
		i++;
	}
	cout << "Item not found";
	return 1;
}

