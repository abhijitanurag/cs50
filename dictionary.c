/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"
#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
typedef struct node{
    bool is_word;
    struct node *children[27];
}node;
node *root,*temp,*temp1;
int word=0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    char cr;
    int num=0;
    temp=root;
    temp1=root;
    for(int j=0;j<strlen(word);j++){
        if(isalpha(word[j])){
        cr=tolower(word[j]);
        num=cr-97;
        if(temp->children[num]!= NULL)
        temp=temp->children[num];
        else
        return false;
        
        }  
         if (word[j] == '\'')
        {
            if (temp -> children[26] != NULL)
                temp = temp -> children[26];
            else
                return false;
        }
         if (j == strlen(word) - 1)
        {
            if (temp -> is_word == true)
                return true;
            else
                return false;
        }
        
    }
    // TODO
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    int n=0;
   int i=0; 
root=NULL;
    FILE* file=fopen(dictionary,"r");
    if(file==NULL){
      
        return false;
    }
    root=malloc(sizeof(node));
            for(i=0;i<27;i++){
                root->children[i]=NULL;
            }
            temp=root;
   int  b=fgetc(file);
   
   //int n=0;
    while(b!=EOF){
 if(b>=97&&b<=122){
     
     
     n=b-97;
     if(temp->children[n]==NULL){
         temp->children[n]=malloc(sizeof(node));
         temp=temp->children[n];
         for(i=0;i<27;i++){
                temp->children[i]=NULL;
            }
         
     }
     else{
         temp=temp->children[n];
     }
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     //printf("  letter");
     
 }
 if((char)b=='\''){
     n=26;
     
     
     
     
     if(temp->children[n]==NULL){
         temp->children[n]=malloc(sizeof(node));
         temp=temp->children[n];
         for(i=0;i<27;i++){
                temp->children[i]=NULL;
            }
         
     }
     else{
         temp=temp->children[n];
     }
     
     
     
     
     
     //printf("  apos");
 }
 if((char)b=='\n'){
     temp->is_word=true;
     temp=root;
     word++;
     //printf("  break");
 }
 //printf("%c",(char)b);
 b=fgetc(file);
    }
    // TODO
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return word;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    node *temp2;
    temp2=temp1;
    // TODO
     for(int i = 0; i < 26; i++)
    {
        if(temp1->children[i] != NULL)
        {
            temp1 = temp1->children[i];
            unload();
        }
    }

    free(temp2);
    return true;
    
}
