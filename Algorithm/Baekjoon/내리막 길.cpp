#include <iostream>

using namespace std;

int h, w;
int moveX[4] = { 1, -1, 0, 0 };
int moveY[4] = { 0, 0, 1, -1 };
int arr[501][501];
int dp[501][501];

int dfs(int nowX, int nowY)
{
	if (dp[nowY][nowX] > -1)
	{
		return dp[nowY][nowX];
	}

	dp[nowY][nowX] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nextX = nowX + moveX[i];
		int nextY = nowY + moveY[i];

		if (nextX < w && nextX >= 0 &&
			nextY < h && nextY >= 0 &&
			arr[nowY][nowX] > arr[nextY][nextX])
		{
			dp[nowY][nowX] += dfs(nextX, nextY);
		}
	}

	return dp[nowY][nowX];
}

int main(void)
{
	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}

	dp[h - 1][w - 1] = 1;
	cout << dfs(0, 0) << "\n";
}