#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int number;
	struct node *next;
	struct node *prev;
} node;

void append_node(node **list, int number);
void prepend_node(node **list, int number);
void remove_node(node **list, int number);
int find_node(node *list, int number);
void print_nodes(node *list);
void release(node *list);

int main(void)
{	
	node *list = NULL;
	
	printf("Adding (appending) 10-20\n");
	for (int i = 10; i <= 20; i++)
		append_node(&list, i);
	print_nodes(list);
	
	printf("List contains 0: %d\n", find_node(list, 0));

	printf("Adding (prepending) 9-0\n");
	for (int i = 0; i < 10; i++)
		prepend_node(&list, i);
	print_nodes(list);

	printf("List contains 0: %d\n", find_node(list, 0));
	
	printf("Removing head\n");
	remove_node(&list, 9);
	print_nodes(list);

	printf("Removing tail\n");
	remove_node(&list, 20);
	print_nodes(list);

	printf("Remove some middle elements, 0 1 2 3 15 16\n");
	remove_node(&list, 0);
	remove_node(&list, 1);
	remove_node(&list, 2);
	remove_node(&list, 3);
	remove_node(&list, 15);
	remove_node(&list, 16);
	print_nodes(list);

	release(list);
	return 0;
}

void append_node(node **list, int number)
{
	node *n = malloc(sizeof(node));	
	if (n == NULL)
	{
		printf("Failed to allocate memory\n");
		release(*list);
		exit(1);
	}
	n->number = number;
	n->next = NULL;
	n->prev = NULL;

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
			n->prev = ptr;
			ptr->next = n;
			break;
		}
		ptr = ptr->next;
	}
}

void prepend_node(node **list, int number)
{
	node *n = malloc(sizeof(node));	
	if (n == NULL)
	{
		printf("Failed to allocate memory\n");
		release(*list);
		exit(1);
	}
	n->number = number;
	n->next = NULL;
	n->prev = NULL;

	if (*list == NULL)
	{
		*list = n;
		return;
	}
	
	(*list)->prev = n;
	n->next = *list;
	*list = n;
}

void remove_node(node **list, int number)
{
	node *current = *list;
	if (current == NULL)
		return;
	
	while (current != NULL)
	{
		if (current->number == number)
		{
			// remove head if the list contains more than 1 node
			if (current->prev == NULL && current->next != NULL)
			{
				current->next->prev = NULL;
				*list = current->next;
			}
			// remove node in the middle
			else if  (current->prev != NULL && current->next != NULL)
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}
			// remove tail if the list contains more than 1 node
			else if (current->next == NULL && current->prev != NULL)
			{
				current->prev->next = NULL;
			}
			// if it reaches this case, it means there's only one node in the list
			else
			{
				*list = NULL;
			}
			
			free(current);
			break;
		}
		current = current->next;
	}
}

int find_node(node *list, int number)
{
	node *current = list;
	int found_node = 0;
	while (current != NULL)
	{
		if (current->number == number)
		{
			found_node = 1;
			break;
		}	
		current = current->next;
	}
	return found_node;
}

void print_nodes(node *list)
{
	printf("List:");
	node *ptr = list;
	while (ptr != NULL)
	{
		printf(" %i", ptr->number);
		ptr = ptr->next;	
	}
	printf("\n");
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
