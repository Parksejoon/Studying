#include <stdio.h>

#define MAX_SIZE 3

typedef struct _Queue
{
	int arr[MAX_SIZE];
	int head = 0;
	int tail = 0;
	int size = 0;
} Queue;

Queue queue;

int pop()
{
	if (queue.size <= 0)
	{
		printf("Queue is empty\n");

		return 0;
	}

	int result = queue.arr[queue.tail];

	queue.size--;
	queue.tail = (queue.tail + 1) % MAX_SIZE;

	return result;
}

void push(int n)
{
	if (queue.size >= MAX_SIZE)
	{
		printf("Queue is overflow\n");

		return;
	}

	queue.arr[queue.head] = n;
	queue.head = (queue.head + 1) % MAX_SIZE;
	queue.size++;
}

void show()
{
	int index = queue.tail;

	for (int i = 0; i < queue.size; i++)
	{
		printf("%d ", queue.arr[index++]);

		index %= MAX_SIZE;
	}

	printf("\n");
}

int main(void)
{
	push(0);
	push(1);
	push(2);
	push(3);

	show();

	pop();
	pop();

	show();

	push(2);
	push(3);

	show();

	pop();
	pop();
	pop();
	pop();

	show();
}