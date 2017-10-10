#include <stdio.h>
#include <algorithm>

int check[51][51];
int dp[51][51];
char field[51][51];
int moveX[4] = { 1, -1, 0, 0 };
int moveY[4] = { 0, 0, -1, 1 };
int h, w;

int dfs(int nowX, int nowY)
{
	if (nowX < 0 || nowX >= w || nowY < 0 || nowY >= h || field[nowY][nowX] == 'H') return 0;
	if (check[50][50])
	{
		printf("-1\n");
		exit(0);
	}
	if (dp[nowY][nowX]) return dp[nowY][nowX];

	int big = 0;

	check[nowY][nowX] = 1;
	for (int i = 0; i < 4; i++)
	{
		int value = dfs(nowX + (field[nowY][nowX] - 48) * moveX[i], nowY + (field[nowY][nowX] - 48) * moveY[i]);
		if (big < value) big = value;
	}
	check[nowY][nowX] = 0;

	return dp[nowY][nowX] = big + 1;
}

int main(void)
{
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++)
	{
		scanf("%s", field[i]);
	} 

	printf("%d\n", dfs(0, 0));

	return 0;
}