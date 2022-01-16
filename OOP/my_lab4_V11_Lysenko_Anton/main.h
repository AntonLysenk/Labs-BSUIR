#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

struct Pair {
	char name[21];	
	int value;	
	Pair& operator=(int);
	Pair& operator=(const char*);
	friend istream& operator>>(istream& is, Pair&);
	friend ostream& operator<<(ostream& os, Pair&);
};

class Pairs {
	Pair* prs;	
	int length;	
	int count;	
public:
	Pairs() : length(0), count(0) { prs = new Pair; }
	Pairs(int length1, int count1) : length(length1), count(count1) { prs = new Pair[length]; }
	Pairs(const Pairs& pairs1) : length(0), count(0) {
		for (int i = 0; i < pairs1.count; i++)
			this->prs[i] = pairs1.prs[i];
	}
	~Pairs() {
		delete[] prs;
		prs = nullptr;
	}
	int getCount(Pairs*) { return count; }
	void inkCount(Pairs*) { count++; }
	int getLength(Pairs*) { return length; }
	void setLength(int a) { length = a; }
	bool getValue(Pairs&, Pair&, char*, int&);
	bool setValue(Pairs&, Pair&, Pair&);
	Pairs& operator=(const Pairs&);
	Pairs& operator+=(const Pairs&);
	Pairs& operator+=(const Pair&);
	char* operator[](int);
	int operator[](const char*);
	friend ostream& operator<<(ostream& os, const Pairs&);
};
