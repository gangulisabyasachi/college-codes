i = imread('onion.png');

figure();
imshow(i);
title('Original Image');

imwrite(i, "onion_copy.png");  % better not to overwrite original

% Crop the image
im = imcrop(i, [60 40 100 90]);

figure();
imshow(im);
title('Cropped Image');

% Rotate the cropped image
img_rot = imrotate(im, 35, "bilinear");

figure();
imshow(img_rot);
title('Rotated Image');

% Image info
info = imfinfo('onion.png');
disp(info);

% Pixel value
pixel_val = impixel(i, 200, 200);
disp('Pixel value at (200,200):');
disp(pixel_val);

% Arithmetic Operations
x = i + i;
figure();
imshow(x);
title('i + i');

y = i - i;
figure();
imshow(y);
title('i - i');

% Element-wise multiplication
z = immultiply(i, i);  % safer than i*i
figure();
imshow(z);
title('i .* i');

% Division
div = imdivide(i, 0.5);  % divide by scalar
figure();
imshow(div);
title('i / 0.5');

