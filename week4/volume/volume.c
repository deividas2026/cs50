// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Custom types
typedef uint8_t BYTE;
typedef int16_t SAMPLE;
// Number of bytes in .wav header
const int HEADER_SIZE = 44;

// Function prototypes
int close_files(FILE *a, FILE *b);

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTE wav_header[HEADER_SIZE];
    size_t input_header_ret = fread(wav_header, sizeof(BYTE), HEADER_SIZE, input);
    if (input_header_ret != HEADER_SIZE)
    {
        printf("Failed to read header\n");
        close_files(input, output);
        return 1;
    }

    size_t output_header_ret = fwrite(wav_header, sizeof(BYTE), HEADER_SIZE, output); 
    if (output_header_ret != HEADER_SIZE)
    {
        printf("Failed to write header\n");
        close_files(input, output);
        return 1;
    }
    // TODO: Read samples from input file and write updated data to output file
    SAMPLE wav_sample;
    
    while (1)
    {
        size_t input_sample_ret = fread(&wav_sample, sizeof(SAMPLE), 1, input);
        if (input_sample_ret == 1)
        {
            wav_sample *= factor;
            size_t output_sample_ret = fwrite(&wav_sample, sizeof(SAMPLE), 1, output);
            if (output_sample_ret != 1)
            {
                printf("Failed to copy samples\n");
                break;
            }
        }
        else if (input_sample_ret != 1 && feof(input))
        {
            break;
        }
        else
        {
            printf("Failed to copy samples\n");
            break;
        }
    }

    // Close files
    if (close_files(input, output) != 0)
        return 1;

    return 0;
}

int close_files(FILE *input, FILE *output)
{
    int err = 0;
    if (fclose(input) != 0)
    {
        printf("Failed to close input file\n");
        err = 1;
    }
    if (fclose(output) != 0)
    {
        printf("Failed to close output file\n");
        err = 1;
    }
    return err;
}





