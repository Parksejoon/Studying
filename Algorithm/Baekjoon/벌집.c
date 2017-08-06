#include<stdio.h>

int main(void)
{
	int n, i = 1;

	scanf("%d", &n);

	for (i = 1; n > 1; i++)
	{
		n -= i * 6;
	}

	printf("%d\n", i);
}