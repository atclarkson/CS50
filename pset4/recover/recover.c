/* recover.c v0
 * A program to recover deleted images from a memory card.
 * a. Adam T Clarkson
 * e. atclarkson@gmail.com
 * d. 2017-10-01
 */

#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check that program accepts exactly 1 command-line argument.
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    // remember filename
    char *infile = argv[1];
    // Open infile for reading
    FILE* inptr = fopen(infile, "r");
     // Check that file is not null,  return error if null.
    if (infile == NULL)
    {
        fprintf(stderr, "Unable to open %s.\n", infile);
        return 2;
    }

    // Define Variables
    BYTE buffer[512];   // a buffer to hold 512 bytes of data
    int counter = 0;    // Counter to assign file names
    char filename[10];  // Char array to store the resultent string
    FILE* temp = NULL;  // temp file output



    //  Read a 512 byte block from infile
    while (!feof(inptr))
    {
        //fread(buffer, 512, 1, inptr);
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // if already exist, then close file
            if (temp != NULL)
            {
                fclose(temp);

            }
            sprintf(filename, "%03i.jpg", counter);
            // Open file for writing
            temp = fopen(filename, "w");
            counter++;
            // new file with buffer
            fwrite(buffer, sizeof(buffer), 1, temp);
        }
        else if (counter > 0)
        {
            // put jpg into temp
            fwrite(buffer, sizeof(buffer), 1, temp);

        }

        fread(buffer, sizeof(buffer), 1, inptr);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(temp);

    // success
    return 0;
}