function [ altitude,azimuth ] = sunCoordinates( latitude,declination,hour_angle )

% altitude calculation NOAA
cos_zenith = sind(latitude)*sind(declination) + cosd(latitude)*cosd(declination)*cosd(hour_angle);
zenith = acosd(cos_zenith);
altitude = 90-zenith;

% azimuth calculation
aux = asind((-sind(hour_angle)*cosd(declination))/(sind(zenith)));
azimuth = 180-aux;

%{
% By the NOAA Global Monitoring Division 
aux = -(sind(latitude)*cosd(zenith)-sind(declination))/(cosd(latitude)*sind(zenith));
aux = acosd(aux);
azimuth = 180-aux;
%}

%aux = acosd((sind(declination)- cosd(zenith)*cosd(latitude))/(sind(zenith)*cosd(latitude)));

%azimuth = sind(hour_angle)*abs(aux);


end

