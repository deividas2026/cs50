#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    
    const int ALPHABET_LENGTH = 26;
    char *key = argv[1];

    if (strlen(key) != ALPHABET_LENGTH)
    {
        printf("Key must be 26 characters long\n");
        return 1;
    }

    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {
        if(!isalpha(key[i]))
        {
            printf("Key must only include alphabet characters\n");
            return 1;
        }
    }
    
    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {
        key[i] = toupper(key[i]);
    }

    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {   
        for (int j = i + 1; j < ALPHABET_LENGTH; j++)
        {
            if (key[i] == key[j])
            {
                printf("Key must not contain duplicate characters\n");
                return 1;
            }
        }
    }

    char *plaintext = get_string("plaintext:  ");
    int plaintext_length = strlen(plaintext);
    char ciphertext[plaintext_length + 1];
    int char_index;

    for (int i = 0; i < plaintext_length; i++)
    {
        if (isupper(plaintext[i]))
        {
            char_index = plaintext[i] - 'A';
            ciphertext[i] = key[char_index]; 
        }
        else if (islower(plaintext[i]))
        {
            char_index = plaintext[i] - 'a';
            ciphertext[i] = tolower(key[char_index]); 
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[plaintext_length] = '\0';
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}
