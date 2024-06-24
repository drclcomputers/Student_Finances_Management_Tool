#include "card.h"
#include "cryptographie.h"
cryptographiex crypto1;

void cardx::show() {
	cout << "Number,   Expiration Month/Expiration Year,   CVC,   Type\n\n";
	ifstream fin("./files/cards.pg");
	//fin.ignore();
	for (int i = 1; fin; i++) {
		char text[302]; fin.getline(text, 300);
		strcpy(text, crypto1.decrypt(text, 10));
		cout << i << ". " << text << '\n';
		fin.ignore();
	}
	cout << '\n';
	fin.close();
}

void cardx::add() {
	cout << "------------------Add-Card------------------\n\nEnter card number: ";
	//cin.ignore();
	char numar[40]; cin.getline(numar, 20);
	//cout << "R: " << numar << '\n';
	char month[10], year[10], cvc[10]; 
	cout << "Enter expiration month: ";
	cin.getline(month, 9);

	//check month
	int month2 = atoi(month);
	while (month2 < 1 || month2>12) {
		cout << "Enter correct month: ";
		cin.getline(month, 9);
		month2 = atoi(month);
	}

	//cin.get();
	cout << "Enter expiration year (last 2 digits): ";
	cin.getline(year, 9);

	//check year
	month2 = atoi(year);
	while (month2 < 24 || month2>40) {
		cout << "Enter correct year (last 2 digits): ";
		cin.getline(year, 9);
		month2 = atoi(year);
	}

	//cin.get();
	cout << "Enter CVC: ";
	cin.getline(cvc, 9);

	//check CVC
	month2 = atoi(cvc);
	while (month2 < 100 || month2>999) {
		cout << "Enter correct CVC: ";
		cin.getline(cvc, 9);
		month2 = atoi(cvc);
	}


	//cin.get();
	cout << "Choose type: \n1. Debit\n2. Credit\n";
	char choice[2]; cin.getline(choice, 2);
	//cin.get();
	ofstream fin("./files/cards.pg", ios::app);
	char linie[200]=" ";
	strcat(linie, numar);
	strcat(linie, "     ");
	strcat(linie, month);
	strcat(linie, "/");
	strcat(linie, year);
	strcat(linie, "     ");
	strcat(linie, cvc);
	strcat(linie, "     ");
	if (strcmp(choice, "1") == 0) strcat(linie, "Debit");
	else strcat(linie, "Credit");
	//cout << linie;
	//cin.get();
	strcpy(linie, crypto1.encrypt(linie, 10));
	fin << linie << '\n';
	fin.close();
}