#include <iostream>

int main()

{
	setlocale(LC_ALL, "Rus");
	int n, m, i, p, j, u;
	bool e = 0;

	printf("Введите число строк:");
	scanf_s("%d", &n);
	printf("Введите число столбцов:");
	scanf_s("%d", &m);

	int **a;
	a = new int* [n];
	for (p = 0; p < n; p++)
		a[p] = new int[m];
	int *b;
	b = new int [n];

	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < m; j++)
		{
			printf("Введите элемент [%d][%d]:", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
	
	for (i = 0; i < n; i++)
	{
		e = 1;
		for (j = 0, u = m - 1; j < m / 2; j++, u--)
		{
			if (a[i][j] != a[i][u])
			{
				e = 0;
				break;
			}
		}
		if (e) b[i] = 1;
		else b[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < m; j++)
		{
			printf("%d    ", a[i][j]);
		}
		printf("b[%d]:%d\n", i, b[i]);
	}



	for (i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete []a;
	delete []b;
	return 0;
}