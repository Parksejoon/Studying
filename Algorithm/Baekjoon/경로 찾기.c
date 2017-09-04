#include<stdio.h>

int n;
int field[100][100];
int result[100][100];

void dfs(int start, int now)
{	
	if (!result[start][now])
	{
		result[start][now] = 1;

		for (int i = 0; i < n; i++)
		{
			if (field[now][i])
			{
				dfs(start, i);
				dfs(now, i);
			}
		}
	}

	return;
}

int main(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &field[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (field[i][j])
			{
				dfs(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", result[i][j]);
		}

		printf("\n");
	}
}