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
    char cipher_text[50];
    int i=0;
    int j=0;
    int character;
    int inc=atoi(argv[1]);
  printf("plaintext: ");
    string plain_text=get_string();
    if(plain_text!=NULL){
        while(plain_text[i]!='\0'){
            if(isalpha(plain_text[i])){
               
                if(isupper(plain_text[i])){
                  character=(plain_text[i]-65+inc)%26+65; 
                  cipher_text[j]=character;
                }
                else {
                    character=(plain_text[i]-97+inc)%26+97; 
                  cipher_text[j]=character;
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