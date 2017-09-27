#include<stdio.h>

int street[1000][3];

int main(void)
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &street[i][j]);
		}
	}

	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < 3; j++)
		{
			int small;

			switch (j)
			{
			case 0:
				if (street[i][1] < street[i][2]) small = 1;
				else small = 2;
				break;
			case 1:
				if (street[i][0] < street[i][2]) small = 0;
				else small = 2;
				break;
			case 2:
				if (street[i][0] < street[i][1]) small = 0;
				else small = 1;
				break;
			default:
				break;
			}

			street[i - 1][j] += street[i][small];
		}
	}

	int small = street[0][0];
	for (int i = 1; i < 3; i++)
	{
		if (small > street[0][i]) small = street[0][i];
	}

	printf("%d\n", small);
}