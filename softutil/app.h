#pragma warning(disable : 4996)

#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<cstdlib>

#include "cryptographie.h"
#include "card.h"
cardx crd;


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


typedef int natural;

using namespace std;

class app {
public:
	natural buget, venit;

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
		ofstream fin("./files/income.pg", ios::app);
		fin << suma;
		fin << setw(5) << " ";
		if (type == 1) fin << "Scholarship";
		else if (type == 2) fin << "Paycheck";
		else if (type == 3) fin << "Sold-Stuff";
		else if (type == 4) {
			cout << "Custom income: ";
			char customtype[100]; cin.ignore();  cin.getline(customtype, 100);
			fin << customtype;
		}

		fin << setw(5) << " ";
		time_t rawtime = time(0);
		char* date_time = ctime(&rawtime);
		fin << date_time << '\n';


		fin.close();
		ofstream fin1("./files/venit.pg", ios::trunc);
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
		ofstream fin("./files/expense.pg", ios::app);
		fin << suma;
		fin << setw(5) << " ";
		if (type == 1) fin << "Food";
		else if (type == 2) fin << "Clothes";
		else if (type == 3) fin << "Books";
		else if (type == 4) fin << "Devices";
		else if (type == 5) fin << "School-Supplies";
		else if (type == 6) fin << "Home-Supplies";
		else if (type == 7) {
			cout << "Custom expense: ";
			char customtype[101]; cin.ignore();  cin.getline(customtype, 100);
			fin << customtype;
		}

		fin << setw(5) << " ";
		time_t rawtime = time(0);
		char* date_time = ctime(&rawtime);
		fin << date_time << '\n';


		fin.close();
		ofstream fin1("./files/venit.pg", ios::trunc);
		fin1 << venit;
		fin1.close();
	}

	void setbudget() {
		cout << "------------------Set-Budget------------------\n\n";
		cout << "Enter budget: "; cin >> buget;
		while (buget < 0) {
			cout << "Enter correct budget: ";
			cin >> buget;
		}
		ofstream fin("./files/buget.pg", ios::trunc);
		fin << buget;
		fin.close();
	}


	void showincome() {
		cout << right;
		cout << setw(6) << "Sum"
			<< setw(5) << " " << "Description"
			<< setw(10) << " " << "Date";
		cout << "\n\n";
		ifstream fin("./files/income.pg", ios::app);
		for (int i = 1; fin; i++) {
			char text[200]; fin.getline(text, 200);
			cout << i << ". " << text << '\n';
			fin.get();
		}
		cout << '\n';
		fin.close();
	}

	void showexpense() {
		cout << right;
		cout << setw(6) << "Sum"
			<< setw(5) << " " << "Description"
			<< setw(10) << " " << "Date";
		cout << "\n\n";
		ifstream fin("./files/expense.pg", ios::app);
		for (int i = 1; fin; i++) {
			char text[200]; fin.getline(text, 200);
			cout << i << ". " << text << '\n';
			fin.get();
		}
		cout << '\n';
		fin.close();
	}


	void report() {
		int sum = 0;
		ifstream fin("./files/income.pg", ios::app);
		for (int i = 1; fin; i++) {
			char text[200]; fin.getline(text, 200);
			char *p = strtok(text, " ");
			if (p != NULL) {
				cout << "+" << p << "\n";
				sum += atoi(p);
			}
			fin.get();
		}
		fin.close();
		ifstream fin1("./files/expense.pg", ios::app);
		for (int i = 1; fin1; i++) {
			char text[200]; fin1.getline(text, 200);
			char* p = strtok(text, " ");
			if (p != NULL) {
				cout << "-" << p << "\n";
				sum -= atoi(p);
			}
			fin1.get();
		}
		fin1.close();
		cout << "----------------";
		cout << "\nTotal: " << sum << '\n';
		cout << '\n' << "Report: ";
		if (sum < 0) cout << "You shouldn't spend this much or maybe try to get a second source of income!";
		else if (sum == 0) cout << "You should try and save some money in a savings account!";
		else cout << "You're pretty good with managing your finances!";

		cout << '\n'<<'\n';
		
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


	void resetsavings() {
		cout << "Are you sure to delete all your savings: ";
		char ans[5]; cin >> ans;
		if (strcmp(ans, "yes")==0) {
			ofstream fin1("./files/savings.pg", ios::trunc);
			fin1.close();
			ofstream fin2("./files/istoricsavings.pg", ios::trunc);
			fin2.close();
		}
	}

	void resetincome() {
		cout << "Are you sure to delete all your incomes: ";
		char ans[5]; cin >> ans;
		if (strcmp(ans, "yes")==0) {
			ofstream fin1("./files/income.pg", ios::trunc);
			fin1.close();
		}
	}

	void resetexpense() {
		cout << "Are you sure to delete all your expenses: ";
		char ans[5]; cin >> ans;
		if (strcmp(ans, "yes")==0) {
			ofstream fin1("./files/expense.pg", ios::trunc);
			fin1.close();
		}
	}

	void resetcard() {
		cout << "Are you sure to delete all your cards: ";
		char ans[5]; cin >> ans;
		if (strcmp(ans, "yes") == 0) {
			ofstream fin1("./files/cards.pg", ios::trunc);
			fin1.close();
		}
	}

	void reset() {
		cout << "Are you sure to delete all your finances: ";
		char ans[5]; cin >> ans;
		if (strcmp(ans, "yes")==0) {
			ofstream fin2("./files/income.pg", ios::trunc);
			fin2.close();
			ofstream fin3("./files/expense.pg", ios::trunc);
			fin3.close();
			ofstream fin7("./files/istoricsavings.pg", ios::trunc);
			fin7.close();
			ofstream fin4("./files/buget.pg", ios::trunc);
			fin4 << 0;
			fin4.close();
			ofstream fin5("./files/venit.pg", ios::trunc);
			fin5 << 0;
			fin5.close();
			ofstream fin6("./files/savings.pg", ios::trunc);
			fin6 << 0;
			fin6.close();
			ofstream fin8("./files/logins/user.lg", ios::trunc);
			fin8.close();
			ofstream fin9("./files/logins/pass.lg", ios::trunc);
			fin9.close();
			ofstream fin10("./files/logins/cards.lg", ios::trunc);
			fin10.close();
			cout << "The program will shut down to delete all the files!\n\n";
			cout << "Press any key to continue . . . ";
			cin.ignore();
			cin.get();
			return;
		}
	}


	void help() {
		cout << "------------------Help------------------\n\n";
		cout << "income -> add new income entry\n";
		cout << "expense -> add new expense entry\n";
		cout << "card -> add new card\n";
		cout << "showincome -> show a list of all incomes\n";
		cout << "showexpense -> show a list of all expenses\n";
		cout << "showcard -> show a list of all cards\n";
		cout << "setbudget -> sets budget\n";
		cout << "exit -> exit the software\n";
		cout << "help -> show help menu\n";
		cout << "savings -> manage savings account\n";
		cout << "report -> generates a report with all incomes and expenses\n";
		cout << "resetincome -> delete all records of income\n";
		cout << "resetexpense -> delete all records of expenses\n";
		cout << "resetsavings -> reset all records of savings\n";
		cout << "reset -> reset all the data in the program\n\n";
	}


	void start() {
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
		if (venit >= buget) cout << "All good!\n";
		else if (venit <= buget / 2 && venit > 0) cout << "Your income is kind of low!\n";
		else if (venit == 0) cout << "You're on the verge of bankruptcy\n";
		else if (venit < 0) cout << "You're in debt!\n";
		cout << WHITE;
		cout << '\n';
		cout << "> ";  
		cout << GREEN;
		char com[21]; cin.getline(com, 21);
		cout << WHITE;
		if (strncmp(com, "income", 6)==0) {
			income();
		}
		else if (strncmp(com, "expense", 7)==0) {
			expense();
		}
		else if (strcmp(com, "setbudget")==0) {
			setbudget();
		}
		else if (strcmp(com, "exit")==0) {
			cout << "All transactions were saved automatically.\n";
			cout << "Press any key to continue . . . ";
			cin.get();
			return;
		}
		else if (strcmp(com, "showincome")==0) {
			showincome();
			cout << "Press any key to continue . . . ";
			cin.get();
		}
		else if (strcmp(com, "showexpense")==0) {
			showexpense();
			cout << "Press any key to continue . . . ";
			cin.get();
		}
		else if (strcmp(com, "resetincome")==0) {
			resetincome();
		}
		else if (strcmp(com, "resetexpense")==0) {
			resetexpense();
		}
		else if (strcmp(com, "resetsavings")==0) {
			resetsavings();
		}
		else if (strcmp(com, "resetcard") == 0) {
			resetcard();
		}
		else if (strcmp(com, "reset")==0) {
			reset();
			return;
		}
		else if (strcmp(com, "savings")==0) {
			savingsv();
		}
		else if (strcmp(com, "report")==0) {
			report();
			cout << "Press any key to continue . . . ";
			cin.get();
		}
		else if (strcmp(com, "help")==0) {
			help();
			cout << "Press any key to continue . . . ";
			cin.get();
		}
		else if (strcmp(com, "showcard")==0) {
			crd.show();
			cout << "Press any key to continue . . . ";
			cin.get();
		}
		else if (strcmp(com, "card")==0) {
			crd.add();
		}
		system(CLEAR_SCREEN);
		start();
	}
};