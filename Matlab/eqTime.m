function [ eqtime ] = eqTime( fract_year,graph )
%time in minutes
%fractional year input (0-1)
%fractional year has to be in radians (0-6.28)
fr_year = fract_year*2*pi;
n = 0:(2*pi/365):(2*pi);
time = 229.18*(0.000075 + 0.001868*cos(n) - 0.032077*sin(n) - 0.014615*cos(2*n)- 0.040849*sin(2*n)); 
eqtime = 229.18*(0.000075 + 0.001868*cos(fr_year) - 0.032077*sin(fr_year) - 0.014615*cos(2*fr_year)- 0.040849*sin(2*fr_year)); 

if graph == 1
    figure('Name','eqTime','NumberTitle','off');
    n = n*(365/(2*pi));             %for X axis in days
    plot (n,time)
    hold on
    fr_year = fr_year*(365/(2*pi)); %for X axis in days
    plot(fr_year,eqtime,'*')
    hold off
end
end

