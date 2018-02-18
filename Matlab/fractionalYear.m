function [ fract_year ] = fractionalYear( hour, yearDay )
% fract_year between 0 and 1
fract_year = 1 / 365 * (yearDay - 1 + (hour - 12) / 24);

end

