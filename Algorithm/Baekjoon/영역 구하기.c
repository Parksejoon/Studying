#include<stdio.h>
#include<stdlib.h>

int m, n, k;
int field[100][100];
int moveX[4] = { 1, -1, 0, 0 };
int moveY[4] = { 0, 0, 1, -1 };
int count[100];
int index;

int compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
	{
		return 1;
	}
	else if (*(int*)first < *(int*)second)
	{
		return -1;
	}
	
	return 0;
}

void dfs(int nowX, int nowY)
{
	field[nowY][nowX] = 1;

	for (int i = 0; i < 4; i++)
	{
		if (nowX + moveX[i] >= 0 && nowX + moveX[i] < n &&
			nowY + moveY[i] >= 0 && nowY + moveY[i] < m &&
			!field[nowY + moveY[i]][nowX + moveX[i]])
		{
			count[index]++;
			dfs(nowX + moveX[i], nowY + moveY[i]);
		}
	}
}

int main(void)
{
	int cnt = 0;

	scanf("%d %d %d", &m, &n, &k);

	for (int i = 0; i < k; i++)
	{
		int sx, sy;
		int ex, ey;

		scanf("%d %d", &sx, &sy);
		scanf("%d %d", &ex, &ey);

		for (int k = sy; k < ey; k++)
		{
			for (int j = sx; j < ex; j++)
			{
				field[k][j] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!field[i][j])
			{
				cnt++;
				count[index] = 1;
				dfs(j, i);
				index++;
			}
		}
	}

	printf("%d\n", cnt);
	qsort(count, index, sizeof(int), compare);

	for (int i = 0; i < index; i++)
	{
		printf("%d ", count[i]);
	}
}