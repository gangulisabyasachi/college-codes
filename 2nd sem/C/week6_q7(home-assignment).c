#include <stdio.h>

int digitSum(int n){
    if(n==0){
        return 0;
    }
    return n%10 + digitSum(n/10);
}


int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Sum of digits is %d\n", digitSum(n));
    return 0;
}

/*
Enter a number: 12
Sum of digits is 3
architanant@Archits-MacBook-Air practice_c % ./home3.out
Enter a number: 1421
Sum of digits is 8
*/