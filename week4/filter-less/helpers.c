#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            BYTE gray = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];

			int sepia_red = round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue);  
			if (sepia_red > 255)
				sepia_red = 255;

			int sepia_green = round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue);  
			if (sepia_green > 255)
				sepia_green = 255;

			int sepia_blue = round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue);  
			if (sepia_blue > 255)
				sepia_blue = 255;


            image[i][j].rgbtRed = sepia_red;
            image[i][j].rgbtGreen = sepia_green;
            image[i][j].rgbtBlue = sepia_blue;
        }
    }		
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
	RGBTRIPLE reflected_image[height][width];
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			reflected_image[i][width - j - 1] = image[i][j];
		}

		for (int j = 0; j < width; j++)
		{
			image[i][j] = reflected_image[i][j];
		}
	}
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
	RGBTRIPLE copy[height][width];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			// top left pixel
			if (i == 0 && j == 0)
			{
				BYTE avg_r = round((image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed) / 4.0); 
				BYTE avg_g = round((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 4.0); 
				BYTE avg_b = round((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 4.0); 
				copy[i][j].rgbtRed = avg_r;
				copy[i][j].rgbtGreen = avg_g;
				copy[i][j].rgbtBlue = avg_b;
			}
			// top right pixel
			else if (i == 0 && j == width - 1)  
			{
				BYTE avg_r = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / 4.0); 
				BYTE avg_g = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 4.0); 
				BYTE avg_b = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 4.0); 
				copy[i][j].rgbtRed = avg_r;
				copy[i][j].rgbtGreen = avg_g;
				copy[i][j].rgbtBlue = avg_b;
			}
			// top row pixels
			else if (i == 0)
			{
				BYTE avg_r = round((image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed) / 6.0); 
				BYTE avg_g = round((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen) / 6.0); 

				BYTE avg_b = round((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue) / 6.0); 
				copy[i][j].rgbtRed = avg_r;
				copy[i][j].rgbtGreen = avg_g;
				copy[i][j].rgbtBlue = avg_b;
			}
			// bottom left pixel
			else if (i == height - 1 && j == 0)
			{
				BYTE avg_r = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed) / 4.0); 
				BYTE avg_g = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen) / 4.0); 
				BYTE avg_b = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue) / 4.0); 
				copy[i][j].rgbtRed = avg_r;
				copy[i][j].rgbtGreen = avg_g;
				copy[i][j].rgbtBlue = avg_b;
			}
			// bottom right pixel
			else if (i == height - 1 && j == width - 1)
			{
				BYTE avg_r = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed) / 4.0); 
				BYTE avg_g = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen) / 4.0); 
				BYTE avg_b = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue) / 4.0); 
				copy[i][j].rgbtRed = avg_r;
				copy[i][j].rgbtGreen = avg_g;
				copy[i][j].rgbtBlue = avg_b;

			}
			// bottom row pixels
			else if (i == height - 1)
			{
				BYTE avg_r = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed) / 6.0);
				BYTE avg_g = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen) / 6.0);
				BYTE avg_b = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue) / 6.0);
				copy[i][j].rgbtRed = avg_r;
				copy[i][j].rgbtGreen = avg_g;
				copy[i][j].rgbtBlue = avg_b;
			}
			// left pixels
			else if (j == 0)
			{
				BYTE avg_r = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed) / 6.0);
				BYTE avg_g = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 6.0);
				BYTE avg_b = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 6.0);
				copy[i][j].rgbtRed = avg_r;
				copy[i][j].rgbtGreen = avg_g;
				copy[i][j].rgbtBlue = avg_b;
				
			}
			// right pixels
			else if (j == width - 1)
			{
				BYTE avg_r = round((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / 6.0);
				BYTE avg_g = round((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 6.0);
				BYTE avg_b = round((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 6.0);
				copy[i][j].rgbtRed = avg_r;
				copy[i][j].rgbtGreen = avg_g;
				copy[i][j].rgbtBlue = avg_b;
			}
			// middle pixels
			else 
			{
				BYTE avg_r = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 9.0);
				BYTE avg_g = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 9.0);
				BYTE avg_b = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 9.0);
				copy[i][j].rgbtRed = avg_r;
				copy[i][j].rgbtGreen = avg_g;
				copy[i][j].rgbtBlue = avg_b;
			}
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			image[i][j] = copy[i][j];
		}
	}
    return;
}
