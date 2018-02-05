function test
 [im, map]= imread('photo.jpg');
 size(im);
 size(map);
 
%  im(100:180,100:200,2)=0;
%  figure(1)
%  image(im)
%  
ndg=0.3*im(:,:,1)+0.59*im(:,:,2)+0.11*im(:,:,3);

 size(ndg);
 figure(2)
 image(ndg)

% image en niveau de gris
  mapndg=([0:255]/255)'*[1 1 1];
 colormap(mapndg)
 
%  histogramme
histo = zeros(1,256);
[R,C]=size(ndg);
for r=1:R
    for c=1:C
        histo(ndg(r,c)+1)=histo(ndg(r,c)+1)+1;
    end
end
figure(3)
plot(histo)

% histo cumulé
hcum=zeros(1,256);
hcum(1)=histo(1);
for n=2:256
    hcum(n)=hcum(n-1)+histo(n);
end
figure(4)
plot(hcum)

% seuillage
imseuil=zeros(1,256);
seuil=100;
for r=1:R
    for c=1:C
       if ndg(r,c)+1>seuil
           imseuil(r,c)=255;
       end
    end
end
figure(5)
image(imseuil)
colormap(mapndg)

% recadrage
ndg=double(ndg);
mini=min(min(ndg));
maxi=max(max(ndg));
recadr=255*(ndg-mini)/(maxi-mini);
figure(6)
image(recadr)
colormap(mapndg)

% egalisation
imegal=zeros(size(ndg));
hcum=hcum/(R*C)*255;
for r=1:R
    for c=1:C
        imegal(r,c)=hcum(ndg(r,c)+1);
    end
end
figure(7)
image(imegal)
colormap(mapndg)

% new histo
% histo = zeros(1,256);
% [R,C]=size(ndg);
% for r=1:R
%     for c=1:C
%         histo(imegal(r,c)+1)=histo(imegal(r,c)+1)+1;
%     end
% end
% figure(8)
% plot(histo)

% convolution

%sur contour masque=[-1 -2 -1; -2 12 -2;-1 -2 -1];avec passe haut 
%normal masque=[1 1 1;1 1 1;1 1 1] avec passe bas
%rehausser masque=[-1 -2 -1; -2 13 -2;-1 -2 -1] avce passe bas et offset 0
% sobel contours masque=[-1 -2 -1; 0 0 0 ; 1 2 3]; W=0.5 offset 128 
% contours horizontaux ou verticaux avec masque'
% laplacien masque=[0 1 0;1 -4 1;0 1 0]; W=0.5 offset = 128
masque=[0 1 0;1 -4 1;0 1 0];
imconvol=zeros(size(ndg));
W=0.5;
offset=128;
%plus W est élevé plus l'image est floue 
%16 passe bas/ 1 passe haut/ 9 neutre
for r=2:R-1
    for c=2:C-1
       imconvol(r,c)=offset+(sum(sum(ndg(r-1:r+1,c-1:c+1).*masque)))/W;
       if imconvol(r,c)<0
           imconvol(r,c)=0;
       end
       if imconvol(r,c)>255
           imconvol(r,c)=255;
       end
    end
end
figure(9)
image(imconvol)
colormap(mapndg)

% erosion (inclusion)
imeros=zeros(size(ndg));
for r=2:R-1
    for c=2:C-1
       imeros(r,c)=min(min(ndg(r-1:r+1,c-1:c+1)));
    end
end
figure(10)
image(imeros)
colormap(mapndg)

% dilatation (intersaction)
imdilat=zeros(size(ndg));
for r=2:R-1
    for c=2:C-1
       imdilat(r,c)=max(max(ndg(r-1:r+1,c-1:c+1)));
    end
end
figure(11)
image(imdilat)
colormap(mapndg)

 
end