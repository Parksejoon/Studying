#include <stdio.h>

int moveX[4] = { 0, 0, 1, -1 };
int moveY[4] = { 1, -1, 0, 0 };
int che[30];
char arr[21][21];
int h, w;

int dfs(int nowX, int nowY)
{
	int big = 0;

	che[arr[nowY][nowX] - 65] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextY = nowY + moveY[i];
		int nextX = nowX + moveX[i];
		
		if (!che[arr[nextY][nextX] - 65]
			&& nextY >= 0 && nextY < h
			&& nextX >= 0 && nextX < w)
		{
			int value = dfs(nextX, nextY);
			
			if (big < value) big = value;
		}
	}
	che[arr[nowY][nowX] - 65] = 0;

	return big + 1;
}

int main(void)
{
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++)
	{
		scanf("%s", arr[i]);
	}

	printf("%d\n", dfs(0, 0));
}