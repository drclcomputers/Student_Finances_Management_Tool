#pragma once

#pragma warning(disable : 4996)

#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<cstdlib>
#include "conf.h"


using namespace std;

typedef int natural;


class savingsx {
public:

	natural buget, venit;

	void init();
	
	void savings_history();

	void savings_deposit();

	void savings_withdraw();

	void savingsv();

};