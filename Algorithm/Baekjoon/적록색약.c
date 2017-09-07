#include<stdio.h>

char field[100][100];
int isFirst[100][100];
int moveX[4] = { 0, 0, 1, -1 };
int moveY[4] = { 1, -1, 0, 0 };
int n;

void S_dfs(int nowY, int nowX)
{
	isFirst[nowY][nowX] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nextY = nowY + moveY[i];
		int nextX = nowX + moveX[i];

		if (field[nextY][nextX] == field[nowY][nowX]
			&& nextX >= 0 && nextX < n
			&& nextY >= 0 && nextY < n
			&& isFirst[nextY][nextX])
		{
			S_dfs(nowY + moveY[i], nowX + moveX[i]);
		}
	}

	return;
}

void N_dfs(int nowY, int nowX)
{
	isFirst[nowY][nowX] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextY = nowY + moveY[i];
		int nextX = nowX + moveX[i];

		if (field[nextY][nextX] == field[nowY][nowX]
			&& nextX >= 0 && nextX < n
			&& nextY >= 0 && nextY < n
			&& !isFirst[nextY][nextX])
		{
			N_dfs(nowY + moveY[i], nowX + moveX[i]);
		}
	}

	return;
}

int main(void)
{
	int cnt = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", field[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!isFirst[i][j])
			{
				cnt++;
				N_dfs(i, j);
			}
		}
	}

	printf("%d ", cnt);
	cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (field[i][j] == 'R')
			{
				field[i][j] = 'G';
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isFirst[i][j])
			{
				cnt++;
				S_dfs(i, j);
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}