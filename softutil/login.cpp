#include "login.h"

#include "cryptographie.h"

cryptographiex crypto;

void login::welcome() {
	cout << "Finance Software for Students\n\n";

	cout << "Press any key to continue . . . ";
	cin.get();
	system(CLEAR_SCREEN);
}

int login::check() {
	ifstream fin("./files/logins/user.lg");
	if (fin.peek() == ifstream::traits_type::eof()) {
		fin.close();
		ofstream fin2("./files/logins/user.lg");
		ofstream fin1("./files/logins/pass.lg", ios::trunc);
		cout << YELLOW << "Create account\n\n";
		cout << WHITE << "It appears that no user exists. Enter new user: ";
		char user[50]; cin.getline(user, 50);
		if (strcmp(user, "exit") == 0) return 0;
		if (strcmp(user, "reset") == 0) return 2;
		fin2 << crypto.encrypt(user, 12);

		cout << "Enter new password: ";
		char pass[50]; cin.getline(pass, 50);
		if (strcmp(pass, "exit") == 0) return 0;
		if (strcmp(pass, "reset") == 0) return 2;
		fin1 << crypto.encrypt(pass, 12);

		cout << "Now, you'll be directed to the login screen.\n\n";
		cout << WHITE << "Press any key to continue . . . ";
		cin.get();
		system(CLEAR_SCREEN);
		fin1.close();
		fin2.close();
	}
	fin.close();
	return 1;
}

void login::logs(char* s) {
	ofstream fin("./files/logs/login.logpg", ios::app);

	time_t rawtime = time(0);
	char* date_time = ctime(&rawtime);

	fin << "New session created by user '" << s << "' on " << date_time << '\n';

	fin.close();
}

int login::loginfunc() {
	welcome();
	int o = check();
	if (o == 0) return 0;
	if (o == 2) return 2;
	cout << YELLOW << "Login\n\n" << WHITE;
	cout << "User: ";
	char user[50], realuser[50]; cin.getline(user, 50);
	if (strcmp(user, "exit") == 0) return 0;
	if (strcmp(user, "reset") == 0) return 2;
	strcpy(user, crypto.encrypt(user, 12));

	ifstream fin("./files/logins/user.lg");
	fin.getline(realuser, 50);
	fin.close();

	while (strcmp(user, realuser) != 0) {
		cout << RED << "Incorrect User! Enter correct user (type 'exit' to exit): " << WHITE;
		cin.getline(user, 50);
		if (strcmp(user, "exit") == 0) return 0;
		if (strcmp(user, "reset") == 0) return 2;
		strcpy(user, crypto.encrypt(user, 12));
	}

	cout << WHITE << "Password: ";
	char pass[50], realpass[50]; cin.getline(pass, 50);
	if (strcmp(pass, "exit") == 0) return 0;
	if (strcmp(pass, "reset") == 0) return 2;
	strcpy(pass, crypto.encrypt(pass, 12));


	ifstream fin1("./files/logins/pass.lg");
	fin1.getline(realpass, 50);
	fin1.close();


	while (strcmp(pass, realpass) != 0) {
		cout << RED << "Incorrect Password! Enter correct password (type 'exit' to exit): " << WHITE;
		cin.getline(pass, 50);
		if (strcmp(pass, "exit") == 0) return 0;
		if (strcmp(pass, "reset") == 0) return 2;
		strcpy(pass, crypto.encrypt(pass, 12));
	}

	cout << GREEN << "\nAcces granted!\n\n";

	strcpy(user, crypto.decrypt(user, 12));

	logs(user);

	cout << WHITE << "Press any key to continue . . . ";
	cin.get();
	system(CLEAR_SCREEN);
	return 1;
}