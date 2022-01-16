#include <winsock2.h>
#include <iostream>
#include <stdlib.h>
#include <winbase.h>
#include <ws2tcpip.h>

using namespace std;

int main()
{
	char buf[100], b[100];
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
		return 0;

	SOCKET s;
	s = socket(AF_INET, SOCK_DGRAM, 0);
	sockaddr_in add;
	add.sin_family = AF_INET;
	add.sin_port = htons(1024);

	inet_pton(AF_INET, "127.0.0.1", &(add.sin_addr));

	int t;
	t = sizeof(add);

	cout << "Enter the string, please" << endl;
	cin.getline(buf, 100, '\n');

	sendto(s, buf, strlen(buf), 0, (struct sockaddr*)&add, t);

	cout << "Sent to the server " << buf << endl;

	int rv = recvfrom(s, b, strlen(b), 0, (struct sockaddr*)&add, &t);
	b[rv] = '\0';
	cout << "Received from the server" << endl;

	cout << "Result = " << b << endl;

	closesocket(s);

	WSACleanup();
	return 0;
}
