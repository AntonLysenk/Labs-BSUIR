#include "main.h"

int main()
{
	Trans trans;
	int k = 0;
	double param = 0;
	while (true)
	{
		try {
            cout << "1.Sin(x)" << endl;
            cout << "2.Cos(x)" << endl;
            cout << "3.Tan(x)" << endl;
            cout << "4.Asin(x)" << endl;
            cout << "5.Acos(x)" << endl;
            cout << "6.Atan(x)" << endl;
            cout << "7.Ln(x)" << endl;
            cout << "8.Lg(x)" << endl;
            cout << "9.Exit" << endl;
            cout << "Enter the function: " << endl;
            cin >> k;
			switch (k)
			{
			case 1: 
				cout << "Enter angle: ";
				cin >> param;
                cout << trans.Sin(param) << endl;
                break;
			case 2: 
				cout << "Enter angle: ";
				cin >> param;
                cout << trans.Cos(param) << endl;
                break;
			case 3: 
				cout << "Enter angle: ";
				cin >> param;
                cout << trans.Tan(param) << endl;
                break;
			case 4: 
				cout << "Enter parametr: ";
				cin >> param;
                cout << trans.Asin(param) << endl;
                break;
			case 5: 
				cout << "Enter parametr: ";
				cin >> param;
                cout << trans.Acos(param) << endl;
                break;
			case 6: 
				cout << "Enter parametr: ";
				cin >> param;
                cout << trans.Atan(param) << endl;
                break;
			case 7: 
				cout << "Enter parametr: ";
				cin >> param;
                cout << trans.Ln(param) << endl;
                break;
			case 8: 
				cout << "Enter parametr: ";
				cin >> param;
                cout << trans.Lg(param) << endl;
                break;
			case 9: 
				return 0;
				break;
			default: 
                cout << "Enter correct key!" << endl;
                break;
			}
		}
		catch (const TranscException& p)
		{
			cout << "Error: " << p.Message() << endl;
			cout << "Expr: " << endl;
			p.outV();
			p.outO();
		}
		system("pause");
		system("cls");
	}
	return 0;
}

double Trans::Sin(double angle) {
	return sin(angle);
}

double Trans::Cos(double angle) {
	return cos(angle);
}

double Trans::Tan(double angle) {
	string f = "Tan";
	if (!cos(angle)) throw TrigException(f, angle);
	else return tan(angle);
}

double Trans::Asin(double value) {
	string f = "Asin";
	if (value > 1 || value < -1) throw TrigException(f, value);
	else return asin(value);
}

double Trans::Acos(double value) {
	string f = "Acos";
	if (value > 1 || value < -1) throw TrigException(f, value);
	else return acos(value);
}

double Trans::Atan(double value) {
	return atan(value);
}

double Trans::Ln(double value) {
	string f = "Ln";
	if (value <= 0) throw LogException(f, value);
	return log(value);
}

double Trans::Lg(double value) {
	string f = "Lg";
	if (value <= 0) throw LogException(f, value);
	return log10(value);
}

