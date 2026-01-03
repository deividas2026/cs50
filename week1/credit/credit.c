#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    const int AMEX_LENGTH = 15;
    const int AMEX_LEGIT_1 = 34;
    const int AMEX_LEGIT_2 = 37;

    const int MASTER_LENGTH = 16;
    const int MASTER_LEGIT_1 = 51;
    const int MASTER_LEGIT_2 = 52;
    const int MASTER_LEGIT_3 = 53;
    const int MASTER_LEGIT_4 = 54;
    const int MASTER_LEGIT_5 = 55;

    const int VISA_LENGTH_1 = 13;
    const int VISA_LENGTH_2 = 16;
    const int VISA_LEGIT = 4;

    long card_number = get_long("Number: ");
    long card_number_copy = card_number;
    size_t card_length = 0;
    int digit, prod_a, prod_b, product;
    int is_second = 0;
    int sum = 0;
    int card_first_two_digits;
    int card_first_digit;

    while (card_number_copy > 0)
    {
        digit = card_number_copy % 10;
        if (is_second)
        {
            product = digit * 2;
            if (product > 9)
            {
                prod_a = product % 10;
                prod_b = product / 10;
                sum += prod_a + prod_b;
            }
            else
                sum += product;
        }
        else
            sum += digit;

        card_length++;
        card_number_copy /= 10;
        is_second = is_second ? 0 : 1;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    card_first_two_digits = card_number / (long) pow(10, card_length - 2);
    card_first_digit = card_first_two_digits / 10;

    if (card_length == AMEX_LENGTH &&
        (card_first_two_digits == AMEX_LEGIT_1 || card_first_two_digits == AMEX_LEGIT_2))
    {
        printf("AMEX\n");
        return 0;
    }

    if (card_length == MASTER_LENGTH &&
        (card_first_two_digits == MASTER_LEGIT_1 || card_first_two_digits == MASTER_LEGIT_2 ||
         card_first_two_digits == MASTER_LEGIT_3 || card_first_two_digits == MASTER_LEGIT_4 ||
         card_first_two_digits == MASTER_LEGIT_5))
    {
        printf("MASTERCARD\n");
        return 0;
    }

    if ((card_length == VISA_LENGTH_1 || card_length == VISA_LENGTH_2) &&
        card_first_digit == VISA_LEGIT)
    {
        printf("VISA\n");
        return 0;
    }

    printf("INVALID\n");

    return 0;
}

