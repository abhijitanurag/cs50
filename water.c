#include<cs50.h>
#include<stdio.h>
int main(void){
    printf("Minutes: ");
    int water=get_int();
    int bottle=192*water/16;
    printf("\nBottles: %d\n",bottle);
}