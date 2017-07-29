#include<stdio.h>

char arr[100][101] = { 0 };
char temp[100][101] = { 0 };
int n;

void check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c", arr[i][j]);
		}

		printf("\n");
	}
}

void rotate()
{
	int x = n - 1, y = 0;

	for (int i = 0; i < n; i++)
	{
		y = 0;

		for (int j = 0; j < n; j++)
		{
			temp[y++][x] = arr[i][j];
 		}

		x--;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = temp[i][j];
		}
	}
}

void down()
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] != '.')
			{
				int cnt = 0;

				for (int k = i; k < n; k++)
				{
					if (arr[k][j] == '.') cnt++;
				}

				arr[i + cnt][j] = arr[i][j];
				arr[i][j] = '.';
			}
		}
	}
}

int main(void)
{
	int a;

	scanf("%d %d", &n, &a);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < a; i++)
	{
		rotate();
		down();
	}
	
	check();
}