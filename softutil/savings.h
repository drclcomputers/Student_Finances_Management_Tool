#pragma once

#pragma warning(disable : 4996)

#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<cstdlib>


using namespace std;

typedef int natural;


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



class savingsx {
public:

	natural buget, venit;

	void init() {
		ifstream fin("./files/venit.pg");
		fin >> venit;
		fin.close();
		ifstream fi1n("./files/buget.pg");
		fi1n >> buget;
		fi1n.close();
	}
	
	void savings_history() {
		cout << right << '\n';
		cout << setw(6) << "Sum"
			<< setw(10) << " " << "Description"
			<< setw(10) << " " << "Date";
		cout << "\n\n";
		ifstream fin("./files/istoricsavings.pg", ios::app);
		for (int i = 1; fin; i++) {
			char text[200]; fin.getline(text, 200);
			cout << i << ". " << text << '\n';
			fin.get();
		}
		cout << '\n';
		fin.close();
		cin.get();
	}

	void savings_deposit() {
		cout << "\nEnter sum to deposit: ";
		natural suma, tot; cin >> suma;
		while (suma < 0) {
			cout << "Enter correct sum: ";
			cin >> suma;
		}
		venit -= suma;
		ifstream fin("./files/savings.pg");
		fin >> tot;
		fin.close();

		tot += suma;

		ofstream fin3("./files/savings.pg", ios::trunc);
		fin3 << tot;
		fin3.close();


		ofstream fin1("./files/venit.pg", ios::trunc);
		fin1 << venit;
		fin1.close();

		time_t rawtime = time(0);
		char* date_time = ctime(&rawtime);

		ofstream fin4("./files/istoricsavings.pg", ios::app);
		fin4 << "+" << suma << setw(10) << " " << "Deposit";
		fin4 << setw(10) << " " << date_time << '\n';

		fin4.close();

		ofstream fin5("./files/expense.pg", ios::app);
		fin5 << suma << setw(5) << " " << "Deposit";
		fin5 << setw(5) << " " << date_time << '\n';

	}

	void savings_withdraw() {
		cout << "\nEnter sum to withdraw: ";
		natural suma, tot; cin >> suma;
		while (suma < 0) {
			cout << "Enter correct sum: ";
			cin >> suma;
		}
		venit += suma;
		ifstream fin("./files/savings.pg");
		fin >> tot;
		fin.close();

		tot -= suma;

		ofstream fin3("./files/savings.pg", ios::trunc);
		fin3 << tot;
		fin3.close();


		ofstream fin1("./files/venit.pg", ios::trunc);
		fin1 << venit;
		fin1.close();

		time_t rawtime = time(0);
		char* date_time = ctime(&rawtime);

		ofstream fin4("./files/istoricsavings.pg", ios::app);
		fin4 << "-" << suma << setw(10) << " " << "Withdraw";
		fin4 << setw(10) << " " << date_time << '\n';

		fin4.close();

		ofstream fin5("./files/income.pg", ios::app);
		fin5 << suma << setw(5) << " " << "Withdraw";
		fin5 << setw(5) << " " << date_time << '\n';
	}

	void savingsv() {
		system(CLEAR_SCREEN);
		init();
		ifstream fin("./files/venit.pg");
		fin >> venit;
		fin.close();
		ifstream fi1n("./files/buget.pg");
		fi1n >> buget;
		fi1n.close();
		cout << YELLOW;
		cout << "Money: " << venit;
		cout << BLUE;
		cout << "      Budget: " << buget << '\n';
		cout << RED;
		int savings;
		ifstream fin3("./files/savings.pg");
		fin3 >> savings;
		fin3.close();
		cout << "Savings: " << savings << "\n\n";
		cout << WHITE;
		cout << "What do you want to do: \n1. Deposit\n2. Withdraw\n3. View History\n4. Exit\n\n> ";
		int choice; cin >> choice;
		while (choice > 4 || choice < 1) {
			cout << "Enter correct choice: ";
			cin >> choice;
		}
		if (choice == 4) return;
		else if (choice == 1) {
			savings_deposit();
		}
		else if (choice == 2) {
			savings_withdraw();
		}
		else {
			savings_history();
			cout << "Press any key to continue . . . ";
			cin.get();
		}
		system(CLEAR_SCREEN);
		savingsv();
	}

};