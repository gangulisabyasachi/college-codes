close all
clearvars
clc

I = imread('lighthouse.png');
imshow(I)
figure();

I_red = detectColour(I,1); % 1 indicates channel 1.
imshow(I_red)
figure();

% Do the same in the green channel.
I_green = detectColour(I,2);
imshow(I_green)
figure();

%%If you were to do this in the blue channel, how would it be?
%I_blue = detectColour(I,2);
%imshow(I_blue)
%figure();

function I_detected = detectColour(im, channel)
% Set bright pixels(meaning component > 175) to 255
threshold = 175;
I_detected = im;
I_detected(:,:,:) = 0;
rows = size(I_detected,1);
columns = size(I_detected,2);
for i = 1:rows
 for j= 1:columns
 if( im(i,j,channel)> threshold)
 I_detected(i,j,channel)=255;
 else
 I_detected(i,j,channel)=0;
 end
 end
end
end







