n=input('Valoarea rezolutiei temporale (0.01 sau 0.0002) = ')
F=50
f=20
t=0:n:0.2
s=2*sin(2*pi*F*t);
c=2*cos(2*pi*f*t);
plot(t,s), grid, hold on
plot(t, c), grid