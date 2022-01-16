#include "bus.h"

bool Bus::load(int passengers) {
	if (passengers < getNumberOfSeats()) {
		cout << "Bus is not full, he has " << getNumberOfSeats() - passengers << " seating places and " << getStandingPlaces() << " standing places" << endl;
		return true;
	} 
	else if (passengers == getNumberOfSeats()) {
		cout << "Bus is not full(not seat places), he has " << getStandingPlaces() << " standing places" << endl;
		return true;
	}	
	else if (passengers > getNumberOfSeats()) {
		cout << "Bus is not full(not seat places), he has  " << getStandingPlaces() - (passengers - getNumberOfSeats()) << " standing places" << endl;
		return true;
	}
	else if (passengers > (getNumberOfSeats() + getStandingPlaces())) {
		cout << "Bus is overfull for " << passengers - (getNumberOfSeats() + getStandingPlaces()) << " passengers" << endl;
		return false;
	}
	return false;
}

void Bus::print() {
	cout << "---------------------Bus--------------------------------" << endl;
	cout << "Brand - " << getBrand() << endl;
	cout << "Type of Engine - " << getEngineType() << endl;
	cout << "Power - " << getEnginePower() << endl;
	cout << "Weight - " << getWeight() << endl;
	cout << "Mileage - " << getMileage() << endl;
	cout << "Fuel on 100 km - " << getFuelConsumption() << endl;
	cout << "Time to 100 km/h - " << getAccelerationTime() << endl;
	cout << "Counter Passenger Places - " << getNumberOfSeats() << endl;
	cout << "Counter Stand Passenger Places - " << getStandingPlaces() << endl;
	cout << endl;
}

istream& operator>>(istream& is, Car* bus) {
	string brand;
	string engineType;
	int enginePower;
	int weight;
	int mileage;
	int fuelConsumption;
	int accelerationTime;
	int numberOfSeats;
	int standingPlaces;
	cout << "Enter brand: ";
	is >> brand;
	//bus->setBrand(brand);
	cout << "Enter engine type: ";
	is >> engineType;
	//bus->setEngineType(engineType);
	cout << "Enter engine power: ";
	is >> enginePower;
	//bus->setEnginePower(enginePower);
	cout << "Enter weight: ";
	is >> weight;
	//bus->setWeight(weight);
	cout << "Enter mileage: ";
	is >> mileage;
	//bus->setMileage(mileage);
	cout << "Enter fuel consumption: ";
	is >> fuelConsumption;
	//bus->setFuelConsumption(fuelConsumption);
	cout << "Enter acceleration time: ";
	is >> accelerationTime;
	//bus->setAccelerationTime(accelerationTime);
	cout << "Enter number of seats: ";
	is >> numberOfSeats;
	//bus->setNumberOfSeats(numberOfSeats);
	cout << "Enter number of standing places: ";
	is >> standingPlaces;
	//bus->setStandingPlaces(standingPlaces);
	cout << endl;
	return is;
}

void Bus::setStandingPlaces(int place) {
	standingPlaces = place;
}
int Bus::getStandingPlaces() {
	return standingPlaces;
}