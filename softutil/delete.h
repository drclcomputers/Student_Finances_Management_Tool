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

	fstream fin1("./files/income.pg", ios::beg);
	int n;
	cout << "What entry to remove: "; cin >> n;
	char text1[1000][200];
	for (int i = 1; i < 1000; i++)
		if (i == n)
			strcpy(text1[i], "Deleted!");
		else
			fin1.getline(text1[i], 200);
	fin1.open("./files/income.pg", ios::trunc);
	for (int i = 1; i < 1000; i++)
		fin1 << text1[i];
	fin1.close();
   
	/*cin.clear();
	cout << "\nWhat entry to delete: "; 
	int n; cin >> n;
	fstream fin1("./files/income.pg", ios::beg);
	fin1.clear();
	for (int i = 1; i < n; i++)
		fin1.ignore();
	//fin1.get();
	fin1 << "Deleted!                                                                       \n";
	fin1.close();*/
}
