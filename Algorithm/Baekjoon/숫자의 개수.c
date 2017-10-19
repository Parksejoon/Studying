#include<stdio.h>

int arr[10];

int main(void)
{
	int value = 1;

	for (int i = 0; i < 3; i++)
	{
		int a;

		scanf("%d", &a);
		value *= a;
	}

	while (value >= 10)
	{
		arr[value % 10]++;
		value /= 10;
	}
	arr[value]++;

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
}