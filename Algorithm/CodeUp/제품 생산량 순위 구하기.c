#include <stdio.h>

int main(void)
{
	int n;
	int arr[2000];

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		int rank = 1;

		for (int j = 0; j < n; j++)
		{
			if (arr[j] > arr[i])
			{
				rank++;
			}
		}

		printf("%d\n", rank);
	}
}