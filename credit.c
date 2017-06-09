#include<stdio.h>
#include<cs50.h>
int main(void){
    int length,d1,d2,sum1,sum2,sum3,digit,d;
    long long number,number1;
    printf("Number: ");
    number=get_long_long();
    number1=number;
    length=0;
    d1=0;
    sum1=0;sum2=0;
    while(number1!=0){
        d2=d1;
        d1=number1%10;
        number1=number1/10;
        length++;
        if(length%2==0){
            sum3=0;
            digit=2*d1;
            while(digit!=0){
             sum3=sum3+digit%10;
             digit=digit/10;
            }
            sum1=sum1+sum3;
        }
        else{
            sum2=sum2+d1;
        }
    }
    
    d=d1*10+d2;
    if((sum1+sum2)%10==0){
        switch(d){
            case 51:
            case 52:
            case 53:
            case 54: 
            case 55:
             if(length==16){
            printf("MASTERCARD\n");
            }
            else{
                  printf("INVALID\n");
            }
            
            break;
            case 40:
            case 41:
            case 42:
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
            case 48:
            case 49:
               if(length==16||length==13){
            printf("VISA\n");
            }
            else{
                  printf("INVALID\n");
            }
            
             break;
             case 34: 
            case 37:
            if(length==15){
            printf("AMEX\n");
            }
            else{
                  printf("INVALID\n");
            }
            break;
            default:
            printf("INVALID\n");
        }
    }
    else{
          printf("INVALID\n");
    }
    
    
}