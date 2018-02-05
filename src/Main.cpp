#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "SunPosition.h"

using namespace std;

void main() {

	Time time;
	time.year = 2018;
	time.month = 2;
	time.day = 5;
	time.hours = 18;
	time.minutes = 46;
	time.seconds = 40;

	double eJD = JulianDays(time);

	cout.precision(10);
	cout << "elasped Julian Days: " << eJD << endl;

	_getch();
}