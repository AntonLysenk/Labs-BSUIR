#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double x, y,a, f, c;
	int k;
	cout << "Vvedite x:";
	cin >> x;
	cout << "Vvedite y:";
	cin >> y;
	cout << "Viberite f: 1-sh(x), 2-x^2, 3-exp(x)" << endl;
	cin >> k;
	switch (k)
	{
	case 1:f = sinh(x); break;
	case 2:f = pow(x, 2); break;
	case 3:f = exp(x); break;
	default:cout << "Ne vibrana funkciya";
		return 1;
	}
	a = x - y;
	if (a= 0) c=pow(f, 2) + pow(y, 1 / 3.) + sin(y);
	else
		if (a> 0) c=pow(f - y, 2) + log(x);
		else c=pow(y - f, 2) + tan(y);
	cout << "Result=" << c << endl;
	return (0);
}