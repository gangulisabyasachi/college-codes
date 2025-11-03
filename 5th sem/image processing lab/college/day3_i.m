% Basic Image Processing with MATLAB Programming

% Clear the workspace and start new
close all
clearvars
clc

% Load an image
I = imread('peppers.png'); % Change the path for your own images.

% Display the image
imshow(I);
figure();

% Brightening/Darkening Images
I_bright = I * 1.25; % ~25% brighter
imshow(I_bright);
figure();


I_dark = I * 0.75; % ~25% darker
imshow(I_dark);
figure();


% Resizing Images
I_resized = imresize(I, [100 100]); % Resize to 100x100
imshow(I_resized);
figure();


% Selecting portions of an image (top-left quarter)
topQuarter = I(1:end/2, 1:end/2, :); 
imshow(topQuarter);
figure();


% Convert to Grayscale
Igray = rgb2gray(I);
imshow(Igray);
figure();

% Segmenting an image
Iseg = Igray; % Working with grayscale for segmentation
Iseg(Iseg >= 100) = 255; % Retain bright parts
Iseg(Iseg < 100) = 0; % Remove dark parts
imshow(Iseg);
figure();

% Segmenting a color image (strange results explanation)
Iseg_color = I; 
Iseg_color(Iseg_color >= 100) = 255; % Retain bright parts
Iseg_color(Iseg_color < 100) = 0; % Remove dark parts
imshow(Iseg_color);
