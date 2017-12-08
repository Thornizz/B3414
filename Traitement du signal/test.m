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
%     title('S = f(t)');
    
    % SPECTRE EN FREQUENCE
%     echantillonSpectre=echantillonage(x6,A,B,N);
%     subplot(2,1,1);
%     plot(temps,echantillonSpectre);
%     title('S = f(t)');
%     
%     spectre = spectreEnFrequence(x6,A,B,N);
%     subplot(2,1,2);
%     plot(frequence,spectre);
%     title('spectre S en frequence');
    
    %INVERSE DE FOURIER
%     echantillonFourrier=echantillonage(x6,A,B,N);
%     subplot(3,1,1)
%     plot(temps,echantillonFourrier);
%     title('S = f(t)');
%     
%     spectreFourier = spectreEnFrequence(x6,A,B,N);
%     subplot(3,1,2)
%     plot(frequence,spectreFourier);
%     title('spectre S en frequence');
%     
%     resultatInvFourier = real(tfourinv(spectreFourier'));
%     subplot(3,1,3)
%     plot(temps,resultatInvFourier)
%     title('S = invFourier(spectre S en frequence)');
     
    % MODULATION
%       S1 = real(s1);
%       S2 = real(s2);
%     
%       subplot(3,2,1);
%       plot(temps,S1);
%       title('S1 = f(t)');
%       spectreS1=spectreEnFrequenceDejaEchantillone(S1);
%       subplot(3,2,2);
%       plot(frequence,spectreS1);
%       title('spectre S1 en frequence');
%      
%       subplot(3,2,3);
%       plot(temps,S2);
%       title('S2 = f(t)');
%       spectreS2=spectreEnFrequenceDejaEchantillone(S2);
%       subplot(3,2,4);
%       plot(frequence,spectreS2);
%       title('spectre S2 en frequence');
%       
%       f1 = 1000;
%       f2 = 300;
%       c = modulation(N,temps,S1,f1,S2,f2);
%      
%       subplot(3,2,5);
%       plot(temps,c);
%       title('SModule = f(t)');
%       spectreC=spectreEnFrequenceDejaEchantillone(c);
%       subplot(3,2,6);
%       plot(frequence,spectreC);
%       title('spectre SModule en frequence');
     
    % DEMODULATION
      S1 = real(s1);
      S2 = real(s2);
    
      subplot(5,2,1);
      plot(temps,S1);
      title('S1 = f(t)');
      spectreS1=spectreEnFrequenceDejaEchantillone(S1);
      subplot(5,2,2);
      plot(frequence,spectreS1);
      title('spectre S1 en frequence');
     
      subplot(5,2,3);
      plot(temps,S2);
      title('S2 = f(t)');
      spectreS2=spectreEnFrequenceDejaEchantillone(S2);
      subplot(5,2,4);
      plot(frequence,spectreS2);
      title('spectre S2 en frequence');
      
      f1 = 1000;
      f2 = 200;
      c = modulation(N,temps,S1,f1,S2,f2);
     
      subplot(5,2,5);
      plot(temps,c);
      title('SModule = f(t)');
      spectreC=spectreEnFrequenceDejaEchantillone(c);
      subplot(5,2,6);
      plot(frequence,spectreC);
      title('spectre SModule en frequence');
    
      c = modulation(N,temps,S1,f1,S2,f2);
      f=f2;
    
      d = deModulation(N,temps,c,f);
      
      subplot(5,2,7);
      plot(temps,d);
      title('SDemodule = f(t)');
      spectreD=spectreEnFrequenceDejaEchantillone(d);
      subplot(5,2,8);
      plot(frequence,spectreD);
      title('spectre SDemodule en frequence');
      
      spectreF = filtre(N,frequence,spectreD);
      subplot(5,2,10);
      plot(frequence,spectreF);
      title('spectre SDemoduleFiltre en frequence');
      
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
    four = real(tfour(ech'));
    spectre = four';
end

function [c] = modulation (N,temps,s1,f1,s2,f2)
     c = zeros(1,N);
     for i=1:N
         c(i) = s1(i)*cos(2*pi*f1*temps(i)) + s2(i)*cos(2*pi*f2*temps(i));
     end
end

function [d] = deModulation (N,temps,c,f)
     d = zeros(1,N);
     for i=1:N
         d(i) = c(i)*cos(2*pi*f*temps(i));
     end
end


function [f] = filtre(N,frequence,d)
     LIMITE = 500;
     f = zeros(1,N);
     for i=1:N
         if(abs(frequence(i))<LIMITE)
             f(i) = d(i);
         end
     end
end

function [spectre] = spectreEnFrequenceDejaEchantillone (x)
    four = real(tfour(x));
    spectre = four';
end