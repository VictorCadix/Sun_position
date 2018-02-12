function [ altitude,azimuth ] = sunPosition( time,location )

yearDay = 43;
latitude = location(1);
longitude = location(2);
timezone = location(3);

decl = declination(yearDay);
fractYear_rad = fractionalYear(time(4),yearDay)
eqtime = eqTime(fractYear_rad)
tst = trueSolarTime(eqtime,longitude,timezone,time)
ha = hourAngle(tst)
[altitude,azimuth] = sunCoordinates(latitude,decl,ha)

end

