#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    
    char *k = argv[1];
    for (int i = 0, len = strlen(k); i < len; i++)
    {
        if (!isdigit(k[i]))
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }

    int key = atoi(k);
    char *plaintext = get_string("plaintext:  ");
    int plaintext_length = strlen(plaintext);
    char ciphertext[plaintext_length + 1];

    for (int i = 0; i < plaintext_length; i++)
    {
        char plaintext_char = plaintext[i];
        int char_index;
        if (isupper(plaintext_char))
        {
            char_index = (plaintext_char - 'A' + key) % 26;
            ciphertext[i] = char_index + 'A';
        }
        else if (islower(plaintext_char))
        {
            char_index = (plaintext_char - 'a' + key) % 26;
            ciphertext[i] = char_index + 'a';
        }
        else
        {
            char_index = plaintext_char;
            ciphertext[i] = char_index;
        }
    }

    ciphertext[plaintext_length] = '\0';
    printf("ciphertext: %s\n", ciphertext); 
    
    return 0;
}
