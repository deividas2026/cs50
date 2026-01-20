#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int value;
	struct stack *next;
} stack;

void push(stack **s, int value);
void pop(stack **s);
void print(stack *s);
void destroy(stack *s);

int main(void)
{
	stack *s = NULL;

	pop(&s);
	print(s);
	
	int i = 10;
	while (i > 0)
		push(&s, i--);
	print(s);

	pop(&s);
	print(s);
	pop(&s);
	print(s);
	pop(&s);
	print(s);
	pop(&s);
	print(s);
	push(&s, 2);
	print(s);
	destroy(s);
	return 0;
}

void push(stack **s, int value)
{
	stack *n = malloc(sizeof(stack));
	
	if (n == NULL)
	{
		destroy(*s);
		exit(1);
	}
	n->value = value;
	n->next = *s;
	*s = n;
}
void pop(stack **s)
{
	if (*s == NULL)
	{
		printf("Stack is empty\n");
		return;
	}

	stack *tmp = (*s)->next;
	free(*s);
	*s = tmp;
	return;
}
void destroy(stack *s)
{
	if (s == NULL)
		return;
	
	destroy(s->next);
	free(s);
}
void print(stack *s)
{
	stack *n = s;
	while (n != NULL)
	{
		printf("%d ", n->value);
		n = n->next;
	}
	printf("\n");
}
