#include <stdio.h>
#include <math.h>
#include <locale.h>


int main()
{

	setlocale(LC_ALL, "Rus");

	double a, b, x, s, p, y, h, t, k;
	int n, i, g;
	
	printf("Введите Хмин:");
	g = scanf_s("%lf", &a);
	if (g == 0) return 1; 

	printf("Введите Хмакс:");
	g = scanf_s("%lf", &b);
	if (g == 0) return 1;

	printf("Введите n:");
	g = scanf_s("%d", &n);
	if (g == 0) return 1;

	h = (b - a) / 10;
	x = a;
	t = acos(-1) / 4;
	
	for (; x <= b + h / 2;)
	{
		s = p = 1;
		
		for (i = 1; i <= n; i++)
		{
			k = cos(i * t);
			p *= x / i;
			s += k * p;
		}
		
		y = exp(x * cos(t)) * cos(x * sin(t));
		printf("%30.15lf%30.15lf%30.15lf\n",x,y,s);
		x += h;
	}
	return 0;
}
