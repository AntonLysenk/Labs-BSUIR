#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

//#define MAX_PAIRS 100

struct Pair {
	char name[21];	//���
	int value;		//��������
};

class Pairs {
	Pair* prs;	//������ ���
	int length;	//������ �������
	int count;	//���������� ��������� ��� � �������
	friend void printPairs(Pairs*, Pair*);
public: int getCount(Pairs*) { return count; }
		void inkCount(Pairs*) { count++; }
		int getLength(Pairs*) { return length; }
		void setLength(Pairs*, int a) { length = a; }
		bool getValue(Pairs*, Pair*, char*, int&);
		bool setValue(Pairs*, Pair*, char*, int);
		void initPrs(Pairs*, Pair*);
		void delPrs(Pairs*, Pair*);
};