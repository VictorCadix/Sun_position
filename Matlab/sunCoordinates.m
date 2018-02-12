function [ altitude,azimuth ] = sunCoordinates( latitude,declination,hour_angle )

% altitude calculation
cos_zenith = sind(latitude)*sind(declination) + cosd(latitude)*cosd(declination)*cosd(hour_angle);
zenith = acosd(cos_zenith);
altitude = 90-zenith;

% azimuth calculation
aux = -((sind(latitude)*cosd(zenith)-sind(declination))/(cosd(latitude)*sind(zenith)));
aux = acosd(aux);
azimuth = 180-aux;

end

