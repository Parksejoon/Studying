#include <stdio.h>

#define MAX_ARR 7368788

int arr[MAX_ARR];

int main(void)
{
	int n, i, k = 0;
	int cnt;
	int add;

	scanf("%d", &n);

	for (i = 2; k < n; i++)
	{
		if (!arr[i])
		{
			k++;

			for (int j = i; j < MAX_ARR; j += i)
			{
				arr[j] = 1;
			}
		}
	}

	printf("%d\n", --i);
}