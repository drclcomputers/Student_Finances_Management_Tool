#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
#include<ctime>
#include<iomanip>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

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
		ofstream fin("income.pg", ios::app);
		fin << suma;
		fin << setw(5) << " ";
		if (type == 1) fin << "Scholarship";
		else if (type == 2) fin << "Paycheck";
		else if (type == 3) fin << "Sold-Stuff";
		else if (type == 4) {
			cout << "Custom income: ";
			char customtype[100]; cin.get(); cin.getline(customtype, 100);
			fin << customtype;
		}

		fin << setw(5) << " ";
		time_t rawtime = time(0);
		char* date_time = ctime(&rawtime);
		fin << date_time << '\n';


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
			char customtype[101]; cin.get(); cin.getline(customtype, 100);
			fin << customtype;
		}

		fin << setw(5) << " ";
		time_t rawtime = time(0);
		char* date_time = ctime(&rawtime);
		fin << date_time << '\n';


		fin.close();
		ofstream fin1("venit.pg", ios::trunc);
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
		ofstream fin("buget.pg", ios::trunc);
		fin << buget;
		fin.close();
	}


	void showincome() {
		cout << right;
		cout << setw(6) << "Sum"
			<< setw(5) << " " << "Description"
			<< setw(10) << " " << "Date";
		cout << "\n\n";
		ifstream fin("income.pg", ios::app);
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
		ifstream fin("expense.pg", ios::app);
		for (int i = 1; fin; i++) {
			char text[200]; fin.getline(text, 200);
			cout << i << ". " << text << '\n';
			fin.get();
		}
		cout << '\n';
		fin.close();
	}


	void savings_deposit() {
		cout << "\nEnter sum to deposit: ";
		natural suma, tot; cin >> suma;
		while (suma < 0) {
			cout << "Enter correct sum: ";
			cin >> suma;
		}
		venit -= suma;
		ifstream fin("savings.pg");
		fin >> tot;
		fin.close();

		tot += suma;

		ofstream fin3("savings.pg", ios::trunc);
		fin3 << tot;
		fin3.close();
		

		ofstream fin1("venit.pg", ios::trunc);
		fin1 << venit;
		fin1.close();
	}

	void savings_withdraw() {
		cout << "\nEnter sum to withdraw: ";
		natural suma, tot; cin >> suma;
		while (suma < 0) {
			cout << "Enter correct sum: ";
			cin >> suma;
		}
		venit += suma;
		ifstream fin("savings.pg");
		fin >> tot;
		fin.close();

		tot -= suma;

		ofstream fin3("savings.pg", ios::trunc);
		fin3 << tot;
		fin3.close();


		ofstream fin1("venit.pg", ios::trunc);
		fin1 << venit;
		fin1.close();
	}

	void savingsv() {
		system(CLEAR_SCREEN);
		ifstream fin("venit.pg");
		fin >> venit;
		fin.close();
		ifstream fi1n("buget.pg");
		fi1n >> buget;
		fi1n.close();
		cout << "Money: " << venit << "      Budget: " << buget << '\n';
		int savings;
		ifstream fin3("savings.pg");
		fin3 >> savings;
		fin3.close();
		cout << "Savings: " << savings << "\n\n";
		cout << "What do you want to do: \n1. Deposit\n2. Withdraw\n3. Exit\n\n> ";
		int choice; cin >> choice;
		while (choice > 4 || choice < 1) {
			cout << "Enter correct choice: ";
			cin >> choice;
		}
		if (choice == 3) return;
		else if (choice == 1) {
			savings_deposit();
		}
		else {
			savings_withdraw();
		}
		system(CLEAR_SCREEN);
		savingsv();
	}


	void resetsavings() {
		cout << "Are you sure to delete all your savings: ";
		char ans[5]; cin >> ans;
		if (strstr(ans, "yes")) {
			ofstream fin1("savings.pg", ios::trunc);
			fin1.close();
		}
	}

	void resetincome() {
		cout << "Are you sure to delete all your incomes: ";
		char ans[5]; cin >> ans;
		if (strstr(ans, "yes")) {
			ofstream fin1("income.pg", ios::trunc);
			fin1.close();
		}
	}

	void resetexpense() {
		cout << "Are you sure to delete all your expenses: ";
		char ans[5]; cin >> ans;
		if (strstr(ans, "yes")) {
			ofstream fin1("expense.pg", ios::trunc);
			fin1.close();
		}
	}

	void reset() {
		cout << "Are you sure to delete all your incomes: ";
		char ans[5]; cin >> ans;
		if (strstr(ans, "yes")) {
			ofstream fin2("income.pg", ios::trunc);
			fin2.close();
			ofstream fin3("expense.pg", ios::trunc);
			fin3.close();
			ofstream fin4("buget.pg", ios::trunc);
			fin4 << 0;
			fin4.close();
			ofstream fin5("venit.pg", ios::trunc);
			fin5 << 0;
			fin5.close();
			ofstream fin6("savings.pg", ios::trunc);
			fin6 << 0;
			fin6.close();
		}
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
		else if (venit <= buget / 2 && venit > 0) cout << "Your income is kind of low!\n";
		else if (venit == 0) cout << "You're on the verge of bankruptcy\n";
		else if (venit < 0) cout << "You're in debt!\n";
		cout << '\n';
		cout << "> ";  char com[21]; cin.getline(com, 21);
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
			cout << "All transactions were saved automatically.\n";
			cout << "Press any key to continue . . . ";
			cin.get();
			return;
		}
		else if (strstr(com, "showincome")) {
			showincome();
			cout << "Press any key to continue . . . ";
			cin.get();
		}
		else if (strstr(com, "showexpense")) {
			showexpense();
			cout << "Press any key to continue . . . ";
			cin.get();
		}
		else if (strstr(com, "resetincome")) {
			resetincome();
		}
		else if (strstr(com, "resetexpense")) {
			resetexpense();
		}
		else if (strstr(com, "resetsavings")) {
			resetsavings();
		}
		else if (strstr(com, "reset")) {
			reset();
		}
		else if (strstr(com, "savings")) {
			savingsv();
		}
		system(CLEAR_SCREEN);
		start();
	}
};