function [ fract_year ] = fractionalYear( hour, yearDay )

fract_year = 2 * pi / 365 * (yearDay - 1 + (hour - 12) / 24);

end

