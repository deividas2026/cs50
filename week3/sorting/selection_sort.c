#include <stdio.h>

void print_numbers(int numbers[], int len);

int main(void)
{
    int numbers[] = {-2, 4, 5, 1, 2, 0, 66, 22, 5, 42, 6, 8, 96, 9, 3, 44};
    int numbers_length = sizeof(numbers) / sizeof(numbers[0]);

    printf("Before: ");
    print_numbers(numbers, numbers_length);
    printf("\n");

    for (int i = 0; i < numbers_length; i++)
    {
        int lowest = numbers[i];
        int lowest_index = i;
        for (int j = i + 1; j < numbers_length; j++)
        {
            if (numbers[j] < lowest)
            {
                lowest = numbers[j];
                lowest_index = j;
            }
        }
        numbers[lowest_index] = numbers[i];
        numbers[i] = lowest;
    }

    printf("After:  ");
    print_numbers(numbers, numbers_length);
    printf("\n");

    return 0;
}

void print_numbers(int numbers[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%2d ", numbers[i]);
    }
}
