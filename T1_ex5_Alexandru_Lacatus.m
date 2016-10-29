n=input('Introduceti rezolutia temporala = ')
t=0:n:3;
a=0.8
s=a*sin(2*pi*t);
subplot(211)
plot(s), grid

for t=1:length(t);
    if s(t)<=0
        s(t)=-s(t); %aceleasi explicatii ca la exercitiul anterior, doar ca
                    %"partea negativa" a semnalului nu devine 0, ci i se
                    %schimba semnul si este afisata deasupra abscisei
    else
        s(t)=s(t);
    end
end
subplot(212)
plot(s),grid,title('Sinusoidal DublaAlternanta'),xlabel('t'), ylabel('A');
