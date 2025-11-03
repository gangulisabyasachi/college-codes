x=imread('onion.png');
figure('Name','Original Image','Numbertitle','off');
imshow(x);
x=imread('onion.png');

y=rgb2gray(x);
figure('Name','Gray Scale Image','Numbertitle','off');
imshow(y);

w=edge(y,'canny');
figure('Name','Edge Detection','Numbertitle','off');
imshow(w);

I(:,:,1)=imrotate(x(:,:,1),45);
I(:,:,2)=imrotate(x(:,:,2),45);
I(:,:,3)=imrotate(x(:,:,3),45);
figure('Name','Rotation of Image','Numbertitle','off');
imshow(I);

I1=imtranslate(x,[2.5 5.5]);
figure('Name','Translate Image','Numbertitle','off');
imshow(I1);
figure('Name','Histogram Image','Numbertitle','off');
imhist(y);


