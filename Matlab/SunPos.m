clear %comment if needed

%date and time
Y = 2018
M = 2
D = 12
time = [Y M D 12 0 0];
day = 43;

%position
latitude = 40.4534;
longitude = -3.7269;
timezone = +1;
location = [latitude,longitude,timezone];

%{
decl = declination(day)
fractYear_rad = fractionalYear(time(4),day)
eqtime = eqTime(fractYear_rad)
tst = trueSolarTime(eqtime,longitude,timezone,time)
ha = hourAngle(tst)
[altitude,azimuth] = sunCoordinates(latitude,decl,ha)
%}

[altitude,azimuth] = sunPosition(time,location)