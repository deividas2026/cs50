// Coleman-Liau formula to calculate reading level (index) of a text.
// index = 0.0588 * L - 0.296 * S - 15.8
// where L is the average number of letters per 100 words in the text,
// and S is the average number of sentences per 100 words in the text.

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calculate_reading_level(char *text);
void print_reading_level(int reading_level);

int main(void)
{
    char *text = get_string("Text: "); 
    int reading_level = calculate_reading_level(text);  
    print_reading_level(reading_level);
    return 0;
}

int calculate_reading_level(char *text)
{
    int words = 1;
    int sentences = 0;
    int letters = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences++;
        else if (text[i] == ' ')
            words++;
        else if (isalpha(text[i]))
            letters++;
    }
    
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    return index;
}

void print_reading_level(int reading_level)
{
    if (reading_level >= 16)
        printf("Grade 16+\n");
    else if (reading_level < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %d\n", reading_level);
}
