#include "main.h"

int main() {

	bool flag = true;
	int k = 0;
	int value;
	Stack<int> stack;


	while (flag) {
		cout << "1.Push" << endl;
		cout << "2.Top" << endl;
		cout << "3.Next" << endl;
		cout << "4.Pop" << endl;
		cout << "5.isEmpty" << endl;
		cout << "6.Show" << endl;
		cout << "7.Exit" << endl;
		cin >> k;
		switch (k) {
		case 1:
			cout << "Enter the value: ";
			cin >> value;
			stack.push(value);
			break;
		case 2:
			//value = stack.top();
			cout << "Top is: " << stack.top() << endl;
			break;
		case 3:
			if (stack.next())
				cout << "Next is: " << stack.top(stack.getTmp()) << endl;
			break;
		case 4:
			cout << "Pop: " << stack.pop() << endl;
			break;
		case 5:
			if (stack.isEmpty())
				cout << "isEmpty: true" << endl;
			else
				cout << "isEmpty: false" << endl;
			break;
		case 6:
			cout << "Show: " << endl;
			stack.show();
			cout << endl;
			break;
		case 7:
			flag = false;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}