#include "loans.h"
#include "cryptographie.h"
cryptographiex crypto2;

void loanx::show() {
	cout << "Name,  Total Value,  Months,  Monthly Payment\n\n";
	ifstream fin("./files/loans.pg");
	fin.ignore();
	for (int i = 1; fin; i++) {
		char text[302]; fin.getline(text, 300);
		strcpy(text, crypto2.decrypt(text, 10));
		cout << i << ". " << text << '\n';
		fin.ignore();
	}
	cout << '\n';
	fin.close();
}

void loanx::add() {
	//cin.ignore();
	cout << "------------------Add-Loan------------------\n\nEnter loan name: ";
	char nume[200]; cin.getline(nume, 199);
	cout << "Enter loan value: ";
	char value[100]; cin.getline(value, 99);

	int month2 = atoi(value);
	while (month2 < 0 || month2>2147000000) {
		cout << "Enter correct value: ";
		cin.getline(value, 99);
		month2 = atoi(value);
	}

	cout << "Enter number of monthly payments: ";
	char nr[11]; cin.getline(nr, 10);

	month2 = atoi(nr);
	while (month2 < 1 || month2>100000) {
		cout << "Enter correct number of payments: ";
		cin.getline(nr, 99);
		month2 = atoi(nr);
	}

	int valu = stoi(value), months = stoi(nr);
	char val[20]; sprintf(val, "%d", valu / months);

	char line[302] = " ";
	strcat(line, nume);
	strcat(line, "     ");
	strcat(line, value);
	strcat(line, "     ");
	strcat(line, nr);
	strcat(line, "     ");
	strcat(line, val);
	strcpy(line, crypto2.encrypt(line, 10));
	ofstream fin("./files/loans.pg", ios::app);
	fin << line << '\n';
	fin.close();
}