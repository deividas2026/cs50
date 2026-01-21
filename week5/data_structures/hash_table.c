#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 27

typedef struct bucket {
	char *name;
	struct bucket *next;
} bucket;

typedef struct hash_t {
	bucket *buckets[BUCKET_SIZE];	
} hash_t;

int add(hash_t *hash_table, char *name);
bool find(bucket *b, char *name);
bucket* get(hash_t *hash_table, char *name);
int hash(char *str);
void destroy(hash_t *hash_table);
void print_table(hash_t *hash_table);

int main(void)
{
	hash_t hash_table = { NULL };
		
	char *names[] = {"David", "Anton", "$James", "Dantes", "Amy", "Bob", "BOB", "bob", "BoB", "bobb", "Bobb",  "&illy", "Somali", "&ILLy", "Artiom", "Charlie", "david", "Lucy", "Bob"};	
	size_t names_len = sizeof (names) / sizeof(names[0]);
		
	for (int i = 0; i < names_len; i++)
	{
		printf("Adding %s to the hash table... ", names[i]);
		int added = add(&hash_table, names[i]);
		if (added == -1)
		{
			printf("Failure: name taken\n");
		}
		else if (added == -2)
		{
			printf("Failure: malloc failure\n");
			return 1;
		}
		else {
			printf("Success\n");
		}
	}

	char *s = "charLIe";
	printf("Checking if %s is in the hash table... ", s);
	bucket *user = get(&hash_table, s);

	if (user != NULL)
		printf("Success\n");
	else 
		printf("Failure\n");

	print_table(&hash_table);
	destroy(&hash_table);
	return 0;
}

int add(hash_t *hash_table, char *name)
{
	int bucket_index = hash(name);	
	bool name_taken = find(hash_table->buckets[bucket_index], name);	

	if (name_taken)
		return -1;

	bucket *b = malloc(sizeof(bucket));	
	if (b == NULL)
		return -2;

	b->name = malloc(strlen(name) + 1);
	if (b->name == NULL)
	{
		free(b);
		return -2;
	}

	strcpy(b->name, name);
	b->next = hash_table->buckets[bucket_index];
	hash_table->buckets[bucket_index] = b;

	return bucket_index;
}

bool find(bucket *b, char *name)
{
	for (bucket *bp = b; bp != NULL; bp = bp->next)
	{
		if (strcasecmp(bp->name, name) == 0)
			return true;
	}
	return false;
}

bucket* get(hash_t *hash_table, char *name)
{
	int bucket_index = hash(name);	
	bucket *b = hash_table->buckets[bucket_index];
	for (bucket *bp = b; bp != NULL; bp = bp->next)
	{
		if (strcasecmp(bp->name, name) == 0)
			return bp;
	}
	return NULL;
}

int hash(char *str)
{
	if (isalpha(str[0]) == 0)
		return BUCKET_SIZE - 1;

	return (tolower(str[0]) - 'a');
}


void print_table(hash_t *hash_table)
{
	printf("Hash Table:\n");
	for (int i = 0; i < BUCKET_SIZE; i++)
	{
		printf("bucket %d:", i);
		for (bucket *b = hash_table->buckets[i]; b != NULL; b = b->next)
			printf(" %s", b->name);
		printf("\n");
	}
}

void destroy(hash_t *hash_table)
{
	for (int i = 0; i < BUCKET_SIZE; i++)
	{
		bucket *b = hash_table->buckets[i];
		bucket *tmp_next;
		while (b != NULL)
		{
			tmp_next = b->next;	
			free(b->name);
			free(b);
			b = tmp_next;		
		}
	}
}
