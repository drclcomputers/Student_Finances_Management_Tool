#pragma warning(disable : 4996)

#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<cstdlib>

#include "cryptographie.h"


#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define WHITE "\033[37m"

cryptographiex crypto;

using namespace std;

class login {
public:
	void welcome() {
		cout << "Finance Software for Students\n\n";

		cout << "Press any key to continue . . . ";
		cin.get();
		system(CLEAR_SCREEN);
	}

	void check() {
		ifstream fin("./files/logins/user.lg");
		if (fin.peek() == ifstream::traits_type::eof()) {
			fin.close();
			ofstream fin2("./files/logins/user.lg");
			ofstream fin1("./files/logins/pass.lg", ios::trunc);
			cout << YELLOW << "Create account\n\n";
			cout << WHITE << "It appears that no user exists. Enter new user: ";
			char user[50]; cin.getline(user, 50);
			if (strcmp(user, "exit") == 0) return;
			fin2 << crypto.encrypt(user, 12);
			
			cout << "Enter new password: ";
			char pass[50]; cin.getline(pass, 50);
			if (strcmp(pass, "exit") == 0) return;
			fin1 << crypto.encrypt(pass, 12);
			
			cout << "Now, you'll be directed to the login screen.\n\n";
			cout << WHITE << "Press any key to continue . . . ";
			cin.get();
			system(CLEAR_SCREEN);
			fin1.close();
			fin2.close();
		}
		fin.close();
	}

	void logs(char *s) {
		ofstream fin("./files/logs/login.logpg", ios::app);

		time_t rawtime = time(0);
		char* date_time = ctime(&rawtime);

		fin << "New session created by user '" << s << "' on " << date_time << '\n';

		fin.close();
	}


	bool loginfunc() {
		welcome();
		check();
		cout << YELLOW << "Login\n\n" << WHITE;
		cout <<"User: ";
		char user[50], realuser[50]; cin.getline(user, 50);
		strcpy(user, crypto.encrypt(user, 12));
		if (strcmp(user, "exit") == 0) return 0;

		ifstream fin("./files/logins/user.lg");
		fin.getline(realuser, 50);
		fin.close();

		while(strcmp(user, realuser) != 0) {
			cout << RED << "Incorrect User! Enter correct user (type 'exit' to exit): " << WHITE;
			cin.getline(user, 50);
			if (strcmp(user, "exit") == 0) return 0;
		}

		cout << WHITE << "Password: ";
		char pass[50], realpass[50]; cin.getline(pass, 50);
		strcpy(pass, crypto.encrypt(pass, 12));
		if (strcmp(pass, "exit") == 0) return 0;
		

		ifstream fin1("./files/logins/pass.lg");
		fin1.getline(realpass, 50);
		fin1.close();


		while (strcmp(pass, realpass) != 0) {
			cout << RED << "Incorrect Password! Enter correct password (type 'exit' to exit): " << WHITE;
			cin.getline(pass, 50);
			if (strcmp(pass, "exit") == 0) return 0;
		}

		cout << GREEN << "\nAcces granted!\n\n";

		strcpy(user, crypto.decrypt(user, 12));

		logs(user);

		cout << WHITE << "Press any key to continue . . . ";
		cin.get();
		system(CLEAR_SCREEN);
		return 1;
	}

};