#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s card.raw\n", argv[0]);
		return 1;
	}

	FILE *card = fopen(argv[1], "r");
	if (card == NULL)
	{
		printf("Couldn't open %s\n", argv[1]);
		return 2;
	}

	FILE *image = NULL;
	const int BLOCK_SIZE = 512;
	uint8_t buffer[BLOCK_SIZE];
	size_t file_counter = 0;
	
	while (fread(buffer, BLOCK_SIZE, 1, card) > 0)
	{
		if (buffer[0] == 0xff &&
			buffer[1] == 0xd8 &&
			buffer[2] == 0xff &&
			(buffer[3] & 0xf0) == 0xe0)
		{
			if (image != NULL)
				fclose(image);

			if (file_counter >= 999)
			{
				printf("Too many jpegs...\n");
				fclose(card);
				return 3;
			}
			char path[8];
			sprintf(path, "%03li.jpg", file_counter);
			file_counter++;
			image = fopen(path, "w");
			if (image == NULL)
			{
				printf("Failed to create a new image: %s\n", path);
				return 4;
			}
		}

		if (image == NULL)
			continue;
		fwrite(buffer, BLOCK_SIZE, 1, image);
	}
	
	if (ferror(card))
	{
		printf("Failed to read the card\n");
		fclose(card);
		return 4;
	}

	fclose(card);
	if (image != NULL)
		fclose(image);

	return 0;
}
