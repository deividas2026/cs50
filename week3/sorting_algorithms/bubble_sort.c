#include <stdio.h>

void print_numbers(int numbers[], int len);

int main(void)
{
    int numbers[] = {-2, 4, 5, 1, 2, 0, 66, 22, 5, 42, 6, 8, 96, 9, 3, 44};
    int numbers_length = sizeof(numbers) / sizeof(numbers[0]);

    printf("Before: ");
    print_numbers(numbers, numbers_length);
    printf("\n");

    for (int i = 0, len = numbers_length - 1; i < len; len--)
    {
        int swaps = 0; 
        for (int j = 0; j < len; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j + 1];
                numbers[j + 1] = numbers[j];
                numbers[j] = temp;
                swaps++;
            }
        }
        if (swaps == 0) break;
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
