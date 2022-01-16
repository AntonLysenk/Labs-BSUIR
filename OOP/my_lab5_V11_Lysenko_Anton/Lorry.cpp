#include "lorry.h"

bool Lorry::load(int mass) {
	if (mass < getLoadCapacity()) {
		cout << "Lorry is not full, lorry can be loaded " << getLoadCapacity() - mass << " kg" << endl;
		return true;
	} 
	else if (mass == getLoadCapacity()) {
		cout << "Lorry is full!" << endl;
		return true;
	}
	else if (mass > getLoadCapacity()) {
		cout << "Lorry is overloaded, unload " << mass - getLoadCapacity() << " kg" << endl;
		return false;
	}
	return false;
}

void Lorry::print() {
	cout << "---------------------Lorry------------------------------" << endl;
	cout << "Brand - " << getBrand() << endl;
	cout << "Type of Engine - " << getEngineType() << endl;
	cout << "Power - " << getEnginePower() << endl;
	cout << "Weight - " << getWeight() << endl;
	cout << "Mileage - " << getMileage() << endl;
	cout << "Load capacity - " << getLoadCapacity() << endl;
	cout << "Type of Body - " << getBodyType() << endl;
	cout << endl;
}

istream& operator>>(istream& is, Lorry* lorry) {
	string brand;
	string engineType;
	int enginePower;
	int weight;
	int mileage;
	int loadCapacity;
	string bodyType;
	cout << "Enter brand: ";
	is >> brand;
	lorry->setBrand(brand);
	cout << "Enter engine type: ";
	is >> engineType;
	lorry->setEngineType(engineType);
	cout << "Enter engine power: ";
	is >> enginePower;
	lorry->setEnginePower(enginePower);
	cout << "Enter weight: ";
	is >> weight;
	lorry->setWeight(weight);
	cout << "Enter mileage: ";
	is >> mileage;
	lorry->setMileage(mileage);
	cout << "Enter load capacity: ";
	is >> loadCapacity;
	lorry->setLoadCapacity(loadCapacity);
	cout << "Enter body type: ";
	is >> bodyType;
	lorry->setBodyType(bodyType);
	cout << endl;
	return is;
}

void Lorry::setLoadCapacity(int capacity) {
	loadCapacity = capacity;
}
int Lorry::getLoadCapacity() {
	return loadCapacity;
}
void Lorry::setBodyType(string body) {
	bodyType = body;
}
string Lorry::getBodyType() {
	return bodyType;
}