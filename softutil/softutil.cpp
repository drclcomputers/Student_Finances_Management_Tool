#include "app.h"
#include "login.h"

int main() {
	login login;
	bool start=login.loginfunc();
	if (start==1) {
		app app;
		app.start();
	}

	return 0;
}