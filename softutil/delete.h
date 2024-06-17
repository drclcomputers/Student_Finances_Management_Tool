#pragma once
#pragma warning(disable : 4996)

#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<cstdlib>

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

int venit;

void init2() {
	ifstream fin("./files/venit.pg");
	fin >> venit;
	fin.close();
}

void put2() {
	ofstream fin("./files/venit.pg", ios::trunc);
	fin << venit;
	fin.close();
}

void deleteincome() {
	cout << "Value,  Type,  Date\n\n";
	ifstream fin("./files/income.pg");
	//fin.ignore();
	char text[202];
	for (int i = 1; fin; i++) {
		fin.getline(text, 200);
		cout << i << ". " << text << '\n';
		//fin.ignore();
	}
	cout << '\n';
	fin.close();

	ifstream init("./files/income.pg");
	ofstream temp("./files/temp.pg", ios::trunc);
	cout << "What entry to delete: ";
	int n; cin >> n;
	for (int i = 1; init; i++) {
		if (i == n) {
			init.getline(text, 200);
			char* p = strtok(text, " ");
			init2();
			if(p!=NULL)
				venit -= atoi(p);
			put2();
			temp << "Deleted!\n";
		}
		else{
			init.getline(text, 200);
			temp << text << '\n';
		}
	}
	init.close();
	temp.close();
	remove("./files/income.pg");
	rename("./files/temp.pg", "./files/income.pg");
	remove("./files/temp.pg");
}

void deleteexpense() {
	cout << "Value,  Type,  Date\n\n";
	ifstream fin("./files/expense.pg");
	//fin.ignore();
	char text[202];
	for (int i = 1; fin; i++) {
		fin.getline(text, 200);
		cout << i << ". " << text << '\n';
		//fin.ignore();
	}
	cout << '\n';
	fin.close();

	ifstream init("./files/expense.pg");
	ofstream temp("./files/temp.pg", ios::trunc);
	cout << "What entry to delete: ";
	int n; cin >> n;
	for (int i = 1; init; i++) {
		if (i == n) {
			init.getline(text, 200);
			char* p = strtok(text, " ");
			init2();
			if (p != NULL)
				venit += atoi(p);
			put2();
			temp << "Deleted!\n";
		}
		else {
			init.getline(text, 200);
			temp << text << '\n';
		}
	}
	init.close();
	temp.close();
	remove("./files/expense.pg");
	rename("./files/temp.pg", "./files/expense.pg");
	remove("./files/temp.pg");
}
