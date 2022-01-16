#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "client.h"

using namespace std;

const int BUFF_SIZE = 512;

int main() {
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;
    bool flag = false;
    wVersionRequested = MAKEWORD(2, 2);
    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0)
        return err;
    bool a = true;
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(1280);
    inet_pton(AF_INET, "127.0.0.1", &(dest_addr.sin_addr));
    connect(s, (sockaddr*)&dest_addr, sizeof(dest_addr));
    char buffer[BUFF_SIZE] = {};

	while (a)
	{
        int k = 0;
        cout << "1.Authorization" << endl;
        cout << "2.Send" << endl;
        cout << "3.Exit" << endl;
        cin >> k;
        buffer[0] = static_cast<char>(k);
        switch (k)
        {
        case 1:
            cout << "Enter the login: ";
            cin >> user.login;
            cout << "Enter the password: ";
            cin >> user.password;
            memcpy(&buffer[1], &user, sizeof(User));
            send(s, buffer, BUFF_SIZE, 0);
            break;
        case 2:
            if (flag) {
                strcpy_s(message.from, sizeof(workUser.login), workUser.login);
                cout << "Enter the recipient: ";
                cin >> message.to;
                cout << "Enter the message: ";
                cin >> message.message;
                memcpy(&buffer[1], &message, sizeof(Message));
                send(s, buffer, BUFF_SIZE, 0);
            }
            else {
                cout << "Go through authorization!" << endl;
                send(s, buffer, BUFF_SIZE, 0);
            }
            break;
        case 3:
            cout << "Disconnection completed successfully!" << endl;
            a = false;
            send(s, buffer, BUFF_SIZE, 0);
            WSACleanup();
            closesocket(s);
            break;
        default: 
            cout << "Error!" << endl;
            break;
        }

		if (recv(s, buffer, BUFF_SIZE, 0))
		{
			switch (buffer[0]) {
			case 1:
                if (buffer[1] == '1') {
                    cout << "You have successfully logged in to your account!" << endl;
                    workUser = user;
                    flag = true;
                }
                else {
                    flag = false;
                    cout << "Invalid username or password!" << endl;
                }
				break;
			case 2:
                if (buffer[1] == '1')
                    cout << "Message delivered!" << endl;
                else
                    cout << "Delivery error!" << endl;
				break;
			case 3:
				break;
			default:
                cout << "Error!" << endl;
				break;
			}
		}
		system("pause");
		system("cls");
	}
    return 0;
}