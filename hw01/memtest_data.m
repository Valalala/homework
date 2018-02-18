load memdata
s=memdata(:,1);
start=memdata(:,4)+memdata(:,5)/1e9;
e=memdata(:,6)+memdata(:,7)/1e9;
dt=e-start;
rate=s./dt;
semilogx(s,rate/1024/1024)
title('RPi memory speed')
xlabel('data size, B')
ylabel('Rate, MB/s')
grid
pause()

