#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int number;
	struct node *next;
} node;

void append(node **list, int number);
void prepend(node **list, int number);
//void delete(node *list, int number);
void print(node *list);
void release(node *list);

int main(void)
{
	node *list = NULL;
	append(&list, 1);
	append(&list, 2);
	append(&list, 3);

	print(list);
	release(list);
	return 0;
}

void append(node **list, int number)
{
	node *n = malloc(sizeof(node));	
	n->number = number;
	n->next = NULL;

	if (*list == NULL)
	{
		*list = n;
		return;
	}
	
	node *ptr = *list;
	while (ptr != NULL)
	{
		if (ptr->next == NULL)
		{
			ptr->next = n;
			break;
		}
		ptr = ptr->next;
	}
}

void prepend(node **list, int number)
{
	node *n = malloc(sizeof(node));
	n->number = number;
	n->next = NULL;

	if (*list == NULL)
	{
		*list = n;
		return;
	}

	n->next = *list;
	*list = n;	
}

void print(node *list)
{
	node *ptr = list;
	while (ptr != NULL)
	{
		printf("%i\n", ptr->number);
		ptr = ptr->next;	
	}
}

void release(node *list)
{
	node *ptr = list;
	while (ptr != NULL)
	{
		node *tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
}
