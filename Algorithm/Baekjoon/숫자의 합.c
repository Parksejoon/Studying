#include <stdio.h>

int main(void)
{
	int sum = 0;
	int temp;
	int n;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%1d", &temp);
		sum += temp;
	}

	printf("%d\n", sum);
}