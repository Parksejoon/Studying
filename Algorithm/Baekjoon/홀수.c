#include <stdio.h>

int main(void)
{
	int min = 101;
	int sum = 0;

	for (int i = 0; i < 7; i++)
	{
		int n;

		scanf("%d", &n);
		if (n % 2)
		{
			if (n < min)
			{
				min = n;
			}

			sum += n;
		}

	}

	if (!sum)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", sum);
		printf("%d\n", min);
	}
}