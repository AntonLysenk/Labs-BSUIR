#include "main.h"

int main() {

	bool a = false, b = true;
	short choise = 0, length1 = 0;
	int n = 0, value1 = 0, value2 = 0;
	char* name2 = new char[128];
	Pairs pairs = {};
	Pair pair = {};

	cout << "Enter the number of pairs: ";
	cin >> length1;

	pairs.setLength(&pairs, length1);
	pairs.initPrs(&pairs, &pair);

	system("cls");

	while (b) {
		cout << "1. Set value" << endl;
		cout << "2. Get value" << endl;
		cout << "3. Print pairs" << endl;
		cout << "4. Exit" << endl;
		cin >> choise;
		switch (choise) {
		case 1:
			cout << "Enter the name: ";
			cin >> name2;
			cout << "Enter the value for pair: ";
			cin >> value1;
			a = pairs.setValue(&pairs, &pair, name2, value1);
			if (a)
				cout << "New pair added successfully!" << endl;
			else
				cout << "The value was changed successfully!" << endl;
			break;
		case 2:
			cout << "Enter the name of the pair: ";
			cin >> name2;
			a = pairs.getValue(&pairs, &pair, name2, value2);
			if (a) {
				cout << "The pair was found successfully!" << endl;
				cout << "Name: " << name2 << endl << "Value: " << value2 << endl;
			}
			else
				cout << "The pair not found!";
			break;
		case 3: printPairs(&pairs, &pair); break;
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
	pairs.delPrs(&pairs, &pair);
	return 0;

}

bool Pairs::getValue(Pairs* pairs, Pair* pair, char* name2, int& value) {

	bool a = true;

	char* name1 = nullptr;

	for (int i = 0; i <= pairs->count; i++) {
		int j = 0;
		name1 = pairs->prs[i].name;
		while (name2[j] || name1[j]) {
			if (name2[j] != name1[j]) {
				a = false;
				break;
			}
			j++;
		}
		if (a) {
			value = pairs->prs[i].value;
			return a;
		}
		a = true;
	}
	return a;
}

bool Pairs::setValue(Pairs* pairs, Pair* pair, char* name2, int value) {

	bool a = true;
	int i = 0, j = 0, k = 0;
	char* name1 = nullptr;

	for (i = 0; i <= pairs->count; i++) {
		name1 = pairs->prs[i].name;
		if (name1)
			while (name2[j] || name1[j]) {
				if (name2[j] != name1[j]) {
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
		pairs->prs[i].value = value;
		return false;
	}
	else {
		for (k = 0; name2[k]; k++)
			pairs->prs[pairs->count].name[k] = name2[k];
		pairs->prs[pairs->count].name[k] = '\0';
		pairs->prs[pairs->count].value = value;
		pairs->count++;
		return true;
	}
}

void printPairs(Pairs* pairs, Pair* pair) {
	for (int i = 0; i < pairs->count; i++) {
		cout << i + 1 << " pair: " << endl;
		cout << setw(5) << "Name: " << pairs->prs[i].name << endl;
		cout << setw(5) << "Value: " << pairs->prs[i].value << endl;
	}
}

void Pairs::initPrs(Pairs* pairs, Pair* pair) {
	pairs->prs = new Pair[pairs->getLength(pairs)];
}

void Pairs::delPrs(Pairs* pairs, Pair* pair) {
		delete[] pairs->prs;
		pairs->prs = nullptr;
}