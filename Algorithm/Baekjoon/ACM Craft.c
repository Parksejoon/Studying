#include <stdio.h>

int link[1001][1001];

int dfs(int* money, int* dp, int n, int now)
{
	int big = 0;

	if (dp[now])
	{
		return dp[now];
	}

	for (int i = 1; i <= n; i++)
	{
		if (link[i][now])
		{
			int value = dfs(money, dp, n, i);

			if (value > big) big = value;
		}
	}

	int ans = big + money[now];
	if (dp[now] < ans)
	{
		dp[now] = ans;
	}

	return ans;
}

int main(void)
{
	int t;

	scanf("%d", &t);
	while (t--)
	{
		int n, k, goal;
		int money[1001] = { 0 };
		int dp[1001] = { 0 };
		
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &money[i]);
			
			for (int j = 1; j <= n; j++)
			{
				link[i][j] = 0;
			}
		}

		for (int i = 0; i < k; i++)
		{
			int a, b;
			
			scanf("%d %d", &a, &b);
			link[a][b] = 1;
		}

		scanf("%d", &goal);
		printf("%d\n", dfs(money, dp, n, goal));
	}
}