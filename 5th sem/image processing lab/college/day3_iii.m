I = imread('coins.png');
imshow(I)

BW1 = edge(I,'sobel');
BW2 = edge(I,'canny');
figure;
imshowpair(BW1,BW2,'montage')
title('Sobel Filter Canny Filter');

I = imread('peppers.png');
I(1:15, 1:15, 1)

imshow(I);
figure();


Igray = rgb2gray(I);
imshow(diff(Igray))

Iedge = diff(Igray);

threshold_value = 7

Iedge(Iedge>=threshold_value) = 255;
Iedge(Iedge<threshold_value) = 0;
imshow(Iedge)
figure();


BW1 = edge(Igray,'sobel');
BW2 = edge(Igray,'canny');
figure;
imshowpair(BW1,BW2,'montage')
title('Sobel Filter Canny Filter')