function [ tst ] = trueSolarTime( eqtime, longitude, timezone , time)

time_offset = eqtime + 4*longitude - 60*timezone;

hour = time(4);
minutes = time(5);
seconds = time(6);
tst = hour*60 + minutes + seconds/60 + time_offset;
end