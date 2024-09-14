/*
Write a recursive function to print the first n Fibonacci numbers.
*/


#include <stdio.h>

void fib(int a,int b,int n,int count) {
    int ans ;

    if(count == n-2){
        return;
    }

    ans = a+b;

    printf("%d ",ans);

    fib(b,ans,n,count+1);
    
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("First %d Fibonacci numbers: ", n);
    printf("0 1 ");
    fib(0,1,n,0);
    printf("\n");
    return 0;
}

/*

Enter a number: 7
First 7 Fibonacci numbers: 0 1 1 2 3 5 8 
architanant@Archits-MacBook-Air practice_c % ./p4.out
Enter a number: 3
First 3 Fibonacci numbers: 0 1 1 
architanant@Archits-MacBook-Air practice_c % ./p4.out
Enter a number: 5
First 5 Fibonacci numbers: 0 1 1 2 3 

*/