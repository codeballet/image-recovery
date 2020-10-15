#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 8
typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    // Check for command line argument
    if (argc != 2)
    {
        printf("Usage: recover [image]\n");
        return 1;
    }

    // Open memory card, check that it worked
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Could not open image %s", argv[1]);
        return 1;
    }

    // Initiate variables
    int filenumber = 0;
    int jpg_found = 0; // false
    FILE *img = NULL;
    BYTE buffer[BLOCK_SIZE];

    // Repeat until final read of card
    while (fread(buffer, BLOCK_SIZE, 1, infile) == 1)
    {
        // Check buffer for jpg header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (jpg_found == 1) // already found jpg file
            {
                fclose(img);
            }
            else // found first jpg file
            {
                jpg_found = 1;
            }

            char filename[FILE_NAME_SIZE];
            sprintf(filename, "%03i.jpg", filenumber++);
            img = fopen(filename, "a");
        }
        if (jpg_found == 1) // if found jpg
        {
            // Keep writing next 512 byte block
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
    }
    fclose(img);
    fclose(infile);

    return 0;
}
