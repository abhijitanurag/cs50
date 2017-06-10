#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
int main(void){
    int i=0;
    int j;
string s=get_string();
if(s!=NULL){
  if(s[0]!=' '){
        printf("%c",toupper(s[i]));
    }
while(s[i]!='\0'){
  j=i;
    if(s[i]==' '){
        while(s[i]==' '){
        ++i;
        }
       if(s[i]!='\0')
    printf("%c",toupper(s[i]));
    }
    i++;
    
}
}
printf("\n");
}