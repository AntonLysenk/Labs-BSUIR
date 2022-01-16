#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

#define MAX_PAIRS 100

struct Pair {
	char* name;	//имя
	int value;	//значение
};

struct Pairs {
	Pair par[MAX_PAIRS];  //массив пар
	int count;			  //количество пар в массиве
};

bool getValue(Pairs*, Pair*, char*, int&);
bool setValue(Pairs*, Pair*, char*, int);
void printPairs(Pairs*, Pair*);
