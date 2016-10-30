n=-15:1:25
x1=sin( (pi*n)/17 )

m=0:1:50
x2=cos( (pi*m)/sqrt(23) )
a=input('Alege 1 -> Fig1 si 2 -> Fig2 =')
switch a
    case 1
        plot(n,x1),grid, hold on
        plot(m,x2),grid
    case 2
        subplot(2,2,1)
        plot(n,x1),grid
        
        subplot(2,2,2)
        stem(n,x1),grid
        
        subplot(2,2,3)
        plot(m,x2),grid
        
        subplot(2,2,4)
        stem(m,x2),grid
    otherwise
        disp('Alege 1 pentru figura 1 si 2 pentru figura 2!')
end
