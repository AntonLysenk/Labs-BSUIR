#pragma once
#include "automobile.h"

class Lorry : public Automobile {
	int loadCapacity;
	string bodyType;
public:
	Lorry() : Automobile(), loadCapacity(0), bodyType("") {}
	Lorry(string brand, string engineType, int enginePower, int weight, int mileage,
		int loadCapacity, string bodyType) : Automobile(brand, engineType, enginePower, weight, mileage),
		loadCapacity(loadCapacity), bodyType(bodyType) {}
	bool load(int) override;
	void print() override;

	friend istream& operator>>(istream& is, Lorry*);

	void setLoadCapacity(int);
	int getLoadCapacity();

	void setBodyType(string);
	string getBodyType();
};