#include <winsock2.h>
#include <iostream>
#include <stdio.h>
#include <winbase.h>
#include <ws2tcpip.h>

using namespace std;

struct Subjects {
	char name[20] = {};
	int mark = 0;
};

struct Student {
	char FIO[50] = {};
	int group = 0;
	int grant = 0;
	Subjects subject[3];
};

struct Students {
	int count = 0;
	Student student[20] = {};
};

int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) { return 1; }

	Students students;
	char* buffer = new char[sizeof(Students) + 1];
	bool a = true;

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in dest_addr;
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(1280);
	inet_pton(AF_INET, "127.0.0.1", &(dest_addr.sin_addr)); //преобразует сетевой адрес в двоичную форму
	connect(s, (sockaddr*)&dest_addr, sizeof(dest_addr));

	while (a)
	{
		short k = 0;
		cout << "1.Student search" << endl;
		cout << "2.Viewing information about students" << endl;
		cout << "3.Adding a student" << endl;
		cout << "4.Editing student information" << endl;
		cout << "5.Deleting student information" << endl;
		cout << "6.Exit" << endl;
		cin >> k;
		buffer[0] = static_cast<char>(k);
		switch (k) {
		case 1:
			cout << "Enter the first letter of the students last name: ";
			cin >> buffer[1];
			send(s, buffer, sizeof(Students), 0);
			break;
		case 2:
			send(s, buffer, sizeof(Students), 0);
			break;
		case 3:
			cout << "Enter the student's full name: ";
			if (cin.peek() == '\n')
				cin.ignore();
			gets_s(students.student[0].FIO, 50);
			cout << "Enter the grant: ";
			cin >> students.student[0].grant;
			cout << "Enter the student's group: ";
			cin >> students.student[0].group;
			cout << "Enter the name of the item: ";
			if (cin.peek() == '\n')
				cin.ignore();
			gets_s(students.student[0].subject[0].name, 20);
			cout << "Enter the " << students.student[0].subject[0].name << " score: ";
			cin >> students.student[0].subject[0].mark;
			cout << "Enter the name of the item: ";
			if (cin.peek() == '\n')
				cin.ignore();
			gets_s(students.student[0].subject[1].name, 20);
			cout << "Enter the " << students.student[0].subject[1].name << " score: ";
			cin >> students.student[0].subject[1].mark;
			cout << "Enter the name of the item: ";
			if (cin.peek() == '\n')
				cin.ignore();
			gets_s(students.student[0].subject[2].name, 20);
			cout << "Enter the " << students.student[0].subject[2].name << " score: ";
			cin >> students.student[0].subject[2].mark;
			memcpy(&buffer[1], &students, sizeof(Students));
			send(s, buffer, sizeof(Students) + 1, 0);
			break;
		case 4:
			cout << "Enter the student's full name to change the information: ";
			if (cin.peek() == '\n')
				cin.ignore();
			gets_s(students.student[0].FIO, 50);
			cout << "Enter the corrected student information: " << endl;
			cout << "Enter the grant: ";
			cin >> students.student[0].grant;
			cout << "Enter the student's group: ";
			cin >> students.student[0].group;
			cout << "Enter the name of the item: ";
			if (cin.peek() == '\n')
				cin.ignore();
			gets_s(students.student[0].subject[0].name, 20);
			cout << "Enter the " << students.student[0].subject[0].name << " score: ";
			cin >> students.student[0].subject[0].mark;
			cout << "Enter the name of the item: ";
			if (cin.peek() == '\n')
				cin.ignore();
			gets_s(students.student[0].subject[1].name, 20);
			cout << "Enter the " << students.student[0].subject[1].name << " score: ";
			cin >> students.student[0].subject[1].mark;
			cout << "Enter the name of the item: ";
			if (cin.peek() == '\n')
				cin.ignore();
			gets_s(students.student[0].subject[2].name, 20);
			cout << "Enter the " << students.student[0].subject[2].name << " score: ";
			cin >> students.student[0].subject[2].mark;
			memcpy(&buffer[1], &students, sizeof(Students));
			send(s, buffer, sizeof(Students) + 1, 0);
			break;
		case 5:
			cout << "Enter the full name of the student being removed: ";
			if (cin.peek() == '\n')
				cin.ignore();
			gets_s(&buffer[1], 50);
			send(s, buffer, sizeof(Students) + 1, 0);
			break;
		case 6:
			cout << "Disconnection completed successfully!" << endl;
			a = false;
			send(s, buffer, sizeof(Students) + 1, 0);
			WSACleanup();
			closesocket(s);
			break;
		default: cout << "Error, repeat please!" << endl;
			break;
		}

		if (recv(s, buffer, sizeof(Students) + 1, 0))
		{
			switch (buffer[0]) {
			case 1:
				memcpy(&students, &buffer[1], sizeof(Students));
				if (!students.count)
					cout << "There are no students for this letter!" << endl;
				for (int i = 0; i < students.count; i++) {
					cout << "FIO: " << students.student[i].FIO << endl;
					cout << "Grant: " << students.student[i].grant << endl;
					cout << "Group: " << students.student[i].group << endl;
					cout << "Grades by subject:" << endl;
					cout << students.student[i].subject[0].name << ": " << students.student[i].subject[0].mark << endl;
					cout << students.student[i].subject[1].name << ": " << students.student[i].subject[1].mark << endl;
					cout << students.student[i].subject[2].name << ": " << students.student[i].subject[2].mark << endl << endl;
				}
				break;
			case 2:
				memcpy(&students, &buffer[1], sizeof(Students));
				for (int i = 0; i < students.count; i++) {
					cout << "FIO: " << students.student[i].FIO << endl;
					cout << "Grant: " << students.student[i].grant << endl;
					cout << "Group: " << students.student[i].group << endl;
					cout << "Grades by subject:" << endl;
					cout << students.student[i].subject[0].name << ": " << students.student[i].subject[0].mark << endl;
					cout << students.student[i].subject[1].name << ": " << students.student[i].subject[1].mark << endl;
					cout << students.student[i].subject[2].name << ": " << students.student[i].subject[2].mark << endl << endl;
				}
				break;
			case 3:
				if (buffer[1])
					cout << "New student is added successfully!" << endl;
				else
					cout << "Error!" << endl;
				break;
			case 4:
				if (buffer[1])
					cout << "Student data has been successfully changed!" << endl;
				else
					cout << "The student with the given name doesn't exist" << endl;
				break;
			case 5:
				if (buffer[1])
					cout << "Student information has been successfully deleted!" << endl;
				else
					cout << "A student with this full name does't exist!" << endl;
				break;
			case 6: 
				break;
			default: cout << "Error!" << endl;
				break;
			}
		}
		system("pause");
		system("cls");
	}
	delete[] buffer;
	return 0;
}
