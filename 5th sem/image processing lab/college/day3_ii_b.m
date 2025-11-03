I = imread('peppers.png');
imshow(I);
figure();

I_red = I;
I_red(I_red(:,:,1)<128) = 0;
imshow(I_red)
figure();


I_red(:,:,2:3) = 0;
imshow(I_red)
figure();
