#include "car.h"

bool Car::load(int passengers) {
	if (passengers < getNumberOfSeats()) {
		cout << "There are " << getNumberOfSeats() - passengers << " free seats in the car" << endl;
		return true;
	} 
	else if (passengers == getNumberOfSeats()) {
		cout << "Car is full!" << endl;
		return true;
	} 
	else if (passengers > getNumberOfSeats()) {
		cout << "Car is overfull for " << passengers - getNumberOfSeats() << " passengers" << endl;
		return false;
	}
	return false;
}

void Car::print() {
	cout << "---------------------Car--------------------------------" << endl;
	cout << "Brand - " << getBrand() << endl;
	cout << "Type of Engine - " << getEngineType() << endl;
	cout << "Power - " << getEnginePower() << endl;
	cout << "Weight - " << getWeight() << endl;
	cout << "Mileage - " << getMileage() << endl;
	cout << "Fuel on 100 km - " << getFuelConsumption() << endl;
	cout << "Time to 100 km/h - " << getAccelerationTime() << endl;
	cout << "Counter Passenger Places - " << getNumberOfSeats() << endl;
	cout << endl;
}

istream& operator>>(istream& is, Car* car) {
	string brand;
	string engineType;
	int enginePower;
	int weight;
	int mileage;
	int fuelConsumption;
	int accelerationTime;
	int numberOfSeats;
	cout << "Enter brand: ";
	is >> brand;
	car->setBrand(brand);
	cout << "Enter engine type: ";
	is >> engineType;
	car->setEngineType(engineType);
	cout << "Enter engine power: ";
	is >> enginePower;
	car->setEnginePower(enginePower);
	cout << "Enter weight: ";
	is >> weight;
	car->setWeight(weight);
	cout << "Enter mileage: ";
	is >> mileage;
	car->setMileage(mileage);
	cout << "Enter fuel consumption: ";
	is >> fuelConsumption;
	car->setFuelConsumption(fuelConsumption);
	cout << "Enter acceleration time: ";
	is >> accelerationTime;
	car->setAccelerationTime(accelerationTime);
	cout << "Enter number of seats: ";
	is >> numberOfSeats;
	car->setNumberOfSeats(numberOfSeats);
	cout << endl;
	return is;
}

void Car::setFuelConsumption(int fuel) {
	fuelConsumption = fuel;
}
int Car::getFuelConsumption() {
	return fuelConsumption;
}

void Car::setAccelerationTime(int time) {
	accelerationTime = time;
}
int Car::getAccelerationTime() {
	return accelerationTime;
}

void Car::setNumberOfSeats(int seats) {
	numberOfSeats = seats;
}
int Car::getNumberOfSeats() {
	return numberOfSeats;
}