#include <winsock2.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2, 2);
	int errStart = 0;
	errStart = WSAStartup(wVersionRequested, &wsaData);

	SOCKET  s = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(1280);
	local.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(s, (struct sockaddr*)&local, sizeof(local));
	listen(s, 5);

	while (true) {
		char res[100], buff[129], sign = 0;
		//структура определяет удаленный адрес,
		//с которым  соединяется сокет
		sockaddr_in remote_addr;
		int size = sizeof(remote_addr), result = 0, a = 0, b = 0, mult = 1, i = 0;
		SOCKET s2 = accept(s, (struct sockaddr*)&remote_addr, &size);

		while (recv(s2, buff, sizeof(buff), 0) != 0) {

			cout << "Accepted from the client " << buff << endl;

			for (i = strlen(buff) - 1; i >= 0; i--) {
				if (buff[i] == '+' || buff[i] == '-' || buff[i] == '*' || buff[i] == '/') {
					sign = buff[i];
					mult = 1;
					break;
				}
				b += (buff[i] - 48) * mult;
				mult *= 10;
			}

			for (i = i - 1; i >= 0; i--) {
				a += (buff[i] - 48) * mult;
				mult *= 10;
			}
		
			switch (sign) {
			case 42: result = a * b; break; 
			case 43: result = a + b; break; 
			case 45: result = a - b; break; 
			case 47: result = a / b; break; 
			default: break;
			}
			cout << "Result = " << result << endl;
			_itoa_s(result, res, 10);

			//Посылает данные на соединенный сокет
			send(s2, res, sizeof(res) - 2, 0);
			cout << "Sent to the client" << endl;
		}
		closesocket(s2);
	}

	WSACleanup();
}
