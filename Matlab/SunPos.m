clear %comment if needed

%date and time
Y = 2018
M = 6
D = 19
time = [Y M D 17 30 0];
yearDay = dayOfYear(time)

%position
latitude = 40.4534;
longitude = -3.7269;
timezone = +1;
location = [latitude,longitude,timezone];

%{
decl = declination(day,1)
fractYear_rad = fractionalYear(time(4),day)
eqtime = eqTime(fractYear_rad,1)
tst = trueSolarTime(eqtime,longitude,timezone,time)
ha = hourAngle(tst)
[altitude,azimuth] = sunCoordinates(latitude,decl,ha)
%}

[altitude,azimuth,data] = sunPosition(time,location,1);
altitude
azimuth