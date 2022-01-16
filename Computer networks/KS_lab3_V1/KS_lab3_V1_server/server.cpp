#include <winsock2.h>
#include <iostream>
#include <stdio.h>
#include <winbase.h>
#include <ws2tcpip.h>
#include <processthreadsapi.h>
#include <windows.h>

using namespace std;

struct Subjects {
	char name[20] = {};
	int mark = 0;
};

struct Student {
	char FIO[50] = {};
	int group = 0;
	int grant = 0;
	Subjects subject[3] = {};
};

struct Students {
	int count = 0;
	Student student[20] = {};
}students;

int numClients = 0;

DWORD WINAPI ThreadFunc(LPVOID);
Students input(Students);
void output(char*, int);

int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) { return 1; }

	students = input(students);

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in local_addr;
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(1280);
	local_addr.sin_addr.s_addr = 0;

	bind(s, (sockaddr*)&local_addr, sizeof(local_addr));
	int c = listen(s, 5);
	cout << "Server receive ready" << endl;
	cout << endl;
	cout << "Client IP: 127.0.0.1" << endl;

	SOCKET client_socket;
	sockaddr_in client_addr;
	int client_addr_size = sizeof(client_addr);

	while ((client_socket = accept(s, (sockaddr*)&client_addr, &client_addr_size)))
	{
		DWORD thID; 
		int portClient = ntohs(client_addr.sin_port);
		cout << endl;
		cout << "Client socket: " << client_socket << endl;
		cout << "Client Port: " << portClient << endl;
		cout << "Number of Clients: " << ++numClients << endl << endl;
		CreateThread(NULL, 64, ThreadFunc, &client_socket, NULL, &thID);
	}
	return 0;
}

DWORD WINAPI ThreadFunc(LPVOID client_socket)
{
	SOCKET s2 = ((SOCKET*)client_socket)[0];
	bool a = true;
	char* buffer = new char[sizeof(Students) + 1];
	Students students1;

	while (recv(s2, buffer, sizeof(Students) + 1, 0) && a) {
		output(buffer, sizeof(Students));
		switch (buffer[0]) {
		case 1:
			students1.count = 0;
			for (int i = 0; i < students.count; i++)
				if ((students.student[i].FIO[0] == buffer[1]) || (students.student[i].FIO[0] == buffer[1] - 32)) {
					students1.student[students1.count] = students.student[i];
					students1.count++;
				}
			memcpy(&buffer[1], &students1, sizeof(Students));
			send(s2, buffer, sizeof(Students) + 1, 0);
			break;
		case 2:
			memcpy(&buffer[1], &students, sizeof(Students));
			send(s2, buffer, sizeof(Students) + 1, 0);
			break;
		case 3:
			memcpy(&students1, &buffer[1], sizeof(Students));
			students.student[students.count++] = students1.student[0];
			buffer[1] = '1';
			send(s2, buffer, sizeof(Students) + 1, 0);
			break;
		case 4:
			memcpy(&students1, &buffer[1], sizeof(Students));
			for (int i = 0; i < students.count; i++)
				if (!strcmp(students.student[i].FIO, students1.student[0].FIO)) {
					students.student[i] = students1.student[0];
					buffer[1] = '1';
					break;
				}
			if (buffer[1] == '1')
				send(s2, buffer, sizeof(Students) + 1, 0);
			else {
				buffer[1] = 0;
				send(s2, buffer, sizeof(Students) + 1, 0);
			}
			break;
		case 5:
			for (int i = 0; i < students.count; i++)
				if (!strcmp(students.student[i].FIO, &buffer[1])) {
					for (int j = i; j < students.count - 1; j++)
						students.student[j] = students.student[j + 1];
					students.count--;
					buffer[1] = '1';
					break;
				}
			if (buffer[1] == '1')
				send(s2, buffer, sizeof(Students) + 1, 0);
			else {
				buffer[1] = 0;
				send(s2, buffer, sizeof(Students) + 1, 0);
			}
			break;
		case 6: 
			a = false;
			break;
		default: cout << "Error!" << endl;
			break;
		}
	}
	closesocket(s2);
	cout << "Number of Clients: " << --numClients << endl;
	delete[] buffer;
	return 0;
}

Students input(Students students)
{
	strcpy_s(students.student[0].FIO, 50, "Adamovich Daria Stanislavovna");
	students.student[0].FIO[strlen(students.student[0].FIO)] = '\0';
	students.student[0].group = 110101;
	students.student[0].grant = 160;
	strcpy_s(students.student[0].subject[0].name, 20, "Math");
	students.student[0].subject[0].name[strlen(students.student[0].subject[0].name)] = '\0';
	students.student[0].subject[0].mark = 8;
	strcpy_s(students.student[0].subject[1].name, 20, "English");
	students.student[0].subject[1].name[strlen(students.student[0].subject[1].name)] = '\0';
	students.student[0].subject[1].mark = 9;
	strcpy_s(students.student[0].subject[2].name, 20, "History");
	students.student[0].subject[2].name[strlen(students.student[0].subject[2].name)] = '\0';
	students.student[0].subject[2].mark = 9;

	strcpy_s(students.student[1].FIO, 50, "Lysenko Anton Aleksandrovich");
	students.student[1].FIO[strlen(students.student[1].FIO)] = '\0';
	students.student[1].group = 120601;
	students.student[1].grant = 140;
	strcpy_s(students.student[1].subject[0].name, 20, "Math");
	students.student[1].subject[0].name[strlen(students.student[1].subject[0].name)] = '\0';
	students.student[1].subject[0].mark = 9;
	strcpy_s(students.student[1].subject[1].name, 20, "English");
	students.student[1].subject[1].name[strlen(students.student[1].subject[1].name)] = '\0';
	students.student[1].subject[1].mark = 5;
	strcpy_s(students.student[1].subject[2].name, 20, "History");
	students.student[1].subject[2].name[strlen(students.student[1].subject[2].name)] = '\0';
	students.student[1].subject[2].mark = 7;

	strcpy_s(students.student[2].FIO, 50, "Tomashevich Evgeny Antonovich");
	students.student[2].FIO[strlen(students.student[2].FIO)] = '\0';
	students.student[2].group = 111801;
	students.student[2].grant = 115;
	strcpy_s(students.student[2].subject[0].name, 20, "Math");
	students.student[2].subject[0].name[strlen(students.student[2].subject[0].name)] = '\0';
	students.student[2].subject[0].mark = 5;
	strcpy_s(students.student[2].subject[1].name, 20, "English");
	students.student[2].subject[1].name[strlen(students.student[2].subject[1].name)] = '\0';
	students.student[2].subject[1].mark = 8;
	strcpy_s(students.student[2].subject[2].name, 20, "History");
	students.student[2].subject[2].name[strlen(students.student[2].subject[2].name)] = '\0';
	students.student[2].subject[2].mark = 10;

	strcpy_s(students.student[3].FIO, 50, "Berezhnoy Danila Sergeevich");
	students.student[3].FIO[strlen(students.student[3].FIO)] = '\0';
	students.student[3].group = 150504;
	students.student[3].grant = 130;
	strcpy_s(students.student[3].subject[0].name, 20, "Math");
	students.student[3].subject[0].name[strlen(students.student[3].subject[0].name)] = '\0';
	students.student[3].subject[0].mark = 10;
	strcpy_s(students.student[3].subject[1].name, 20, "English");
	students.student[3].subject[1].name[strlen(students.student[3].subject[1].name)] = '\0';
	students.student[3].subject[1].mark = 8;
	strcpy_s(students.student[3].subject[2].name, 20, "History");
	students.student[3].subject[2].name[strlen(students.student[3].subject[2].name)] = '\0';
	students.student[3].subject[2].mark = 6;

	strcpy_s(students.student[4].FIO, 50, "Voronova Ksenia Nikolaevna");
	students.student[4].FIO[strlen(students.student[4].FIO)] = '\0';
	students.student[4].group = 110101;
	students.student[4].grant = 160;
	strcpy_s(students.student[4].subject[0].name, 20, "Math");
	students.student[4].subject[0].name[strlen(students.student[4].subject[0].name)] = '\0';
	students.student[4].subject[0].mark = 8;
	strcpy_s(students.student[4].subject[1].name, 20, "English");
	students.student[4].subject[1].name[strlen(students.student[4].subject[1].name)] = '\0';
	students.student[4].subject[1].mark = 9;
	strcpy_s(students.student[4].subject[2].name, 20, "History");
	students.student[4].subject[2].name[strlen(students.student[4].subject[2].name)] = '\0';
	students.student[4].subject[2].mark = 9;

	students.count = 5;

	return students;
}

void output(char* buffer, int size) {
	Students students1;
	int buf = buffer[0];
	switch (buffer[0]) {
	case 1: 
		cout << "Received buffer: " << buf << "/" << buffer[1] << "/" << endl;
		break;
	case 2:
		cout << "Received buffer: " << buf << "/" << endl;
		break;
	case 3:
		cout << "Received buffer: " << buf << "/";
		memcpy(&students1, &buffer[1], size);
		cout << students1.student[0].FIO;
		cout << "/" << students1.student[0].grant;
		cout << "/" << students1.student[0].group;
		cout << "/" << students1.student[0].subject[0].name << "/" << students1.student[0].subject[0].mark;
		cout << "/" << students1.student[0].subject[1].name << "/" << students1.student[0].subject[1].mark;
		cout << "/" << students1.student[0].subject[2].name << "/" << students1.student[0].subject[2].mark << "/" << endl;
		break;
	case 4:
		cout << "Received buffer: " << buf << "/";
		memcpy(&students1, &buffer[1], size);
		cout << students1.student[0].FIO;
		cout << "/" << students1.student[0].grant;
		cout << "/" << students1.student[0].group;
		cout << "/" << students1.student[0].subject[0].name << "/" << students1.student[0].subject[0].mark;
		cout << "/" << students1.student[0].subject[1].name << "/" << students1.student[0].subject[1].mark;
		cout << "/" << students1.student[0].subject[2].name << "/" << students1.student[0].subject[2].mark << "/" << endl;
		break;
	case 5:
		cout << "Received buffer: " << buf << "/";
		puts(&buffer[1]);
		break;
	case 6:
		cout << "Received buffer: " << buf << "/";
		cout << endl << "The client disconnected!" << endl;
		break;
	default: 
		cout << "Error!" << endl;
		break;
	}
}
