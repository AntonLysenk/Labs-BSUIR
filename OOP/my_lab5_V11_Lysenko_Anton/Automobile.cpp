#include "automobile.h"

void Automobile::setBrand(string bran) {
	brand = bran;
}
string Automobile::getBrand() {
	return brand;
}

void Automobile::setEngineType(string type) {
	engineType = type;
}
string Automobile::getEngineType() {
	return engineType;
}

void Automobile::setEnginePower(int power) {
	enginePower = power;
}
int Automobile::getEnginePower() {
	return enginePower;
}

void Automobile::setWeight(int weigh) {
	weight = weigh;
}
int Automobile::getWeight() {
	return weight;
}

void Automobile::setMileage(int mileag) {
	mileage = mileag;
}
int Automobile::getMileage() {
	return mileage;
}