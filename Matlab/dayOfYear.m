function [ doy ] = dayOfYear( time )
%DAYOFYEAR Returns the day of the year
%   Detailed explanation goes here
y = time(1);
m = time(2);
d = time(3);

% the year will be used to know whether it's a leap year or not

doy = 0;
i = 1;
while i < m
    if i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12
        doy = doy + 31;
    elseif i == 2
        doy = doy + 28;
    else
        doy = doy + 30;
    end
end

doy = doy + d;

end

