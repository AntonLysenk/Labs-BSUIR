#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double x, y, z, a, b, c, s;
	cout << "Vvedite x:";
	cin >> x;
	cout << "Vvedite y:";
	cin >> y;
	cout << "Vvedite z:";
	cin >> z;
	a = (1 + pow(sin(x + y), 2))*pow(x,fabs(y));
	b = fabs(x - 2*y / (1 + pow(x*y, 2)));
	c = pow(cos(atan2(1, z)), 2);
	s = a / b + c;
	cout << "Result s=" << s << endl;
	return(0);
}