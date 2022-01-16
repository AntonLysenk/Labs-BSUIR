#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

#define MAX_PAIRS 100

struct Pair {
	char* name;	//���
	int value;	//��������
};

struct Pairs {
	Pair par[MAX_PAIRS];  //������ ���
	int count;			  //���������� ��� � �������
};

bool getValue(Pairs*, Pair*, char*, int&);
bool setValue(Pairs*, Pair*, char*, int);
void printPairs(Pairs*, Pair*);
