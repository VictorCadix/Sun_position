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

typedef struct Position {
	double latitude;
	double longitude;
	int timezone;
};

typedef struct SunCoordinates {
	double azimuth;
	double altitude;
};

typedef struct Sunrise_sunet {
	Time sunrise;
	Time sunset;
	Time noon;
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

	return eqtime;	//In minutes
}

double declination(Time time) {
	double fr_year = fractionalYear(time);
	double decl;
	decl = 0.006918 - 0.399912*cos(fr_year) + 0.070257*sin(fr_year) - 0.006758*cos(2 * fr_year) + 0.000907*sin(2 * fr_year) - 0.002697*cos(3 * fr_year) + 0.00148*sin(3 * fr_year);

	return decl;	//In radians
}

double trueSolarTime(Time time, Position pos) {
	double time_offset;
	double eqtime;
	eqtime = eqTime(time);
	time_offset = eqtime + 4 * pos.longitude - 60 * pos.timezone;

	double tst;	//true solar time
	tst = time.hours * 60 + time.minutes + time.seconds / 60 + time_offset;

	return tst;
}

double hourAngle(double true_solar_time) {
	double ha = (true_solar_time / 4) - 180;
	return ha;
}

void sunCoordinates(Time time, Position pos, SunCoordinates* sun) {
	double lat = pos.latitude * pi / 180;
	double decl = declination(time);
	double tst = trueSolarTime(time, pos);
	double ha = hourAngle(tst) * pi / 180;
	
	double cos_zenithAngle;
	double zenithAngle;
	cos_zenithAngle = sin(lat)*sin(decl) + cos(lat)*cos(decl)*cos(ha);
	zenithAngle = acos(cos_zenithAngle);

	sun->altitude = 90 - zenithAngle * 180 / pi;
	
	double cos_aux;
	cos_aux = -(sin(lat)*cos(zenithAngle)-sin(decl))/(cos(lat)*sin(zenithAngle));
	double aux = acos(cos_aux);
	sun->azimuth = 180 - aux * 180 / pi;
}

void UTCtimeOf_sunrise_sunset(Time time, Position pos, Sunrise_sunet *sun) {
	double ha;	//hour angle
	double lat = pos.latitude*pi / 180;
	double decl = declination(time);
	
	//ha in rad
	ha = acos((cos(90.833*pi/180)) / (cos(lat)*cos(decl)) - tan(lat)*tan(decl));

	double eqtime = eqTime(time);
	//in minutes
	double sunrise = 720 - 4 * (pos.longitude + ha * 180 / pi) - eqtime;
	sun->sunrise.hours = sunrise / 60;
	sun->sunrise.minutes = sunrise - sun->sunrise.hours * 60;
	sun->sunrise.seconds = (sunrise - sun->sunrise.hours * 60 - sun->sunrise.minutes)*60;
	
	double sunset = 720 - 4 * (pos.longitude - ha * 180 / pi) - eqtime;
	sun->sunset.hours = sunset / 60;
	sun->sunset.minutes = sunset - sun->sunset.hours * 60;
	sun->sunset.seconds = (sunset - sun->sunset.hours * 60 - sun->sunset.minutes) * 60;

	double noon = 720 - 4 * pos.longitude - eqtime;
	sun->noon.hours = noon / 60;
	sun->noon.minutes = noon - sun->noon.hours * 60;
	sun->noon.seconds = (noon - sun->noon.hours * 60 - sun->noon.minutes) * 60;
}