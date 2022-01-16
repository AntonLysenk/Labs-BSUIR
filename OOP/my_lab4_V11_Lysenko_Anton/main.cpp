#include "main.h"

int main() {

	bool a = false, b = true;
	short choise = 0;
	int n = 0, value1 = 0, value2 = 0, length = 0;
	char* name2 = new char[128];

	cout << "Enter the number of pairs: ";
	cin >> length;

	Pairs pairs(length, 0);
	Pair pair;
	system("cls");

	while (b) {
		cout << "1. Set value" << endl;
		cout << "2. Get value" << endl;
		cout << "3. Print pairs" << endl;
		cout << "4. Exit" << endl;
		cin >> choise;
		switch (choise) {
		case 1:
			Pair newPair;
			cin >> newPair;
			a = pairs.setValue(pairs, pair, newPair);
			if (a)
				cout << "New pair added successfully!" << endl;
			else
				cout << "The value was changed successfully!" << endl;
			break;
		case 2:
			cout << "Enter the name of the pair: ";
			cin >> name2;
			a = pairs.getValue(pairs, pair, name2, value2);
			if (a) {
				cout << "The pair was found successfully!" << endl;
				cout << "Name: " << name2 << endl << "Value: " << value2 << endl;
			}
			else
				cout << "The pair not found!";
			break;
		case 3: cout << pairs;;
			break;
		case 4: cout << "Are you sure you want to finish the program?" << endl;
			cout << "0.Yes" << endl;
			cout << "1.No" << endl;
			cin >> b;
			break;
		default: cout << "Please make your choise according to the menu" << endl; break;
		}
		system("pause");
		system("cls");
	}
	delete[] name2;
	name2 = nullptr;

	return 0;
}

bool Pairs::getValue(Pairs& pairs, Pair& pair, char* name2, int& value) {

	bool a = true;
	char* name1 = nullptr;

	for (int i = 0; i <= pairs.count; i++) {
		int j = 0;
		a = true;
		name1 = pairs.prs[i].name;
		while (name2[j] || name1[j]) {
			if (name2[j] != name1[j]) {
				a = false;
				break;
			}
			j++;
		}
		if (a) {
			value = pairs.prs[i].value;
			return a;
		}
	}
	return a;
}

bool Pairs::setValue(Pairs& pairs, Pair& pair, Pair& newPair) {

	bool a = true;
	int i = 0, j = 0, k = 0;
	char* name1 = nullptr;

	for (i = 0; i <= pairs.count; i++) {
		name1 = pairs.prs[i].name;
		if (name1)
			while (newPair.name[j] || name1[j]) {
				if (newPair.name[j] != name1[j]) {
					a = false;
					break;
				}
				else
					a = true;
				j++;
			}
		else
			a = false;
		if (a)
			break;
	}
	if (a) {
		pairs.prs[i] = newPair.value;
		return false;
	}
	else {
		pairs += newPair;
		return true;
	}
}

Pairs& Pairs::operator=(const Pairs& newPairs) {
	for (int i = 0; (i < newPairs.count) && (i < this->length); i++)
		this->prs[i] = newPairs.prs[i];
	return *this;
}

Pairs& Pairs::operator+=(const Pairs& newPairs) {
	for (int i = this->count, j = 0; (i < this->length) && (j < newPairs.count); i++, j++)
		this->prs[i] = newPairs.prs[j];
	return *this;
}

Pairs& Pairs::operator+=(const Pair& newPair) {
	strcpy_s(this->prs[this->count].name, newPair.name);
	this->prs[this->count].value = newPair.value;
	this->count++;
	return *this;
}

char* Pairs::operator[](int value) {
	for (int i = 0; i < this->count; i++)
		if (this->prs[i].value == value)
			return this->prs[i].name;
	return nullptr;
}

int Pairs::operator[](const char* name) {
	for (int i = 0; i < this->count; i++)
		if (!strcmp(this->prs[i].name, name))
			return this->prs[i].value;
	return -1;
}

ostream& operator<<(ostream& os, const Pairs& pairs) {
	for (int i = 0; i < pairs.count; i++) {
		os << i + 1 << " pair: " << endl;
		os << setw(5) << "Name: " << pairs.prs[i].name << endl;
		os << setw(5) << "Value: " << pairs.prs[i].value << endl;
	}
	return os;
}

Pair& Pair::operator=(int value) {
	this->value = value;
	return *this;
}

Pair& Pair::operator=(const char* name) {
	strcpy_s(this->name, name);
	return *this;
}

istream& operator>>(istream& is, Pair& newPair) {
	cout << "Enter the name: ";
	is >> newPair.name;
	cout << "Enter the value for pair: ";
	is >> newPair.value;
	return is;
}

ostream& operator<<(ostream& os, Pair& pair) {
	//os << i + 1 << " pair: " << endl;
	os << setw(5) << "Name: " << pair.name << endl;
	os << setw(5) << "Value: " << pair.value << endl;
	return os;
}