// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <stdio.h>
#include <string.h>

char *replace(char *input);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s word\n", argv[0]);
        return 1;
    }
    printf("%s\n", replace(argv[1]));
    return 0;
}

char *replace(char *input)
{
    for (int i = 0, len = strlen(input); i < len; i++)
    {
        switch(input[i])
        {
            case 'a':
                input[i] = '6';
                break;
            case 'e':
                input[i] = '3';
                break;
            case 'i':
                input[i] = '1';
                break;
            case 'o':
                input[i] = '0';
                break;
            default:
                break;
        }
    }
    return input;
}
