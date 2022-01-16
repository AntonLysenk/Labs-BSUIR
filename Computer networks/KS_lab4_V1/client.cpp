#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <istream>
#include <climits>
#include <unistd.h>

using namespace std;

struct Book {
	char name[50] = {};
	int year = 0;
	char author[20] = {};
	char language[15] = {};
};

struct Books {
	Book book[20];
	int count = 5;
} books;

int main(){

	struct sockaddr_in peer;
	int s,t,t1;
	int rc;
	char buf[256],p,p1,b[256];

	char* buffer = new char[sizeof(Books) + 1];
	bool a = true;
	int yearPub = 0;
	char languageWri[15] = {};
	char nameBook[50] = {};
	Books books1;

	peer.sin_family=AF_INET;
	peer.sin_port=htons(7500);
	inet_pton(AF_INET, "127.0.0.1", &(peer.sin_addr));

	s=socket(AF_INET,SOCK_STREAM,0);
	rc=connect(s,(struct sockaddr *)&peer,sizeof(peer));
while(true){
	short k = 0;
		cout << "1.Search by name" << endl;
		cout << "2.Search by year of publication" << endl;
		cout << "3.Search by writing language" << endl;
		cout << "4.Adding a book" << endl;
		cout << "5.Deleting a book" << endl;
		cout << "6.Sorting by year of publication" << endl;
		cout << "7.Sorting by name" << endl;
		cout << "8.Exit(black out)" << endl;
		cin >> k;
		buffer[0] = static_cast<char>(k);
		switch (k) {
		case 1:
			cout << "Enter the name of book: ";
			cin >> nameBook;
			cout << endl;
			memcpy(&buffer[1], &nameBook, sizeof(nameBook));
			send(s, buffer, sizeof(Books) + 1, 0);
			break;
		case 2:
			cout << "Enter the year of publication: ";
			cin >> yearPub;
			cout << endl;
			memcpy(&buffer[1], &yearPub, sizeof(yearPub));
			send(s, buffer, sizeof(Books) + 1, 0);
			break;
		case 3:
			cout << "Enter the writing language: ";
			cin >> languageWri;
			cout << endl;
			memcpy(&buffer[1], &languageWri, sizeof(languageWri));
			send(s, buffer, sizeof(Books) + 1, 0);
			break;
		case 4:
			cout << "Enter the name of book: ";
			cin >> books.book[0].name;
			cout << "Enter the author of book: ";
			cin >> books.book[0].author;
			cout << "Enter the language of book: ";
			cin >> books.book[0].language;
			cout << "Enter the year of publication: ";
			cin >> books.book[0].year;
			cout << endl;
			memcpy(&buffer[1], &books, sizeof(books));
			send(s, buffer, sizeof(Books) + 1, 0);
			break;
		case 5:
			cout << "Enter the name of deleting book: ";
			cin >> nameBook;
			cout << endl;
			memcpy(&buffer[1], &nameBook, sizeof(nameBook));
			send(s, buffer, sizeof(Books) + 1, 0);
			break;
		case 6:
			cout << "Select the sort type: " << endl;
			cout << "1.Old ones first" << endl;
			cout << "2.New ones first" << endl;
			cin >> buffer[1];
			cout << endl;
			send(s, buffer, sizeof(Books) + 1, 0);
			break;
		case 7:
			send(s, buffer, sizeof(Books) + 1, 0);
			break;
		case 8:
			send(s, buffer, sizeof(Books) + 1, 0);
			close(s);
            exit(0);
		default: cout << "Error, repeat please!" << endl;
			break;
		}

		if (recv(s, buffer, sizeof(Books) + 1, 0))
		{
			switch (buffer[0]) {
			case 1:
				memcpy(&books, &buffer[1], sizeof(Books));
				if (!books.count)
					cout << "There are no books for this name!" << endl;
				else
					for (int i = 0; i < books.count; i++) {
						cout << "Name: " << books.book[i].name << endl;
						cout << "Author: " << books.book[i].author << endl;
						cout << "Language: " << books.book[i].language << endl;
						cout << "Year of publication: " << books.book[i].year << endl << endl;
				    }
				break;
			case 2:
				memcpy(&books, &buffer[1], sizeof(Books));
				if (!books.count)
					cout << "There are no books for this year!" << endl;
				else 
					for (int i = 0; i < books.count; i++) {
						cout << "Name: " << books.book[i].name << endl;
						cout << "Author: " << books.book[i].author << endl;
						cout << "Language: " << books.book[i].language << endl;
						cout << "Year of publication: " << books.book[i].year << endl << endl;
					}
				break;
			case 3:
				memcpy(&books, &buffer[1], sizeof(Books));
				if (!books.count)
					cout << "There are no books for this language!" << endl;
				else
					for (int i = 0; i < books.count; i++) {
						cout << "Name: " << books.book[i].name << endl;
						cout << "Author: " << books.book[i].author << endl;
						cout << "Language: " << books.book[i].language << endl;
						cout << "Year of publication: " << books.book[i].year << endl << endl;
					}
				break;
			case 4:
				if (buffer[1])
					cout << "New book is added successfully!" << endl;
				else
					cout << "Error!" << endl;
				break;
			case 5:
				if (buffer[1])
					cout << "Book has been successfully deleted!" << endl;
				else
					cout << "A book with this name does't exist!" << endl;
				break;
			case 6:
				memcpy(&books, &buffer[1], sizeof(Books));
				if (!books.count)
					cout << "There are no books in the library!" << endl;
				for (int i = 0; i < books.count; i++) {
					cout << "Name: " << books.book[i].name << endl;
					cout << "Author: " << books.book[i].author << endl;
					cout << "Language: " << books.book[i].language << endl;
					cout << "Year of publication: " << books.book[i].year << endl << endl;
				}
				break;
			case 7: 
				memcpy(&books, &buffer[1], sizeof(Books));
				if (!books.count)
					cout << "There are no books in the library!" << endl;
				for (int i = 0; i < books.count; i++) {
					cout << "Name: " << books.book[i].name << endl;
					cout << "Author: " << books.book[i].author << endl;
					cout << "Language: " << books.book[i].language << endl;
					cout << "Year of publication: " << books.book[i].year << endl << endl;
				}
				break;
			case 8:
				break;
			default: cout << "Error!" << endl;
				break;
			}
		}
		cout << "Press enter to continue...";
		cin.ignore(INT_MAX,'\n'); 
		cin.get();
		system("clear");
	}
	return 0;
}