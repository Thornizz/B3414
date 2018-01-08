function [] = partie2()
    
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [] = G(N,f,S,temps,frequence,position)
      G = zeros(1,N);
      for i=1:N
          G(i) = S(i)*cos(2*pi*f*temps(i));
      end
      subplot(5,2,2*position+1);
      plot(temps,G);
      title(strcat('G(',int2str(f),') = f(t)'));
      spectreG=spectreEnFrequenceDejaEchantillone(G);
      subplot(5,2,2*position+2);
      plot(frequence,spectreG);
      title(strcat('spectre G(',int2str(f),') en frequence'));
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
             f(i) = 2*d(i);
         end
     end
end

function [spectre] = spectreEnFrequenceDejaEchantillone (x)
    four = real(tfour(x));
    spectre = four';
end