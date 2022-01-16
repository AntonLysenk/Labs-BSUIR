#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> array;
	int v = 0, k = 0;
	while (true) {
		try {
			cout << "1.Add element" << endl;
			cout << "2.Show elements" << endl;
			cout << "3.Delete elements" << endl;
			cout << "4.Exit" << endl;
			cin >> k;
			switch (k) {
			case 1:
				cout << "Enter the element: ";
				cin >> v;
				array.insert(v);
				break;
			case 2:
				if (!array.size()) throw 1;
				for (set<int>::iterator i = array.begin(); i != array.end(); ++i)
					cout << *i << ' ';
				break;
			case 3:
				if (!array.size()) throw 1;
				while (array.size() != 1) {
					set<int>::iterator i = array.begin();
					array.erase(i);
				}
				cout << "Result: " << *array.begin() << endl;
				break;
			case 4: return 0;
				break;
			default: throw 0;
				break;
			}
		}
		catch (int c) {
			if (c)
				cout << "Array should has more than 0 elements!" << endl;
			else	
				cout << "Choise the correct key!" << endl;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
