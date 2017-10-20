#include <stdio.h>

int main(void)
{
	int a, b;
	int na = 0, nb = 0;

	scanf("%d %d", &a, &b);

	for (int i = 1; i <= 3; i++)
	{
		na *= 10;
		nb *= 10;

		na += a % 10;
		nb += b % 10;
		
		a /= 10;
		b /= 10;
	}

	if (na > nb) printf("%d\n", na);
	else printf("%d\n", nb);
}