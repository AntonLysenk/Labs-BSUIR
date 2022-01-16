#include <iostream>
#include <winsock2.h>
#include <cstring>
#include <ws2tcpip.h>
#include <processthreadsapi.h>
#include <windows.h>
#include "server.h"

using namespace std;

DWORD WINAPI ThreadFunc(LPVOID);
void input();

const int BUFF_SIZE = 512;

int numClients = 0;

int main() {

    input();
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;
    wVersionRequested = MAKEWORD(2, 2);
    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0)
        return -1;

    sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(1280);
    local.sin_addr.s_addr = 0;
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);

    bind(s, (struct sockaddr*)&local, sizeof(local));
    int c = listen(s, 5);

    SOCKET client_socket;
    sockaddr_in client_addr;
    int client_addr_size = sizeof(client_addr);

    cout << "Server is started..." << endl;

    while ((client_socket = accept(s, (sockaddr*)&client_addr, &client_addr_size)))
    {
        DWORD thID;
        int portClient = ntohs(client_addr.sin_port);
        char ip_client[20] = {};
        inet_ntop(AF_INET, &client_addr.sin_addr, ip_client, sizeof(ip_client));
        cout << endl;
        cout << "Client socket: " << client_socket << endl;
        cout << "Client Port: " << portClient << endl;
        cout << "Client IP: " << ip_client << endl;
        cout << "Number of Clients: " << ++numClients << endl << endl;
        CreateThread(NULL, 64, ThreadFunc, &client_socket, NULL, &thID);
    }

    WSACleanup();

    return 0;
}

DWORD WINAPI ThreadFunc(LPVOID client_socket) {
	SOCKET s2 = ((SOCKET*)client_socket)[0];
	char buffer[BUFF_SIZE];
    bool a = true;

	while (recv(s2, buffer, BUFF_SIZE, 0) && a) {
		switch (buffer[0]) {
		case 1:
            memcpy(&workUser, &buffer[1], sizeof(workUser));
            buffer[1] = '0';
            for (int i = 0; i < 3; i++) {
                if (!strcmp(workUser.login, user[i].login))
                    if (!strcmp(workUser.password, user[i].password))
                        buffer[1] = '1';
            }
            if (buffer[1] == '1')
                send(s2, buffer, BUFF_SIZE, 0);
            else 
                send(s2, buffer, BUFF_SIZE, 0);
			break;
		case 2:
            memcpy(&message, &buffer[1], sizeof(message));
            cout << "-----------Letter--------------" << endl;
            cout << "From: ";
            cout << message.from << endl;
            cout << "To: ";
            cout << message.to << endl;
            cout << "Text: ";
            cout << message.message << endl;
            buffer[1] = '1';
			send(s2, buffer, BUFF_SIZE, 0);
			break;
		case 3:
            a = false;
			break;
		default: cout << "Error!" << endl;
			break;
		}
	}
	closesocket(s2);
	cout << "Number of Clients: " << --numClients << endl;
	return 0;
}

void input() {
    strcpy_s(user[0].login, 100, "user1\0");
    strcpy_s(user[0].password, 50, "user1\0");

    strcpy_s(user[1].login, 100, "user2\0");
    strcpy_s(user[1].password, 50, "user2\0");

    strcpy_s(user[2].login, 100, "user3\0");
    strcpy_s(user[2].password, 50, "user3\0");
}
