function [] = test()
    load('fonction5.mat');
    load('signal1.mat');
    load('signal2.mat');
    
    f = 4;
    x0 = @(x) f;
    x1 = @(x) cos(2*pi*f*x);
    x2 = @(x) sin(2*pi*f*x);
    x3 = @(x) exp(1i*2*pi*f*x);
    x4 = @(x) rect(x);
    T0 = 0.1;
    x6 = @(x) x4(mod(x+T0/2,T0)-T0/2);
    
    A=-2;
    B=2;
    N=16384;
    
    temps = zeros(N,1);
    frequence = zeros(N,1);
    
    for n=1:N
        temps(n) = (n-1)*(B-A)/N + A;
        frequence(n) = -2*N/(B-A) + n;
    end   
    
    
    % AFFICHAGE
%     echantillon=echantillonage(x6,A,B,N);
%     plot(temps,echantillon);
    
    % SPECTRE EN FREQUENCE
%     echantillonSpectre=echantillonage(x6,A,B,N);
%     subplot(2,1,1);
%     plot(temps,echantillonSpectre);
%     
%     spectre = spectreEnFrequence(x6,A,B,N);
%     subplot(2,1,2);
%     plot(frequence,spectre);
    
    %INVERSE DE FOURIER
%     echantillonFourrier=echantillonage(x6,A,B,N);
%     subplot(3,1,1)
%     plot(temps,echantillonFourrier);
%     
%     
%     spectreFourier = spectreEnFrequence(x6,A,B,N);
%     subplot(3,1,2)
%     plot(frequence,spectreFourier)
%     
%     resultatInvFourier = tfourinv(spectreFourier');
%     subplot(3,1,3)
%     plot(temps,resultatInvFourier)
     
    % MODULATION
      subplot(4,2,1);
      plot(temps,s1);
      spectreS1=spectreEnFrequenceDejaEchantillone(s1);
      subplot(4,2,2);
      plot(frequence,spectreS1);
     
      subplot(4,2,3);
      plot(temps,s2);
      spectreS2=spectreEnFrequenceDejaEchantillone(s2);
      subplot(4,2,4);
      plot(frequence,spectreS2);
      
      f1 = 600;
      f2 = 300;
      c = modulation(N,s1,f1,s2,f2);
     
      subplot(4,2,5);
      plot(temps,c);
      spectreC=spectreEnFrequenceDejaEchantillone(c);
      subplot(4,2,6);
      plot(frequence,spectreC);
     
    % DEMODULATION
      
%       f1 = 600;
%       f2 = 300;
%       c = modulation(N,s1,f1,s2,f2);
%       f=f2;
%     
%       d = deModulation(N,c,f);
end

function [y] = rect(x)
    if(abs(x)<=0.02)
        y = 1;
    else
        y = 0;
    end
end


function [e] = echantillon (x,A,B,N)
    T=(B-A)/N;
    
    e = zeros(N,1);
    temps = zeros(N,1);
    frequence = zeros(N,1);
    
    for n=1:N
        temps(n) = (n-1)*T + A;
        frequence(n) = 1/temps(n);
        e(n) = x((n-1)*T+A);
    end
end

function [spectre] = spectreEnFrequence (x,A,B,N)
    ech = echantillon (x,A,B,N);
    four = tfour(ech');
    spectre = four';
end

function [c] = modulation (N,s1,f1,s2,f2)
     c = zeros(1,N);
     for i=1:N
         c(i) = s1(i) * cos(2*pi*f1*i) + s2(i) * cos(2*pi*f2*i);
     end
end

function [d] = deModulation (N,c,f)
     d = zeros(1,N);
     for i=1:N
         d(i) = c(i)*cos(2*pi*f*i);
     end
end

function [spectre] = spectreEnFrequenceDejaEchantillone (x)
    four = tfour(x);
    spectre = four';
end