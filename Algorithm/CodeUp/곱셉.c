#include <stdio.h>

int main(void)
{
	int a, b[3];
	int c, d, e;

	scanf("%d", &a);

	for (int i = 0; i < 3; i++)
	{
		scanf("%1d", &b[i]);
	}

	c = b[2] * a;
	d = b[1] * a;
	e = b[0] * a;

	printf("%d\n%d\n%d\n%d\n", c, d, e, c + d * 10 + e * 100);
}