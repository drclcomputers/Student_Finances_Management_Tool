#pragma once

int main() {
	login login;
	int start = login.loginfunc();
	if (start == 1) {
		app app;
		app.start();
	}
	else if (start == 2) {
		reset();
	}

	return 0;
}