#include <stdio.h>

int main(void)
{
	int big = 0;
	int now = 0;

	for (int i = 0; i < 4; i++)
	{
		int a, b;

		scanf("%d %d", &a, &b);
		now -= a;
		now += b;

		if (now > big) big = now;
	}

	printf("%d\n", big);
}
