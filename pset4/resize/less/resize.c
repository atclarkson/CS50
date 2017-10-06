/* resize.c v0
 * A Program to resize a bmp.
 * a. Adam T Clarkson
 * e. atclarkson@gmail.com
 * d. 2017-09-29
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>

#include "bmp.h"
// Declare Function
bool isbmp(char *filename);


int main(int argc, char *argv[])
{
    // Check that program accepts exactly three command-line arguments.
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize.c n infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // Check that the first command line argument value (n) is a positive integer less than or equal to 100
    if (n < 0 || n > 100)
    {
        fprintf(stderr, "Usage: Value must be a positive integer less than or equal to 100\n");
        return 1;
    }

    // Check that infile is of type .bmp
    if (!isbmp(infile))
    {
        fprintf(stderr, "Usage: infile Filename must have extension of .bmp\n");
        return 1;
    }
    // Check that infile is of type .bmp
    if (!isbmp(outfile))
    {
        fprintf(stderr, "Usage: outfile Filename must have extension of .bmp\n");
        return 1;
    }

    // Open infile for reading
    FILE* inptr = fopen(infile, "r");
    // Check that file is not null,  return error if null.
    if (infile == NULL)
    {
        fprintf(stderr, "Unable to open %s.\n", infile);
        return 2;
    }
    // Open outfile for writing
    FILE* outptr = fopen(outfile, "w");
    // Check that file is not null,  return error if null.
    if (outfile == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Unable to create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bf_resize;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf_resize = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, bi_resize;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_resize = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


    // Determine new width and height of bitmap
    bi_resize.biWidth = bi.biWidth * n;
    bi_resize.biHeight = bi.biHeight * n;

    // determine original file padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    // determine new file padding for scanlines
    int newpadding = (4 - ((bi_resize.biWidth) * sizeof(RGBTRIPLE)) % 4) % 4;

    // Determine new infoheader and fileheader size
    bi_resize.biSizeImage = ((sizeof(RGBTRIPLE) * bi_resize.biWidth) + newpadding) * abs(bi_resize.biHeight);
    bf_resize.bfSize = bf.bfSize - bi.biSizeImage + bi_resize.biSizeImage;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_resize, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_resize, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Read each scanline n times
        for (int j = 0; j < n; j++)
        {
            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile, multiplied by n
                for (int l = 0; l < n; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // Add a new padding
            for (int l = 0; l < newpadding; l++)
            {
                fputc(0x00, outptr);
            }

            // Return to the beginning of a scanline
            if (j < n - 1)
            {
                long offset = bi.biWidth * sizeof(RGBTRIPLE);
                fseek(inptr, -offset, SEEK_CUR);
            }
        }

        // Skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}







// Function to check if file extension is a BMP or not
bool isbmp(char *filename)
{
    // Determine length of the filename
    int length = strlen(filename);

    // Check that last 3 characters are bmp in upper or lower case
    if ((filename[length - 1] == 'p') || (filename[length - 1] == 'P'))
    {
        if ((filename[length - 2] == 'm') || (filename[length - 2] == 'M'))
        {
            if ((filename[length - 3] == 'b') || (filename[length - 3] == 'B'))
            {
                return true;
            }
        }
    }
    // return false if file extension is not bmp
    return false;
}
