#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int i, max = 0, count = 0;
	string st;
    printf("Введите строку состоящую из нулей, единиц и пробелов:");
	getline(cin, st);

	for (i = 0; i <= int (st.size()); i++)
	{
		if (st[i] == '1' || st[i] == '0') count++;
		else 
		if (st[i] == ' ' || st[i] == '\0')
		{
			if (count > max) max = count;
			count = 0;
		}
		else
		{
			printf("Ошибка ввода, строка должна состоять из нулей, единиц и пробелов\n");
			return 1;
		}
	}
	printf("Максимальное количество символов в группе: %d\n", max);
    return 0;
}


