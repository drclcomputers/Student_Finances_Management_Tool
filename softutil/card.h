#pragma warning(disable : 4996)

#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<cstdlib>

#include "cryptographie.h"
cryptographiex crypto1;

using namespace std;

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define WHITE "\033[37m"
#define BLUE "\033[34m"

class cardx{
public:
	void show() {
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

	void add() {
		cout << "------------------Add-Card------------------\n\nEnter card number: ";
		//cin.ignore();
		char numar[40]; cin.getline(numar, 20);
		cout << "R: " << numar << '\n';
		cout << "Enter expiration month: ";
		char month[3], year[5], cvc[4]; cin.getline(month, 3);
		//cin.get();
		cout << "Enter expiration year: ";
		cin.getline(year, 5);
		//cin.get();
		cout << "Enter CVC: ";
		cin.getline(cvc, 4);
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
		if (strcmp(choice, "1")==0) strcat(linie, "Debit");
		else strcat(linie, "Credit");
		strcpy(linie, crypto1.encrypt(linie, 10));
		fin << linie << '\n';
		fin.close();
	}
};