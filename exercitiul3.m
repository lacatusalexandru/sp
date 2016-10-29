n=input('Introduceti rezolutia temporala = ')
t=0:n:3;          %vectorul rezolutiei temporale
a=0.8             %amplitudinea
s=a*sin(2*pi*t);  %formula semnalului
subplot(211)      %impartirea fereastrei graficc
plot(s), grid     %si afisarea semnalului original in prima minifereastra

for t=1:length(t) %indexul forului trebuie sa parcurga tot intervalul de rezolutie temporala
                  %de aceea, t-ul se ia de la 1 la length(t) -  lungimea
                  %intervalului
    if s(t)<=0    %daca semnalul este negativ
        s(t)=0;   %nu se afiseaza, se egaleaza cu 0
    else          %iar daca nu e pozitiv, se afiseaza
        s(t) = s(t);
    end
end
subplot(212)      %afisarea celui de-al doilea semnal in a doua minifereastra
plot(s),grid,title('Sinusoidal MonoAlternanta'),xlabel('t'), ylabel('A');
