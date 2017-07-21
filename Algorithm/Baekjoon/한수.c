#include<stdio.h>

int main(void)
{
	int n, result;
	int v, a, b;

	scanf("%d", &n);

	if (n < 100) result = n;
	else
	{
		result = 99;

		for (int i = 100; i <= n; i++)
		{
			v = i;
			
			a = v / 100;
			v %= 100;

			b = v / 10;
			v %= 10;

			if (b - a == v - b) result++;
		}
	}

	printf("%d\n", result);
}