#pragma warning(disable : 4996)

#include "reset.h"
#include "card.h"
#include "loans.h"
#include "savings.h"
#include "delete.h"
#include "cryptographie.h"
#include "conf.h"


#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<cstdlib>

using namespace std;

typedef int natural;

class app {
public:
	natural buget, venit;

	void income();
	void expense();
	void showincome();
	void showexpense();
	void report();
	void setbudget();
	void help();
	void start();
};