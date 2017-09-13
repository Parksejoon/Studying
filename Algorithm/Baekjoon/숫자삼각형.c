#include<stdio.h>

int arr[501][501];
int result[501][501];

int main(void)
{
	int story;

	scanf("%d", &story);
	for (int i = 0; i < story; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < story - 1; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (arr[i][j] + arr[i + 1][j] > result[i + 1][j])
			{
				result[i + 1][j] = arr[i][j] + arr[i + 1][j];
			}
			if (arr[i][j] + arr[i + 1][j + 1] > result[i + 1][j + 1])
			{
				result[i + 1][j + 1] = arr[i][j] + arr[i + 1][j + 1];
			}
		}

		for (int j = 0; j <= i + 1; j++)
		{
			arr[i + 1][j] = result[i + 1][j];
		}
	}

	int big = 0;
	for (int i = 0; i < story; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (big < result[i][j]) big = result[i][j];
		}
	}

	printf("%d\n", big);
}