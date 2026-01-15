#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLATES 8
#define PLATE_LENGTH 7

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[PLATE_LENGTH];

    // Create array to store plate numbers
    char *plates[PLATES];
	for (int i = 0; i < PLATES; i++)
	{
		plates[i] = malloc(PLATE_LENGTH);
		if (plates[i] == NULL)
		{
			printf("Failed to allocate memory to *plates[PLATES]\n");
			return 2;
		}
	}

    FILE *infile = fopen(argv[1], "r");
	if (infile == NULL)
	{
		printf("Failed to open %s\n", argv[1]);
		return 3;
	}
	
    int idx = 0;

    while (fread(buffer, 1, PLATE_LENGTH, infile) == PLATE_LENGTH && idx < PLATES)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';
        // Save plate number in array
		strcpy(plates[idx], buffer);
        idx++;
    }

    for (int i = 0; i < PLATES; i++)
        printf("%s\n", plates[i]);

	for (int i = 0; i < PLATES; i++)
		free(plates[i]);

	fclose(infile);
	return 0;
}
