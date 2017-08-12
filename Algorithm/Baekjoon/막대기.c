#include<stdio.h>

int arr[65];

int main(void)
{
	int x, sum;
	int index = 0;

	sum = 64;
	arr[0] = 64;
	scanf("%d", &x);

	while (sum != x)
	{
		if (x <= sum - (arr[index] / 2))
		{
			sum -= arr[index] / 2;
			arr[index] = arr[index] / 2;
		}
		else
		{
			arr[index] = arr[index] / 2;
			arr[++index] = arr[index - 1];
		}
	}

	printf("%d\n", index + 1);
}