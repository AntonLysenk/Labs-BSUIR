#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

struct Pair {
	char name[21];	//���
	int value;		//��������
};

class Pairs {
	Pair* prs;	//������ ���
	int length;	//������ �������
	int count;	//���������� ��������� ��� � �������
	friend void printPairs(Pairs*, Pair*);
public: 
	  Pairs();
	  Pairs(int, int);
	  Pairs(const Pairs&);
	  ~Pairs();
	  int getCount(Pairs*) { return count; }
	  void inkCount(Pairs*) { count++; }
	  int getLength(Pairs*) { return length; }
	  void setLength(int a) { length = a; }
	  bool getValue(Pairs*, Pair*, char*, int&);
	  bool setValue(Pairs*, Pair*, char*, int);
};
