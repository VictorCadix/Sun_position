function [decl] = declination( dayOfYear,graph )
n = 1:365;
declin = 23.45*sind((360/365)*(284+n));

decl = 23.45*sind((360/365)*(284+dayOfYear));
if graph == 1
   figure('Name','Declination','NumberTitle','off');
   plot (n,declin)
   hold on
   plot(dayOfYear,decl,'*')
   hold off
end

end

