function [decl] = declination( dayOfYear )
n = 1:365;
declin = 23.45*sind((360/365)*(284+n));

decl = 23.45*sind((360/365)*(284+dayOfYear));
%if plot == 1
   figure('Name','Declination','NumberTitle','off');
   plot (n,declin)
   hold on
   plot(dayOfYear,decl,'*')
   hold off
%end

end

