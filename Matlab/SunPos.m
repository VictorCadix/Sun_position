clear %comment if needed

Y = 2018
M = 2
D = 12

time = [Y M D 12 0 0]
day = 43;

decl = declination(day)
fractYear_rad = fractionalYear(time(4),day)
eqtime = eqTime(fractYear_rad)