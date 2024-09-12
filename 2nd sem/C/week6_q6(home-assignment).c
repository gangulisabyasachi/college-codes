/*Write a recursive function to evaluate nCr*/
#include <stdio.h>

int fact(int n){
    if(n==1){
        return 1;
    }

    return n*fact(n-1);
}

int nCr(int n,int r){

    if(n<r){
        printf("Invalid input\n");
        return -1;
    }
    else{
        if(r==0 || r==n){
            return 1;
        }
        return fact(n)/(fact(n-r)*fact(r));
    }
}

int main() {
    int n,r;
    printf("Enter n and r: ");
    scanf("%d %d", &n,&r);
    printf("nCr is %d\n", nCr(n,r));
    return 0;
}

/*
Output
Enter n and r: 5 3
nCr is 10
Enter n and r: 6 2
nCr is 15
*/