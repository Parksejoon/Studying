#include <stdio.h>

int arr[10000];

int main(void)
{
	int temp;
	int a, x;

	scanf("%d %d", &a, &x);
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &temp);

		if (temp < x) arr[i] = temp;;
	}

	for (int i = 0; i < a; i++)
	{
		if (arr[i])
		{
			printf("%d ", arr[i]);
		}
	}
}