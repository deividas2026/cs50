// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

//#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N] = { NULL };

// Dictionary size
size_t dictionary_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
	int hash_key = hash(word);
	for (node *b = table[hash_key]; b != NULL; b = b->next)
		if (strcasecmp(b->word, word) == 0)
			return true;
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
	FILE *fp = fopen(dictionary, "r");
	if (fp == NULL)
	{
		printf("Failed to open the file: %s.\n", dictionary);
		return false;
	}
	
	char buffer[LENGTH + 1];	
	while (fscanf(fp, "%s", buffer) == 1)
	{
		
		int hash_key = hash(buffer);		
		node *n = malloc(sizeof(node));
		if (n == NULL)
		{
			fclose(fp);
			return false;

		}
		strcpy(n->word, buffer);
		n->next = table[hash_key]; 	
		table[hash_key] = n;
		dictionary_size++;
	}

	fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dictionary_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
	for (int i = 0; i < N; i++)
	{
		node *tmp;
		node *cursor = table[i];
		while (cursor != NULL)
		{
			tmp = cursor;
			cursor = cursor->next;
			free(tmp);
		}
		table[i] = NULL;
	}
    return true;
}
