#pragma once
#include "car.h"

class Bus : public Car {
	int standingPlaces;
public:
	Bus() : Car(), standingPlaces(0) {}
	Bus(string brand, string engineType, int enginePower, int weight, int mileage,
		int fuelConsumption, int accelerationTime, int numbersOfSeats,
		int standingPlaces) : Car(brand, engineType, enginePower, weight, mileage,
			fuelConsumption, accelerationTime, numbersOfSeats),
		standingPlaces(standingPlaces) {}

	bool load(int) override;
	void print() override;

	friend istream& operator>>(istream&, Car*);

	void setStandingPlaces(int);
	int getStandingPlaces();
};
