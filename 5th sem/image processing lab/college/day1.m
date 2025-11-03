i=imread('onion.png');
imshow(i);
figure();
imshow(i(:,:,1));
figure();
imshow(i(:,:,2));
figure();
imshow(i(:,:,3));

i1=imnoise(i,'salt & pepper', 0.1);
figure();
imshow(i1);

i2(:,:,1)=medfilt2(i1(:,:,1),[3 3]);
i2(:,:,2)=medfilt2(i1(:,:,2),[3 3]);
i2(:,:,3)=medfilt2(i1(:,:,3),[3 3]);
figure();
imshow(i2);

i3=rgb2gray(i);
figure()
imhist(i3);

Mean=mean2(i3);
SD=std2(i3);

i4=im2bw(i3);
figure();
imshow(i3);

i5=edge(i3,'sobel');
figure(); 
imshow(i5)