function [ eqtime ] = eqTime( fract_year,graph )
%time in minutes
%input in rad
n = 0:(2*pi/365):(2*pi);
time = 229.18*(0.000075 + 0.001868*cos(n) - 0.032077*sin(n) - 0.014615*cos(2*n)- 0.040849*sin(2*n)); 
eqtime = 229.18*(0.000075 + 0.001868*cos(fract_year) - 0.032077*sin(fract_year) - 0.014615*cos(2*fract_year)- 0.040849*sin(2*fract_year)); 

if graph == 1
    figure('Name','eqTime','NumberTitle','off');
    plot (n,time)
    hold on
    plot(fract_year,eqtime,'*')
    hold off
end
end

