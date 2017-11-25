#include <iostream>
#include <queue>

using namespace std;

int n;
int moveX[4] = { 0, 0, 1, -1 };
int moveY[4] = { 1, -1, 0, 0 };
int arr[500][500];
int dp[500][500];

int dfs(int nowX, int nowY)
{
	int big = 0;

	if (dp[nowY][nowX]) return dp[nowY][nowX];

	for (int i = 0; i < 4; i++)
	{
		int nextX = nowX + moveX[i];
		int nextY = nowY + moveY[i];

		if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n)
		{
			if (arr[nextY][nextX] > arr[nowY][nowX])
			{
				dfs(nextX, nextY);

				if (big < dp[nextY][nextX])
				{
					big = dp[nextY][nextX];
				}
			}
		}
	}

	return dp[nowY][nowX] = big + 1;
}

int main()
{
	int big = 1;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!dp[i][j])
			{
				dfs(j, i);
			}

			if (big < dp[i][j])
			{
				big = dp[i][j];
			}
		}
	}

	cout << big << "\n";
}