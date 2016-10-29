n=input('Introduceti rezolutia temporara[s] = ')
t=0:n:2;
s=square(2*pi*t, 25);
plot(t,s),title('DREPTUNGHIULAR'), xlabel('t'), ylabel('s'), grid
axis([0 2 0.5 -1])
