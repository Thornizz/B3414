function [Xechantillone]=echantillonage(x,a,b,N)
    Xechantillone=zeros(N,1);
    T=(b-a)/N;
for n=1:N
    Xechantillone(n)=x((n-1)*T+a);
end   
end