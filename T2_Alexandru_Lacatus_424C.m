t = linspace(-25,25,100);
f = 0;
P = 40;
N=50;
omega = (2*pi)/P; 

for i=-N:1:N
    
    if (i==0)
        continue
    else  
    %C=((exp((-1)*1i*k*omega*P)-1)/(1i*k*omega*P));
    %syms t1;
    %C=int( exp((-1)*1i*k*omega*t1), t1, 0, P);
    %fk = C*exp(omega*k*1i*t1);
    %f = f + fk;
    
    C = ((1)/(pi*1i*i))*(1-exp(-pi*1i*i));    
    fk = C*exp(omega*1i*i*t);                
    f = f + fk;
    
    end
end
f=(1/P)*f;
%drept = square(t1,50)
s = sinc(pi*t);

subplot(2,1,1);
plot(t, f, '-');
%plot(drept, t1);
grid on, xlabel('t'), ylabel('f(t)'), title('Reconstructia folosind coeficienti');

subplot(2,1,2);
stem(t,abs(s));
grid on, xlabel('t'), ylabel('f(t)'), title('Spectrul lui x(t)');
