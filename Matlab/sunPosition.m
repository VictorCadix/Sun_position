function [ altitude,azimuth,data ] = sunPosition( time,location )

yearDay = 43;
latitude = location(1);
longitude = location(2);
timezone = location(3);

decl = declination(yearDay);
fractYear_rad = fractionalYear(time(4),yearDay)
eqtime = eqTime(fractYear_rad)

%plot today trajectory
%%{
data = zeros(24,3);
hour_backup = time(4);
for hour = 0:0.25:24
    if hour==0
        cont=1;
    end
    time(4) = hour;
    tst = trueSolarTime(eqtime,longitude,timezone,time);
    ha = hourAngle(tst);
    [altitude,azimuth] = sunCoordinates(latitude,decl,ha);
    if altitude > -10
        data(cont,1)=time(4);
        data(cont,2)=altitude;
        data(cont,3)=azimuth;
        cont = cont+1;
    end
end
figure('Name','Sun Position','NumberTitle','off');
plot(data(:,3),data(:,2));
hold on
%}
time(4) = hour_backup;
tst = trueSolarTime(eqtime,longitude,timezone,time);
ha = hourAngle(tst);
[altitude,azimuth] = sunCoordinates(latitude,decl,ha);

plot(azimuth,altitude,'*')
hold off

end

