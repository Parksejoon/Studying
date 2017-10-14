#include <stdio.h>
#include <algorithm>

int res[25];
int arr[26][26];
int moveX[4] = { 0, 0, 1, -1 };
int moveY[4] = { 1, -1, 0, 0 };
int n, ind;

int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a < *(int*)b) return -1;
	return 0;
}

int dfs(int nowX, int nowY)
{
	int sum = 0;

	arr[nowY][nowX] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nextX = nowX + moveX[i];
		int nextY = nowY + moveY[i];

		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && arr[nextY][nextX])
		{
			sum += dfs(nextX, nextY);
		}
	}

	return sum + 1;
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j]) res[ind++] = dfs(j, i);
		}
	}

	printf("%d\n", ind);
	qsort(res, ind, sizeof(int), compare);
	for (int i = 0; i < ind; i++)
	{
		printf("%d\n", res[i]);
	}
}