#pragma once
#pragma warning(disable : 4996)

#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<cstdlib>

#include "cryptographie.h"

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

cryptographiex crypto2;

class loanx {
public:
	void show() {
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

	void add(){
		//cin.ignore();
		cout << "------------------Add-Loan------------------\n\nEnter loan name: ";
		char nume[200]; cin.getline(nume, 199);
		cout << "Enter loan value: ";
		char value[100]; cin.getline(value, 99);
		cout << "Enter number of monthly payments: ";
		char nr[4]; cin.getline(nr, 3);
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
};
