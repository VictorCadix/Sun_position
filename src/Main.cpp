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
	cout << "Sunrise at: " << sun.sunrise.hours + pos.timezone << ":" << sun.sunrise.minutes << ":" << sun.sunrise.seconds << endl;
	cout << "Sunset at: " << sun.sunset.hours + pos.timezone << ":" << sun.sunset.minutes << ":" << sun.sunset.seconds << endl;
	cout << "Noon at: " << sun.noon.hours + pos.timezone << ":" << sun.noon.minutes << ":" << sun.noon.seconds << endl;


	cout << "Test trayectory" << endl;
	float trayectory[15][3] = { { 150,1.9,110.6 },{ 200,9.7,118.3 },{ 250,16.9,126.7 },{ 300,23.3,136.1 },{ 350,28.7,146.7 },{ 400,32.6,158.5 },{ 450,34.8,171.4 },{ 500,35.2,184.7 },{ 550,33.4,197.7 },{ 600,30.0,209.9 },{ 650,25.1,220.9 },{ 700,18.9,230.6 },{ 750,11.9,239.3 },{ 800,4.27,247.1 },{ 850,0,90 } }; //8 puntos
	int totalTrayec = 15;
	int deltaTime = 60; //seconds

	for (int i = 0; i < totalTrayec; i++) {

		sunCoordinates(time, pos, &sunPos);
		trayectory[i][0] = 180 + deltaTime * i;
		trayectory[i][1] = sunPos.altitude;
		trayectory[i][2] = sunPos.azimuth;

		time.seconds += deltaTime;
		if (time.seconds >= 60) {
			time.seconds -= 60;
			time.minutes++;
		}
		if (time.minutes >= 60) {
			time.minutes -= 60;
			time.hours++;
		}

	} //Fin bucle for
	_getch();
}