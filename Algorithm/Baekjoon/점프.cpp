#include <iostream>

using namespace std;

int n;
int moveX[2] = { 0, 1 };
int moveY[2] = { 1, 0 };
int arr[100][100];
unsigned long long int dp[100][100];

unsigned long long int dfs(int nowY, int nowX)
{
	if (dp[nowY][nowX]) return dp[nowY][nowX];
	if (nowY == nowX && nowY == n - 1) return 1;
	if (!arr[nowY][nowX]) return 0;

	unsigned long long int sum = 0;
	
	for (int i = 0; i < 2; i++)
	{
		int nextX = nowX + moveX[i] * arr[nowY][nowX];
		int nextY = nowY + moveY[i] * arr[nowY][nowX];

		if (nextX < n && nextY < n)
		{
			sum += dfs(nextY, nextX);
		}
	}

	return dp[nowY][nowX] = sum;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	printf("%lld\n", dfs(0, 0));

	return 0;
}