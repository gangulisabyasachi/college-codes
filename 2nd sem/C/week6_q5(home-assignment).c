#include <stdio.h>
#include <math.h>

int decimalToBinary(int);
int decimalToOctal(int);
int binaryToDecimal(int);
int binaryToOctal(int);
int octalToDecimal(int);
int octalToBinary(int);

int main(){
    int num,base,choice,toContinue =1;

    while(toContinue==1){
        printf("Enter the number to convert: ");
        scanf("%d",&num);
        printf("Enter base of the number: ");
        scanf("%d",&base);
        printf("Supported Conversions\n10 - Decimal\n2 - Binary\n8 - Octal\nEnter your choice: ");
        scanf("%d",&choice);

        if(choice==base){
            printf("WARNING: Conversion into the same base\n");
            printf("The value is %d\n",num);
        
        }
        else{
            switch(choice){
                case 10:
                    if(base == 2){
                        binaryToDecimal(num);
                        break;
                    }
                    else if(base == 8){
                        octalToDecimal(num);
                        break;
                    }
                
                case 2:
                    if(base == 10){
                        decimalToBinary(num);
                        break;
                    }
                    else if(base == 8){
                        octalToBinary(num);
                        break;
                    }

                case 8:
                    if(base == 2){
                        binaryToOctal(num);
                        break;
                    }
                    else if(base == 10){
                        decimalToOctal(num);
                        break;
                    }

                default : 
                    printf("Enter a valid base!");
            }
        }
        printf("More to convert? (1/0): ");
        scanf("%d",&toContinue);
    }
}

int decimalToBinary(int num){
    int binary[100],i=0;
    while(num>0){
        binary[i] = num%2;
        num = num/2;
        i++;
    }
    printf("The binary value is: ");
    for(int j=i-1;j>=0;j--){
        printf("%d",binary[j]);
    }
    printf("\n");

    return 0;
}

int decimalToOctal(int num){
    int octal[100],i=0;
    while(num>0){
        octal[i] = num%8;
        num = num/8;
        i++;
    }
    printf("The octal value is: ");
    for(int j=i-1;j>=0;j--){
        printf("%d",octal[j]);
    }
    printf("\n");
    return 0;
}

int binaryToDecimal(int num){
    int decimal=0,i=0,rem;
    while(num>0){
        rem = num%10;
        decimal = decimal + rem*pow(2,i);
        num = num/10;
        i++;
    }
    printf("The decimal value is: %d\n",decimal);
    return decimal;
}

int binaryToOctal(int num){
    int decimal = binaryToDecimal(num);
    decimalToOctal(decimal);
    return 0;
}

int octalToDecimal(int num){
    int decimal=0,i=0,rem;
    while(num>0){
        rem = num%10;
        decimal = decimal + rem*pow(8,i);
        num = num/10;
        i++;
    }
    printf("The decimal value is: %d\n",decimal);
    return decimal;
}

int octalToBinary(int num){
    int decimal = octalToDecimal(num);
    decimalToBinary(decimal);
    return 0;
}

/*
Enter the number to convert: 101
Enter base of the number: 2
Supported Conversions
10 - Decimal
2 - Binary
8 - Octal
Enter your choice: 8
The decimal value is: 5
The octal value is: 5
More to convert? (1/0): 1   
Enter the number to convert: 1001
Enter base of the number: 2
Supported Conversions
10 - Decimal
2 - Binary
8 - Octal
Enter your choice: 8
The decimal value is: 9
The octal value is: 11
More to convert? (1/0): 1   
Enter the number to convert: 1001
Enter base of the number: 2
Supported Conversions
10 - Decimal
2 - Binary
8 - Octal
Enter your choice: 10
The decimal value is: 9
More to convert? (1/0): 1
Enter the number to convert: 1001
Enter base of the number: 2
Supported Conversions
10 - Decimal
2 - Binary
8 - Octal
Enter your choice: 2
WARNING: Conversion into the same base
The value is 1001
More to convert? (1/0): 1
Enter the number to convert: 11
Enter base of the number: 8
Supported Conversions
10 - Decimal
2 - Binary
8 - Octal
Enter your choice: 10
The decimal value is: 9
More to convert? (1/0): 1   
Enter the number to convert: 11
Enter base of the number: 8
Supported Conversions
10 - Decimal
2 - Binary
8 - Octal
Enter your choice: 2
The decimal value is: 9
The binary value is: 1001
More to convert? (1/0): 1
Enter the number to convert: 10
Enter base of the number: 10
Supported Conversions
10 - Decimal
2 - Binary
8 - Octal
Enter your choice: 2
The binary value is: 1010
More to convert? (1/0): 1
Enter the number to convert: 18
Enter base of the number: 10
Supported Conversions
10 - Decimal
2 - Binary
8 - Octal
Enter your choice: 8
The octal value is: 22
More to convert? (1/0): 0
*/