#include <iostream>
#include <iomanip>

using namespace std;
typedef double (*counter)(double, double, int &);

void output(double, double, double, double, counter, counter);
double y(double, double, int &);
double s(double, double, int &);

int main()
{
	setlocale(LC_ALL, "Rus");
	double  a, b, e, h;
	cout << "Введите Xmin: ";
	cin >> a;
	cout << "Введите Xmax: ";
	cin >> b;
	cout << "Введите точность подсчёта: ";
	cin >> e;
	cout << "Введите шаг изменения X: ";
	cin >> h;
	cout << setw(10) << "X" << setw(10) << "Y(x)" << setw(10) << "S(x)" << endl;
	output(a, b, e, h, y, s);
	cout << endl;
	return 0;
}

void output(double a, double b, double e, double h, counter choise, counter choise1)
{ 
	int k = 0;
	double sum, sum1;
	for (double x = a; x < b + h / 2; x += h)
	{
		sum = choise(x, e, k);
		sum1 = choise1(x, e, k);
		cout << setprecision(3);
		cout << setw(10) << x << setw(10) << sum << setw(10) << sum1 << endl;
	}
}

double s(double x, double e, int& k)
{				
	double p, t, sum1;
	p = x / 3;
	sum1 = 1 + x / 3;
	for (double i = 2; fabs(p) > e; i++)
	{
		t = ((3 * i - 4) * x) / (i * 3);
		p *= -t;
		sum1 += p;
		k++;
	}
	return sum1;
}

double y(double x, double e, int &k)
{
	double sum;
	sum = pow(1 + x, 1 / 3.);
	return sum;
}