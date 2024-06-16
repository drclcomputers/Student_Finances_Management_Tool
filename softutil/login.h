#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<cstdlib>


#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define WHITE "\033[37m"

using namespace std;

class login {
public:
	void check() {
		ifstream fin("./files/logins/user.lg");
		if (fin.peek() == ifstream::traits_type::eof()) {
			fin.close();
			ofstream fin2("./files/logins/user.lg");
			ofstream fin1("./files/logins/pass.lg", ios::trunc);
			cout << YELLOW << "Create account\n\n" << WHITE;
			cout << "It appears that no user exists. Enter new user: ";
			char user[50]; cin.getline(user, 50);
			if (strcmp(user, "exit") == 0) return;
			fin2 << user;
			
			cout << "Enter new password: ";
			char pass[50]; cin.getline(pass, 50);
			if (strcmp(pass, "exit") == 0) return;
			fin1 << pass;
			
			cout << "Now, you'll be directed to the login screen.\n\n";
			cout << WHITE << "Press any key to continue . . . ";
			cin.get();
			system(CLEAR_SCREEN);
			fin1.close();
			fin2.close();
		}
		fin.close();
	}


	bool loginfunc() {
		check();
		cout << YELLOW << "Login\n\n" << WHITE;
		cout <<"User: ";
		char user[50], realuser[50]; cin.getline(user, 50);

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
		cout << WHITE << "Press any key to continue . . . ";
		cin.get();
		system(CLEAR_SCREEN);
		return 1;
	}

};