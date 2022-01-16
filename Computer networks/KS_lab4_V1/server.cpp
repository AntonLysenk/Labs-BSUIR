#include <sys/types.h>
#include<sys/socket.h>
#include<sys/signal.h>
#include<sys/wait.h>
#include<sys/resource.h>
#include<netinet/in.h>

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <climits>

using namespace std;

struct Book {
	char name[50] = {};
	int year;
	char author[20] = {};
	char language[15] = {};
};

struct Books {
	Book book[20];
	int count = 0;
} books;

int k = 0;

void input();
void sortByAlphabet(Books&);
void sortByPrise(Books&, char);

void Func(int s) {
	char* buffer = new char[sizeof(Books) + 1];
	Books books1;
	int yearPub = 0;
	int i = 0, j = 0;
	char languageWri[15] = {};
	char nameBook[50] = {};

	while (true) {
		int r = recv(s, buffer, sizeof(Books) + 1, 0);
		if (r < 0) {
			cout << "ERORR!(recv_server)" << endl;
			exit(1);
		}
		switch (buffer[0]) {
		case 1:
			memcpy(&nameBook, &buffer[1], sizeof(nameBook));
			books1.count = 0;
			for (i = 0, j = 0; i < books.count; i++)
				if (!strcmp(books.book[i].name, nameBook))
					books1.book[books1.count++] = books.book[i];
			memcpy(&buffer[1], &books1, sizeof(Books));
			send(s, buffer, sizeof(Books) + 1, 0);
			break;
		case 2:
			memcpy(&yearPub, &buffer[1], sizeof(yearPub));
			books1.count = 0;
			for (i = 0; i < books.count; i++)
				if (books.book[i].year == yearPub)
					books1.book[books1.count++] = books.book[i];
			memcpy(&buffer[1], &books1, sizeof(Books));
			send(s, buffer, sizeof(Books) + 1, 0);
			break;
		case 3:
			memcpy(&languageWri, &buffer[1], sizeof(languageWri));
			books1.count = 0;
			for (i = 0, j = 0; i < books.count; i++)
				if (!strcmp(books.book[i].language, languageWri))
					books1.book[books1.count++] = books.book[i];
			memcpy(&buffer[1], &books1, sizeof(Books));
			send(s, buffer, sizeof(Books) + 1, 0);
			break;
		case 4:
			memcpy(&books1, &buffer[1], sizeof(Books));
			books.book[books.count++] = books1.book[0];
			buffer[1] = '1';
			send(s, buffer, sizeof(Books) + 1, 0);
			break;
		case 5:
			memcpy(&nameBook, &buffer[1], sizeof(nameBook));
			buffer[1] = 0;
			for (i = 0, j = 0; i < books.count; i++)
				if (!strcmp(books.book[i].name, nameBook)) {
					for (int t = i; t < (books.count - 1); t++)
						books.book[t] = books.book[t + 1];
					buffer[1] = '1';
				}
			books.count--;
			memcpy(&buffer[1], &books, sizeof(Books));
			send(s, buffer, sizeof(Books) + 1, 0);
			break;
		case 6:
			sortByPrise(books, buffer[1]);
			memcpy(&buffer[1], &books, sizeof(Books));
			send(s, buffer, sizeof(Books) + 1, 0);
			break;
		case 7:
			sortByAlphabet(books);
			memcpy(&buffer[1], &books, sizeof(Books));
			send(s, buffer, sizeof(Books) + 1, 0);
			break;
		case 8: {
			cout << "The client has been successfully disconnected!" << endl;
			close(s);
            exit(0);
			break;
		}
		default:
		exit(0);
		}
	}
}

int main(){
		input();
		struct sockaddr_in local;
		int s, rc;
			
		local.sin_family=AF_INET;
		local.sin_port=htons(7500);
		local.sin_addr.s_addr=htonl(INADDR_ANY);
		
		s=socket(AF_INET, SOCK_STREAM,0);

		if (s < 0) {
			perror("socket");
			exit(1);
		}

		if (bind(s,(struct sockaddr *)&local, sizeof(local))) {
			perror("bind");
			exit(2);
		}

		if (listen(s,5)) {
			perror("listen");
			exit(3);
		}
		signal(SIGCHLD,SIG_IGN);
		while (true)
		{
			int newS = accept(s, NULL, NULL);
			pid_t pid = fork();
			if (pid < 0)
			{
				perror("fork1");
				exit(4);
			}
			else if (pid > 0)
			{
				close(newS);
			}
			else
			{
				cout << "A new client is connected!" << endl;
				close(s);

				Func(newS);
			}
		}

		return 0;
}

void input() {

	strcpy(books.book[0].name, "english");
	books.book[0].name[strlen(books.book[0].name)] = '\0';
	strcpy(books.book[0].author, "Gilbert");
	books.book[0].author[strlen(books.book[0].author)] = '\0';
	strcpy(books.book[0].language, "english");
	books.book[0].language[strlen(books.book[0].language)] = '\0';
	books.book[0].year = 2001;

	strcpy(books.book[1].name, "red_cap");
	books.book[1].name[strlen(books.book[1].name)] = '\0';
	strcpy(books.book[1].author, "Charles Perrault");
	books.book[1].author[strlen(books.book[1].author)] = '\0';
	strcpy(books.book[1].language, "rus");
	books.book[1].language[strlen(books.book[1].language)] = '\0';
	books.book[1].year = 2002;

	strcpy(books.book[2].name, "snow_queen");
	books.book[2].name[strlen(books.book[2].name)] = '\0';
	strcpy(books.book[2].author, "Andersen");
	books.book[2].author[strlen(books.book[2].author)] = '\0';
	strcpy(books.book[2].language, "ispanski");
	books.book[2].language[strlen(books.book[2].language)] = '\0';
	books.book[2].year = 2003;

	strcpy(books.book[3].name, "dracula");
	books.book[3].name[strlen(books.book[3].name)] = '\0';
	strcpy(books.book[3].author, "Stoker");
	books.book[3].author[strlen(books.book[3].author)] = '\0';
	strcpy(books.book[3].language, "ukrain");
	books.book[3].language[strlen(books.book[3].language)] = '\0';
	books.book[3].year = 2004;

	strcpy(books.book[4].name, "peopel_in_swamp");
	books.book[4].name[strlen(books.book[4].name)] = '\0';
	strcpy(books.book[4].author, "Ivan Melezh");
	books.book[4].author[strlen(books.book[4].author)] = '\0';
	strcpy(books.book[4].language, "belarus");
	books.book[4].language[strlen(books.book[4].language)] = '\0';
	books.book[4].year = 2005;

	books.count = 5;
}

void sortByAlphabet(Books& books)
{
	int len = 0;
	Books books1;

	for (int k = 0; k <= books.count; k++)
	{
		for (int i = k + 1; i < books.count; i++)
		{
			if (strlen(books.book[k].name) > strlen(books.book[i].name))
				len = strlen(books.book[i].name);
			else
				len = strlen(books.book[k].name);
			for (int j = 0; j < len; j++)
			{
				int a = int(books.book[k].name[j]);
				int b = int(books.book[i].name[j]);
				if (a > b)
				{
					books1.book[0] = books.book[k];
					books.book[k] = books.book[i];
					books.book[i] = books1.book[0];
					break;
				}
				else
					if (a == b)
						continue;
					else
						break;
			}
		}
	}
}

void sortByPrise(Books& books, char flag)
{
	Books books1;
	switch (flag)
	{
	case '1':
		for (int k = 0; k < books.count; k++)
		{
			for (int i = 0; i <= books.count - 1; i++)
			{
				for (int j = i + 1; j < books.count; j++)
				{
					if (books.book[i].year <= books.book[j].year)
						continue;
					else
					{
						books1.book[0] = books.book[i];
						books.book[i] = books.book[j];
						books.book[j] = books1.book[0];
						break;
					}
				}
			}
		}
		break;
	case '2':
		for (int k = 0; k < books.count; k++)
		{
			for (int i = 0; i <= books.count - 1; i++)
			{
				for (int j = i + 1; j < books.count; j++)
				{
					if (books.book[i].year >= books.book[j].year)
						continue;
					else
					{
						books1.book[0] = books.book[i];
						books.book[i] = books.book[j];
						books.book[j] = books1.book[0];
						break;
					}
				}
			}
		}
		break;
	default: cout << "Error!" << endl;
		break;
	}
}