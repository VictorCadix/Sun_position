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

	int day = dayOfYear(time);
	cout << "day of the year: " << day << endl;

	double eqtime = eqTime(time);
	cout << "Equation of time: " << eqtime << endl;

	double decl = declination(time);
	decl = decl * 180 / pi;
	cout << "Declination: " << decl << " degrees" << endl;

	Position pos;
	pos.latitude = 35.5565;
	pos.longitude = -115.4708;
	pos.timezone = -8;

	double tst = trueSolarTime(time, pos);
	cout << "true solar time: " << tst << endl;

	double ha = hourAngle(tst);
	cout << "Hour angle: " << ha << endl;

	SunCoordinates sunPos;
	sunCoordinates(time, pos, &sunPos);
	cout << "Sun altitude: " << sunPos.altitude << " deg" << endl;
	cout << "Sun azimuth: " << sunPos.azimuth << " deg" << endl;

	Sunrise_sunet sun;
	UTCtimeOf_sunrise_sunset(time, pos, &sun);
	cout << "Sunrise at: " << sun.sunrise.hours << ":" << sun.sunrise.minutes << ":" << sun.sunrise.seconds << endl;
	cout << "Sunset at: " << sun.sunset.hours << ":" << sun.sunset.minutes << ":" << sun.sunset.seconds << endl;
	cout << "Noon at: " << sun.noon.hours << ":" << sun.noon.minutes << ":" << sun.noon.seconds << endl;
	_getch();
}