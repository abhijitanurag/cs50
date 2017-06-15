#include<stdio.h>
#include<cs50.h>
#include <stdint.h>
int main(int argc,string argv[]){
     if (argc != 2)
    {
        fprintf(stderr, " provide proper argument\n");
        return 1;
    }
    char *infile = argv[1];
     FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    //int flag=0;
   
   int k=0;
    uint8_t  buffer[512]={0};
    FILE *outptr=NULL;
    char filename[8];
    
    while(fread(buffer, 512, 1, inptr)==1)
    { 
        if (buffer[0]==0xff&&buffer[1]==0xd8&&buffer[2]==0xff&&(buffer[3]&0xf0)==0xe0)
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }

            
            sprintf(filename, "%03d.jpg", k);
            outptr = fopen(filename, "a");

             
            fwrite(buffer, 512, 1, outptr);

            k++;
        }
        else if(k!=0){
            fwrite(buffer, 512, 1, outptr);
        }
    }
    fclose(inptr);
    fclose(outptr);
    
    
    
    return 0;
}