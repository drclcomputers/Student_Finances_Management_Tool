#pragma once

#include<fstream>
#include<iostream>

using namespace std;


void resetsavings() {
	cout << "Are you sure to delete all your savings: ";
	char ans[5]; cin >> ans;
	if (strcmp(ans, "yes") == 0) {
		ofstream fin1("./files/savings.pg", ios::trunc);
		fin1.close();
		ofstream fin2("./files/istoricsavings.pg", ios::trunc);
		fin2.close();
	}
}

void resetincome() {
	cout << "Are you sure to delete all your incomes: ";
	char ans[5]; cin >> ans;
	if (strcmp(ans, "yes") == 0) {
		ofstream fin1("./files/income.pg", ios::trunc);
		fin1.close();
	}
}

void resetexpense() {
	cout << "Are you sure to delete all your expenses: ";
	char ans[5]; cin >> ans;
	if (strcmp(ans, "yes") == 0) {
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

void resetloan() {
	cout << "Are you sure to delete all your loans: ";
	char ans[5]; cin >> ans;
	if (strcmp(ans, "yes") == 0) {
		ofstream fin1("./files/loans.pg", ios::trunc);
		fin1.close();
	}
}

void reset() {
	cout << "Are you sure to delete all your finances: ";
	char ans[5]; cin >> ans;
	if (strcmp(ans, "yes") == 0) {
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
		ofstream fin10("./files/cards.pg", ios::trunc);
		fin10.close();
		ofstream fin11("./files/loans.pg", ios::trunc);
		fin11.close();
		cout << "The program will shut down to delete all the files!\n\n";
		cout << "Press any key to continue . . . ";
		cin.ignore();
		cin.get();
		return;
	}
}
