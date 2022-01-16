#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

//#define MAX_PAIRS 100

struct Pair {
	char name[21];	//имя
	int value;		//значение
};

class Pairs {
	Pair* prs;	//массив пар
	int length;	//размер массива
	int count;	//количество имеющихся пар в массиве
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