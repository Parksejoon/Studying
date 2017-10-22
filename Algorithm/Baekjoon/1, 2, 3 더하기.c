#include <stdio.h>

int main(void)
{
	int t;

	scanf("%d", &t);
	while (t--)
	{
		int dp[12] = { 0 };
		int n;

		scanf("%d", &n);

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				dp[i] += dp[i - j];
			}
		}

		printf("%d\n", dp[n]);
	}
}