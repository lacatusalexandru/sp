n=input('Introduceti rezolutia temporala in secunde = ');
t=0:n:5;
s=sawtooth(2*pi*t,0.5)
plot(t,s), xlabel('t'), ylabel('A'), title('TRIUNGHIULAR'), grid on,axis([0 5 1 -2])