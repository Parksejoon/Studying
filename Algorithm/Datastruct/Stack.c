#include <stdio.h>

#define MAX_SIZE 10

typedef struct _Stack
{
	int stack_arr[MAX_SIZE];
	int top = 0;
} Stack;

Stack stack;

int pop()
{
	if (stack.top > 0)
	{
		return stack.stack_arr[stack.top--];
	}
	else
	{
		printf("Stack is empty\n");

		return 0;
	}
}

void push(int n)
{
	if (MAX_SIZE > stack.top)
	{
		stack.stack_arr[stack.top++] = n;
	}
	else
	{
		printf("Stack overflow\n");

		return;
	}

	return;
}

void show()
{
	for (int i = stack.top - 1; i >= 0; i--)
	{
		printf("%d\n", stack.stack_arr[i]);
	}

	printf("\n");
}

int main(void)
{
	push(0);
	push(1);

	push(0);
	push(1);

	push(0);
	push(1);

	push(0);
	push(1);

	push(0);
	push(1);

	push(0);
	push(1);

	show();
}