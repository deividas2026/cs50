#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input, int nth_digit, int length);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }
    // Convert string to int
    printf("%i\n", convert(input, 0, strlen(input)));
}

int convert(string input, int nth_digit, int length)
{
    if (length <= 0)
        return 0;

    int n = pow(10, nth_digit) * (input[length - 1] - '0');
    nth_digit++;
    length--;
    return n + convert(input, nth_digit, length);
}








