#include <iostream>

using namespace std;

int Num_digits_rec(int, int);
void Num_digits(int);

int main() {

	int k, num, n = 0;
	cout << "Enter the number: ";
	cin >> num;
	cout << "Select a method for calculating the number of digits in a given number:" << endl << "1.No recursion" << endl << "2.Recursion" << endl;
	cin >> k;
	switch (k)
	{
	case 1: 
		Num_digits(num);
		break;
	case 2: 
		n = Num_digits_rec(num, n); 
		cout << "Number of digits in the entered number: " << n << endl;
		break;
	default: cout << "Incorrect calculation method selected"; return 1;
	}
	system("pause");
	return 0;

}

int Num_digits_rec(int num, int n) {
	n++;
	num /= 10;
	if (num == 0) return n;
	else return Num_digits_rec(num, n);
}

void Num_digits(int num) {
	int n = 0;
	if (num == 0) n = 1;
	for (int i = 0; num != 0; i++) {
		num /= 10;
		n++;
	}
	cout << "Number of digits in the entered number: " << n << endl;
}