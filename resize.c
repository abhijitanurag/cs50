
/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
char *size=argv[1];
int n=atoi(size);
if(!(n>0&&n<=100)){
    return 1;
}
//printf("%d",n);
    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    //BITMAPFILEHEADER bf1;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
      //  BITMAPINFOHEADER bi1;
       
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
   // printf("pa1 %d\n",padding);
     bi.biWidth*=n;
       bi.biHeight*=n;
        int padding1 = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
       // printf("pa1 %d",padding1);
        bi.biSizeImage=((sizeof(RGBTRIPLE)*bi.biWidth)+padding1)*abs(bi.biHeight);
         bf.bfSize=bi.biSizeImage+sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    // iterate over infile's scanlines
  //  if(n!=1){
  for (int i = 0, biHeight = abs(bi.biHeight/n); i < biHeight; i++)
    {
    long pos= ftell(inptr);
    //printf("%li\n",pos);
        // iterate over pixels in scanline
        //printf("%li \n",pos);
        for(long mm=0;mm<n;mm++){
        for (int j = 0; j < bi.biWidth/n; j++)
        {
           
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            for(long z=0;z<n;z++){
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
 

        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding1; k++)
        {
            fputc(0x00, outptr);
        }
        if(mm!=n-1)
        fseek(inptr, pos, SEEK_SET);
     //    printf("%li \n\n",ftell(inptr));
        }
         
    }

    

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}

