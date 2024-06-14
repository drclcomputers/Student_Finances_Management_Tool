#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
#include<windows.h>
#include<ctime>
#include<iomanip>

typedef int natural;

using namespace std;

class app {
public:
	natural buget = 1000, venit = 0;

	void showincome() {
		ifstream fin("income.pg", ios::app);
		for(int i=1; fin; i++) {
			char text[200]; fin.getline(text, 200);
			cout << i <<". " << text << '\n';
			fin.get();
		}
		cout << '\n';
		system("pause");
		fin.close();
	}

	void showexpense() {
		ifstream fin("expense.pg", ios::app);
		for (int i = 1; fin; i++) {
			char text[200]; fin.getline(text, 200);
			cout << i << ". " << text << '\n';
			fin.get();
		}
		cout << '\n';
		system("pause");
		fin.close();
	}

	void setbudget() {
		cout << "------------------Set-Budget------------------\n\n";
		cout << "Enter budget: "; cin >> buget;
		while (buget < 0) {
			cout << "Enter correct budget: ";
			cin >> buget;
		}
		ofstream fin("buget.pg", ios::trunc);
		fin << buget;
		fin.close();
	}

	void income() {
		cout << "------------------Income------------------\n\n";
		cout << "Enter income: ";
		natural suma; cin >> suma;
		while (suma < 0) {
			cout << "Enter correct income: ";
			cin >> suma;
		}
		venit += suma;
		cout << "Types:\n1. Scholarship\n2. Paycheck\n3. Sold stuff\n4. Others\n\nEnter income type: ";
		natural type; cin >> type;
		while (type < 0 || type>4) {
			cout << "Enter correct type of income: ";
			cin >> type;
		}
		ofstream fin("income.pg", ios::app);
		fin << suma << " ";
		if (type == 1) fin << "Scholarship";
		else if (type == 2) fin << "Paycheck";
		else if (type == 3) fin << "Sold-Stuff";
		else if (type == 4) {
			cout << "Custom income: ";
			char customtype[100]; cin.get(); cin.getline(customtype, 100);
			fin << customtype ;
		}


		time_t rawtime=time(0);
		char* date_time = ctime(&rawtime);
		fin << " " << date_time << '\n';


		fin.close();
		ofstream fin1("venit.pg", ios::trunc);
		fin1 << venit;
		fin1.close();
	}


	void expense() {
		cout << "------------------Expenses------------------\n\n";
		cout << "Enter expense: ";
		natural suma; cin >> suma;
		while (suma < 0) {
			cout << "Enter correct expense: ";
			cin >> suma;
		}
		venit -= suma;
		cout << "Types:\n1. Food\n2. Clothes\n3. Books\n4. Devices\n5. School Supplies\n6. Home Supplies\n7. Others\n\nEnter income type: ";
		natural type; cin >> type;
		while (type < 0 || type>7) {
			cout << "Enter correct type of expense: ";
			cin >> type;
		}
		ofstream fin("expense.pg", ios::app);
		fin << suma << " ";
		if (type == 1) fin << "Food";
		else if (type == 2) fin << "Clothes";
		else if (type == 3) fin << "Books";
		else if (type == 4) fin << "Devices";
		else if (type == 5) fin << "School-Supplies";
		else if (type == 6) fin << "Home-Supplies";
		else if (type == 7) {
			cout << "Custom expense: ";
			char customtype[101]; cin.get(); cin.getline(customtype, 100);
			fin << customtype << '\n';
		}


		time_t rawtime = time(0);
		char* date_time = ctime(&rawtime);
		fin << " " << date_time << '\n';


		fin.close();
		ofstream fin1("venit.pg", ios::trunc);
		fin1 << venit;
		fin1.close();
	}

	void start() {
		ifstream fin("venit.pg");
		fin >> venit;
		fin.close();
		ifstream fi1n("buget.pg");
		fi1n >> buget;
		fi1n.close();
		cout << "Money: " << venit << "      Budget: " << buget << '\n';
		if (venit >= buget) cout << "All good!\n";
		else if (venit <= buget / 2) cout << "Your income is kind of low!\n";
		else if (venit == 0) cout << "You're on the verge of bankruptcy\n";
		else if (venit <= 0) cout << "You're in debt!\n";
		cout << "$$$: ";  char com[21]; cin.getline(com, 21);
		if (strncmp(com, "income", 6)==0) {
			income();
		}
		else if (strncmp(com, "expense", 7)==0) {
			expense();
		}
		else if (strstr(com, "setbudget")) {
			setbudget();
		}
		else if (strstr(com, "exit")) {
			return;
		}
		else if (strstr(com, "showincome")) {
			showincome();
		}
		else if (strstr(com, "showexpense")) {
			showexpense();
		}
		system("cls");
		start();
	}


};