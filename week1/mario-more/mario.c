#include <cs50.h>
#include <stdio.h>

int main()
{
    int height = 0;
    int spaces = 0;

    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }

    for (int i = 1; i <= height; i++)
    {
        spaces = height - i;
        for (int j = 0; j < spaces; j++)
            printf(" ");
        for (int k = 0; k < i; k++)
            printf("#");
        printf("  ");
        for (int k = 0; k < i; k++)
            printf("#");
        printf("\n");
    }

    return 0;
}

