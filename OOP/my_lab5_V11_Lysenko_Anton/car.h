#pragma once
#include "automobile.h"

class Car : public Automobile {
	int fuelConsumption;
	int accelerationTime;
	int numberOfSeats;
public:
	Car(string brand, string engineType, int enginePower, int weight, int mileage,
		int fuelConsumption, int accelerationTime, int numberOfSeats) : Automobile(brand, engineType, enginePower, weight, mileage),
		fuelConsumption(fuelConsumption), accelerationTime(accelerationTime), numberOfSeats(numberOfSeats) {}
	Car() : Automobile(), fuelConsumption(0), accelerationTime(0), numberOfSeats(0) {}
	bool load(int) override;
	void print() override;

	friend istream& operator>>(istream&, Car*);

	void setFuelConsumption(int);
	int getFuelConsumption();

	void setAccelerationTime(int);
	int getAccelerationTime();

	void setNumberOfSeats(int);
	int getNumberOfSeats();

};