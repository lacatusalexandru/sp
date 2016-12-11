t = linspace(-25,25,100);
f = 0;
P = 40;
N=50;
omega = (2*pi)/P; 

for i=-N:1:N
    
    %if isempty(i)
    if (i==0)
        continue
    else  
    %C=((exp((-1)*1i*k*omega*P)-1)/(1i*k*omega*P));
    %syms t1;
    %C=int( exp((-1)*1i*k*omega*t1), t1, 0, P);
    %fk = C*exp(omega*k*1i*t1);
    %f = f + fk;
    
    C = ((1)/(pi*1i*i))*(1-exp(-pi*1i*i)); %calculul coeficientului folosind integrala   
    fk = C*exp(omega*1i*i*t);%coeficientul de ordinul i si suma lor
    f = f + fk;
    
    end
end
f=(1/P)*f;
%drept = square(t1,50);
s = sinc(pi*t);

subplot(2,1,1);
plot(t, f, '-');
%plot(drept, t1); // daca se incearca reprezentarea semnalului pe acelasi grafic apar erori
grid on, xlabel('t'), ylabel('f(t)'), title('Reconstructia folosind coeficienti');

subplot(2,1,2);
stem(t,abs(s));
grid on, xlabel('t'), ylabel('f(t)'), title('Spectrul lui x(t)');
%in reprezentarea grafica se pot observa componenta continua, componenta fundamentala (i=1), celelalte componente fiind cele de ordinul i
