// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool uppercase = false;
    bool lowercase = false;
    bool number = false;
    bool symbol = false;

    for (int i = 0, len = strlen(password); i < len; i++)
    {
        char c = password[i];
        if (isdigit(c))
        {
            number = true;
        }
        else if (isalpha(c) && isupper(c))
        {
            uppercase = true;
        }
        else if (isalpha(c) && islower(c))
        {
            lowercase = true;
        }
        else if (ispunct(c))
        {
            symbol = true;
        }
    }

    if (uppercase && lowercase && number && symbol)
    {
        return true;
    }

    return false;
}
