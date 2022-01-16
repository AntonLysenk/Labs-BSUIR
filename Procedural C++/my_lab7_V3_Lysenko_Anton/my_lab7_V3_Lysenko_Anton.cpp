#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	
	struct dormitory {
		char FIO[50];
		char gr[10];
		double srb;
		int dohod;
	};

	setlocale(LC_ALL, "Rus");

	int n, i, j, minSalary;

	cout << "Введите количество студентов:";
	cin >> n;

	dormitory *stud = new dormitory[n];

	minSalary = 375;
	
	for (i = 0; i < n; i++)
	{
		cout << "Введите ФИО " << i + 1 << " студента: ";
		cin.ignore(32767, '\n');
		gets_s(stud[i].FIO);
		cout << "Введите номер группы " << i + 1 << " студента: ";
		cin >> stud[i].gr;
		cout << "Введите средний балл " << i + 1 << " студента: ";
		cin >> stud[i].srb;
		cout << "Введите доход на члена семьи " << i + 1 << " студента: ";
		cin >> stud[i].dohod;
		cout << endl;
	}
	
	dormitory reserve;

	for (i = 0; i < n; i++)
	{
		if (stud[i].dohod < 2 * minSalary)
		{
			cout << "ФИО: " << stud[i].FIO << endl << "Номер группы: " << stud[i].gr << endl;
			cout << "Средний балл: " << stud[i].srb << endl << "Доход на члена семьи: " << stud[i].dohod << endl << endl;
		}
	}
	
	for (i = 0; i < n - 1; i++)
	{
		if (stud[i].dohod >= 2 * minSalary)
		{
			for (j = i + 1; j < n; j++)
			{
				if (stud[j].dohod >= 2 * minSalary && stud[i].srb < stud[j].srb)
				{
					reserve = stud[i];
					stud[i] = stud[j];
					stud[j] = reserve;
				}

			}
			cout << "ФИО: " << stud[i].FIO << endl << "Номер группы: " << stud[i].gr << endl;
			cout << "Средний балл: " << stud[i].srb << endl << "Доход на члена семьи: " << stud[i].dohod << endl << endl;
		}
	}

	if (stud[i].dohod >= 2 * minSalary)
	{
		cout << "ФИО: " << stud[i].FIO << endl << "Номер группы: " << stud[i].gr << endl;
		cout << "Средний балл: " << stud[i].srb << endl << "Доход на члена семьи: " << stud[i].dohod << endl << endl;
	}
	return 0;
}