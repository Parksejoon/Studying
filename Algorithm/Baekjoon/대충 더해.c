#include<stdio.h>

char a[7];
char b[7];

int main(void)
{
	scanf("%s", a);
	scanf("%s", b);

	while (!a[6])
	{
		int ind = 6;

		while (ind)
		{
			ind--;

			if (a[ind] && !a[ind + 1])
			{
				a[ind + 1] = a[ind];
				a[ind] = NULL;
			}
		}
	}

	while (!b[6])
	{
		int ind = 6;

		while (ind)
		{
			ind--;

			if (b[ind] && !b[ind + 1])
			{
				b[ind + 1] = b[ind];
				b[ind] = NULL;
			}
		}
	}

	for (int i = 0; i < 7; i++)
	{
		int n = 0;

		if (a[i] + b[i] == NULL) continue;

		if (a[i]) n++;
		if (b[i]) n++;
		printf("%d", a[i] + b[i] - 48 * n);
	}
}
