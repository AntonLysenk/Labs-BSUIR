#include <ctime>
#include <iostream>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main()

{
	
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	const int n = 10;
	int a[n];
	int k, i, u, j, max, max1;
	u = 0;
	printf("Выберите способ заполнения массива:  1-Ввод с клавиатуры; 2-Заполнение случайными числами\n");
	scanf_s("%d", &u);
	printf("\n\n");

	switch (u)

	{

	case 1:

		for (int i = 0; i < n; i++)

		{

			fprintf(stdout,"Элемент:");
			fscanf_s(stderr,"%d", &a[i]);
			printf("\n");

		}

		break;

	case 2:

		for (int i = 0; i < n; i++)

		{

			a[i] = rand() % 15;
			printf("%d \n", a[i]);

		}

		break;

	default:

		printf("Ошибка выбора способа");
		return 1;

	}
	
	j = 0;
	max = 0;
	max1 = 0;
	
	for (i = 0; i < n - 1; i++)

	{
		
		k = 1;

		for (j = i + 1; j < n; j++)

		{

			if ( a[i] == a[j] ) 
			k++;

		}

		if (max < k)

		{ 

			max = k; 
			max1 = a[i]; 
		
		}

	}

	if (max == 1) printf("Нет повторяющихся чисел"); else 
	printf("Наиболее повторяющееся число: %d\nКоличество повторов: %d", max1, max);

}
