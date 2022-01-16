#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Automobile {
	string brand;
	string engineType;
	int enginePower;
	int weight;
	int mileage;
public:
	Automobile(string brand, string engineType, int enginePower, int weight, int mileage) : brand(brand),
		engineType(engineType), enginePower(enginePower), weight(weight), mileage(mileage) {}
	Automobile() : brand(""), engineType(""), enginePower(0), weight(0), mileage(0) {}
	virtual bool load(int) = 0;
	virtual void print() {}

	void setBrand(string);
	string getBrand();

	void setEngineType(string);
	string getEngineType();

	void setEnginePower(int);
	int getEnginePower();

	void setWeight(int);
	int getWeight();

	void setMileage(int);
	int getMileage();
};