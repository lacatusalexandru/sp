t=0:0:21
for n=0:20
    t(n+1)=abs(10-n)
end
m=0:20
stem(m,t)