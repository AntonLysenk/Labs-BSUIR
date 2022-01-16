#include <winsock2.h>
#include <iostream>
#include <stdlib.h>
#include <ws2tcpip.h>

using namespace std;

int main() {

	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2, 2);
	int errStart = 0;
	errStart = WSAStartup(wVersionRequested, &wsaData);

	struct sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(1280);
	inet_pton(AF_INET, "127.0.0.1", &(peer.sin_addr));


	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);

	connect(s, (struct sockaddr*)&peer, sizeof(peer));

	char buf[128], b[100];
	int res = 0, mult = 1;
	cout << "Enter the expression: ";
	cin.getline(buf, 128, '\n');

	send(s, buf, sizeof(buf), 0);
	cout << "Sent to the server "<< buf << endl;
	if (recv(s, b, sizeof(b), 0) != 0) {
		cout << "Received from the server" << endl;
		b[strlen(b)] = '\0';
		for (short i = strlen(b) - 1; i >= 0; i--) {
			res += (b[i] - 48) * mult;
			mult *= 10;
		}
		cout <<"Result = "<< res << endl;
	}

	closesocket(s);

	WSACleanup();

	return 0;
}
