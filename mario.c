#include<stdio.h>
#include<cs50.h>
int main(void){
    int height,i,j;
    
    do{
        printf("\nHeight: ");
        height=get_int();
    }while(!(height>=0&&height<=23));
    for(i=0;i<height;i++){
       
        for(j=height-1;j>i;j--){
        printf(" ");    
            
            
    }
    for(j=0;j<=i;j++){
        printf("#");
    }
    printf("  ");
     for(j=0;j<=i;j++){
        printf("#");
    }
    printf("\n");
    }
}