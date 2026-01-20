#include <stdbool.h>
#include <stdio.h>

#define CAPACITY 5
#define ADD 20
#define REMOVE 11

typedef struct stack {
	int array[CAPACITY];
	int top;
} stack;

typedef struct {
	int value;
	bool ok;
} popped;

bool push(stack *s, int value);
popped pop(stack *s);
void print(stack *s);

int main(void)
{
	stack s;
	s.top = 0;

	print(&s);
	for (int i = 0; i < ADD; i++)
	{
		printf("push(%d)\n", i);
		if (!push(&s, i)) 	
		{
			printf("Stack reached its maximum capacity: %d\n", CAPACITY);
			break;
		}
		print(&s);
	}
	printf("\n");

	popped n;
	for (int i = 0; i < REMOVE; i++)
	{
		printf("int n = pop()\n");
		n = pop(&s);
		if (n.ok)
		{
			printf("n = %d\n", n.value);
		}
		else
		{
			printf("Stack: (empty)\n");
			break;
		}
		print(&s);
	}

	return 0;
}

bool push(stack *s, int value)
{
	if (s->top >= CAPACITY)
		return false;
	s->array[s->top] = value;
	s->top += 1;
	return true;
}

popped pop(stack *s)
{
	popped r = {.value = 0, .ok = false};
	if (s->top <= 0)
	{
		r.ok = false;
		return r;
	}
	s->top -= 1;
	r.value = s->array[s->top];
	r.ok = true;
	return r;
}

void print(stack *s)
{
	if (s->top <= 0)
	{
		printf("Stack: (empty)\n");
		return;
	}

	printf("Stack:");
	for (int i = 0, stack_size = s->top; i < stack_size; i++)
		printf(" %d", s->array[i]);
	
	printf("\n");
}
