#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<cs50.h>
#include<ctype.h>
int main(int argc,string argv[]){
    if(argc!=2){
        printf("please provide proper arguments");
        return 1;
    }
    int len=strlen(argv[1]);
    int key[26];
    for(int m=0;m<len;m++){
        if(isalpha(argv[1][m])){
        if(isupper(argv[1][m])){
        key[m]=argv[1][m]-65;
        }
        else{
            key[m]=argv[1][m]-97;
        }
        }else{
             printf("please provide proper arguments");
            return 1;
        }
       //  printf("%d \n",key[m]);
    }
    char cipher_text[50];
    int i=0;
    int j=0;
    int k=0;
    int character;
   // int inc=atoi(argv[1]);
  printf("plaintext: ");
    string plain_text=get_string();
    if(plain_text!=NULL){
        while(plain_text[i]!='\0'){
            if(isalpha(plain_text[i])){
               
                if(isupper(plain_text[i])){
                  character=(plain_text[i]-65+key[k])%26+65; 
                  cipher_text[j]=character;
                //  printf(" pt %c ct %c key %d k %d\n",plain_text[i],cipher_text[j],key[k],k);
                  if(k<len-1){
                      k++;
                  }
                  else{
                      k=0;
                  }
                }
                else {
                    character=(plain_text[i]-97+key[k])%26+97; 
                  cipher_text[j]=character;
                     if(k<len-1){
                      k++;
                  }
                  else{
                      k=0;
                  }
                }
            }
            else{
                cipher_text[j]=plain_text[i];
            }
            i++;
            j++;
        }
    }
    cipher_text[j]='\0';
    printf("ciphertext: %s\n",cipher_text);
    return 0;
}