#include<stdio.h>

int main(void)
{
	int n, a, i;
	int big = 1, small = 100000;


	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);

		if (a > big)
		{
			big = a;
		}
		if (a < small)
		{
			small = a;
		}
	}

	printf("%d\n", big * small);
}