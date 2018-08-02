#include <stdio.h>

int arr[101][101];

int main(void)
{
	int result = 0;

	for (int i = 0; i < 4; i++)
	{
		int sx, sy, ex, ey;

		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		for (int j = sy; j < ey; j++)
		{
			for (int k = sx; k < ex; k++)
			{
				arr[j][k] = 1;
			}
		}
	}

	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			result += arr[i][j];
		}
	}

	printf("%d\n", result);
}