#pragma once

#define pi 3.14159265358979323846

typedef struct Time {
	int year;
	int month;
	int day;
	int hours;
	int minutes;
	int seconds;
};


double JulianDays(Time time) {
	int Y = time.year;
	int M = time.month;
	int D = time.day;
	int hour = time.hours;
	int min = time.minutes;
	int sec = time.seconds;

	int JDN;	//Julian day number
	double JD;	//Julian day
	double eJD;	//elapsed days since J2000.0

	JDN = (1461.0 * (Y + 4800.0 + (M - 14.0) / 12.0)) / 4.0 + (367.0 * (M - 2.0 - 12.0 * ((M - 14.0) / 12.0))) / 12.0 - (3.0 * ((Y + 4900.0 + (M - 14.0) / 12.0) / 100.0)) / 4.0 + D - 32075.0;
	JD = JDN + (hour - 12.0) / 24.0 + min / 1440.0 + sec / 86400.0;
	eJD = JD - 2451545.0;

	return eJD;
}


int dayOfYear(Time time) {
	Time startOfYear;
	startOfYear.year = time.year;
	startOfYear.month = 1;
	startOfYear.day = 1;
	startOfYear.hours = 12;
	startOfYear.minutes = 0;
	startOfYear.seconds = 0;

	time.hours = 12;
	time.minutes = 0;
	time.seconds = 0;

	double present = JulianDays(time);
	double past = JulianDays(startOfYear);
	int days = present - past + 1;

	return days;
}

double fractionalYear(Time time) {
	double fraction;
	int dayYear = dayOfYear(time);
	fraction = 2 * pi / 365 * (dayYear - 1 + (time.hours - 12) / 24);

	return fraction;	// In radians
}

double eqTime(Time time) {
	double fr_year = fractionalYear(time);
	double eqtime;
	eqtime = 229.18*(0.000075 + 0.001868*cos(fr_year) - 0.032077*sin(fr_year) - 0.014615*cos(2 * fr_year) - 0.040849*sin(2 * fr_year));

	return eqtime;	//In radians
}

double declination(Time time) {
	double fr_year = fractionalYear(time);
	double decl;
	decl = 0.006918 - 0.399912*cos(fr_year) + 0.070257*sin(fr_year) - 0.006758*cos(2 * fr_year) + 0.000907*sin(2 * fr_year) - 0.002697*cos(3 * fr_year) + 0.00148*sin(3 * fr_year);

	return decl;	//In radians
}
