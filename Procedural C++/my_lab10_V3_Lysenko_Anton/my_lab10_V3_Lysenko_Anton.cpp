#include <iostream>
#include <io.h>

using namespace std;

struct Phone_database {
	char Number[15];
	char Surname[15];
	char Address[15];
};

Phone_database SortAlpha();
int CreateBinFile(void);
int RemoveBinFile(void);
int WriteData(void);
int DataProcess(void);
char ToUpper(char);
char ToLower(char);
int OutScreen(void);
int OutFile(void);
int Menu(void);


FILE* fl;
char NameBin[15], WayBin[30] = "Outputs\\", WayText[30] = "Outputs\\";

Phone_database* Subscriber;

int n, k = 0;

int main() {

	while (true) {
		switch (Menu()) {
		case 1: CreateBinFile(); break;
		case 2: WriteData(); break;
		case 3: DataProcess(); break;
		case 4: OutScreen(); break;
		case 5: OutFile(); break;
		case 6: RemoveBinFile(); delete[] Subscriber; return 0;
		default: cout << "Error!"; break;
		}
		system("pause");
		system("cls");
	}
}

Phone_database SortAlpha() {

	Phone_database Subscriber_1;

	Subscriber_1 = Subscriber[k];

	for (int i = 1; (i < n) && ((i + k) < n); i++) {

		if (Subscriber[k].Surname[0] > Subscriber[i + k].Surname[0]) {
			Subscriber_1 = Subscriber[i + k];
			Subscriber[i + k] = Subscriber[k];
			Subscriber[k] = Subscriber_1;
		}

		else if (Subscriber[k].Surname[0] == Subscriber[i + k].Surname[0])

			for (int j = 0; j < strlen(Subscriber[i + k].Surname); j++) {

				if (Subscriber[k].Surname[j] == Subscriber[i + k].Surname[j]) continue;
				else if (Subscriber[k].Surname[j] > Subscriber[i + k].Surname[j]) {
					Subscriber_1 = Subscriber[i + k];
					Subscriber[i + k] = Subscriber[k];
					Subscriber[k] = Subscriber_1;
				}
				break;
			}

	}
	return Subscriber_1;
}

char ToUpper(char ch) {
	if (ch >= 'a' && ch <= 'z')
		return (char)(ch - 32);
	return ch;
}

char ToLower(char ch) {
	if (ch >= 'A' && ch <= 'Z')
		return (char)(ch + 32);
	return ch;
}

int CreateBinFile() {
	
	cout << "Enter the name of the binary file: " << endl;
	cin >> NameBin; 
	strcat_s(WayBin, NameBin);
	errno_t err = fopen_s(&fl, WayBin, "wb");
	if (err) {
		cout << "The file was not created";
		return 1;
	}
	return 0;
}

int WriteData() {
	
	cout << "Enter the number of subscribers: ";
	cin >> n;
	Subscriber = new Phone_database[n];

	for (int i = 0; i < n; i++) {
		cout << "Enter the last name of " << i + 1 << " subscriber: ";
		cin >> Subscriber[i].Surname;
		Subscriber[i].Surname[0] = ToUpper(Subscriber[i].Surname[0]);
		for (int j = 1; j < strlen(Subscriber[i].Surname); j++)
			Subscriber[i].Surname[j] = ToLower(Subscriber[i].Surname[j]);
		cout << "Enter the address of " << i + 1 << " subscriber: ";
		cin >> Subscriber[i].Address;
		cout << "Enter the number of " << i + 1 << " subscriber: ";
		cin >> Subscriber[i].Number;
		cout << endl;
		fwrite(&Subscriber[i], sizeof(Phone_database), 1, fl);
	}
	fclose(fl);
	return 0;
}

int RemoveBinFile() {
	if (remove(WayBin) != 0) cout << "Error deleting a file" << endl;
	else cout << "A binary file is deleted successfully" << endl;
	return 0;
}

int DataProcess() {

	errno_t err = fopen_s(&fl, WayBin, "rb");
	if (err) {
		cout << "The file was not open";
		return 1;
	}

	for (int i = 0; i < n; i++) {
		fread(&Subscriber[i], sizeof(Phone_database), 1, fl);
	}

	for (int i = 0; i < n; i++) {
		Subscriber[i] = SortAlpha();
		k++;
	}
	fclose(fl);
	return 0;
}

int OutScreen() {

	for (int i = 0; i < n; i++) {
		if (Subscriber[i].Number[0] == '3') {
			cout << "Subcriber " << i + 1 << endl;
			cout << Subscriber[i].Surname << endl;
			cout << Subscriber[i].Address << endl;
			cout << Subscriber[i].Number << endl;
		}
	}
	return 0;
}

int OutFile() {
	char OutText[15];
	cout << "Enter the name of the out text file: " << endl;
	cin >> OutText;
	strcat_s(WayText, OutText);
	FILE* ft;
	errno_t err1 = fopen_s(&ft, WayText, "w");
	if (err1) {
		cout << "The file was not created";
		return 1;
	}
	for (int i = 0; i < n; i++) {
		if (Subscriber[i].Number[0] == '3') {
			fprintf(ft, "Subscriber %d\n", i + 1);
			fprintf(ft, "%s\n", Subscriber[i].Surname);
			fprintf(ft, "%s\n", Subscriber[i].Address);
			fprintf(ft, "%s\n", Subscriber[i].Number);
			fprintf(ft, "\n");
		}
	}
	fclose(ft);
	return 0;
}

int Menu() {
	int k;
	cout << "Select: " << endl;
	cout << "1. Creating a binary file" << endl;
	cout << "2. Writing data to a file" << endl;
	cout << "3. Opening a file, reading data from it and completing a task" << endl;
	cout << "4. Displaying the result on the screen" << endl;
	cout << "5. Output the result to a text file" << endl;
	cout << "6. Exit and remove Bin file" << endl;
	cin >> k;
	return k;
}

