function [ eqtime ] = eqTime( fract_year )
%time in minutes
%input in rad
eqtime = 229.18*(0.000075 + 0.001868*cos(fract_year) - 0.032077*sin(fract_year) - 0.014615*cos(2*fract_year)- 0.040849*sin(2*fract_year)); 

end

