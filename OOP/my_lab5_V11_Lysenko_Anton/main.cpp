#include "main.h"

int main() {

	Automobile** autobase = new Automobile*[3];
	short k = 0;
	bool flag = true;
	int passengers = 0, mass = 0;
	Car* car = new Car();
	Lorry* lorry = new Lorry();
	Bus* bus = new Bus();

	cout << "Fill in the information about the vehicles of the fleet: " << endl;
	cout << "---------------------Car--------------------------------" << endl;
	cin >> car;
	cout << "---------------------Lorry------------------------------" << endl;
	cin >> lorry;
	cout << "---------------------Bus--------------------------------" << endl;
	cin >> bus;
	system("pause");
	system("cls");

	while (flag) {

		menuFlight();
		cin >> k;

		switch (k) {
		case 1:
			cout << "Enter the number of passengers: ";
			cin >> passengers;
			if (car->load(passengers)) {
				cout << "The landing was successful!" << endl;
				cout << "Ready to ship!" << endl;
			}
			else {
				cout << "Problems with landing!" << endl;
				cout << "The flight cannot be dispatched!" << endl;
			}
			break;
		case 2:
			cout << "Enter the weight of the cargo: ";
			cin >> mass;
			if (lorry->load(mass)) {
				cout << "Cargo loading was successful!" << endl;
				cout << "Ready to ship!" << endl;
			}
			else {
				cout << "Problems with loading!" << endl;
				cout << "The flight cannot be dispatched!" << endl;
			}
			break;
		case 3:
			cout << "Enter the number of passengers: ";
			cin >> passengers;
			if (bus->load(passengers)) {
				cout << "The landing was successful!" << endl;
				cout << "Ready to ship!" << endl;
			}
			else {
				cout << "Problems with landing!" << endl;
				cout << "The flight cannot be dispatched!" << endl;
			}
			break;
		case 4:
			car->print();
			break;
		case 5:
			lorry->print();
			break;
		case 6:
			bus->print();
			break;
		case 7: flag = false;
			break;
		default: 
			cout << "Error!" << endl;
			break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}

void menuFlight() {
	cout << "Choose the type of car to send on the flight: " << endl;
	cout << "1.Passenger car" << endl;
	cout << "2.Lorry" << endl;
	cout << "3.Bus" << endl;
	cout << "4.Print information about passenger car" << endl;
	cout << "5.Print information about lorry" << endl;
	cout << "6.Print information about bus" << endl;
	cout << "7.End the working day" << endl;
}