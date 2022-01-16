#include <winsock2.h>
#include <iostream>
#include <stdlib.h>
#include <winbase.h>
#include <ws2tcpip.h>

using namespace std;

int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);

	SOCKET s;
	s = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in ad;
	ad.sin_port = htons(1024);
	ad.sin_family = AF_INET;
	ad.sin_addr.s_addr = 0;//подставляет подходящий iр

	bind(s, (struct sockaddr*)&ad, sizeof(ad));

	char b[100];
	int l;
	l = sizeof(ad);

	while (recvfrom(s, b, strlen(b), 0, (SOCKADDR*)&ad, 0) != 0)
	{
		int rv = recvfrom(s, b, strlen(b), 0, (SOCKADDR*)&ad, &l);
		b[rv] = '\0';

		cout << "Accepted from the client " << b << endl;

		int len = strlen(b);
		int temp;

		if (len % 3 == 0)
		{
			for (int i = 0; i < len; i++)
			{
				if (b[i] % 3 == 0)
				{
					for (int j = i; j < strlen(b); j++)
					{
						temp = b[j];
						b[j] = b[j + 1];
						b[j + 1] = temp;
					}
				}
			}
		}
		else
			cout << "The length is not a multiple of 3" << endl;

		cout << "Result = " << b << endl;
		sendto(s, b, strlen(b), 0, (SOCKADDR*)&ad, l);

		cout << "Sent to the client" << endl;
	}
		closesocket(s);

	WSACleanup();
}
