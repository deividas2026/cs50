#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int number;
	struct node *next;
} node;

node* create(int number);
bool find(node *head, int number);
node* insert(node **head, int number);
void print(node *head);
void destroy(node *head);

int main(void)
{
	node *head = create(1);	
	if (head == NULL)
	{
		printf("Failed to create a list\n");
		return 1;
	}
	print(head);

	node *new = insert(&head, 2);
	if (new == NULL)
	{
		printf("Failed to insert a node\n");
		return 2;
	}
	print(head);
	
	bool exists = find(head, 1);
	if (exists)
		printf("Found 1\n");
	else
		printf("Couldn't find 1\n");

	destroy(head);
	return 0;
}

node* create(int number)
{
	node *n = malloc(sizeof(node));
	if (n == NULL)
		return NULL;
	
	n->next = NULL;
	n->number = number;
	return n;
}

bool find(node *head, int number)
{
	for (node *n = head; n != NULL; n = n->next)
	{
		if (n->number == number)
			return true;
	}
	return false;
}

node* insert(node **head, int number)
{
	node *n = malloc(sizeof(node));
	if (n == NULL)
		return NULL;
	
	n->next = *head;
	n->number = number;
	*head = n;
	return *head;
}

void print(node *head)
{
	printf("List:");
	for (node *n = head; n != NULL; n = n->next)
		printf(" %d", n->number);
	printf("\n");
}

void destroy(node *head)
{
	if (head == NULL)
		return;
	
	destroy(head->next);
	free(head);
}










