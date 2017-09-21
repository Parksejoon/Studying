#include <stdio.h>

long long int dp[100][10];

int main(void)
{
	int n;
	long long int sum = 0;
	
	for (int i = 0; i < 10; i++)
	{
		dp[0][i] = 1;
	}

	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][1] % 1000000000;
		for (int j = 1; j < 9; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
		dp[i][9] = dp[i - 1][8] % 1000000000;
	}

	for (int i = 1; i < 10; i++)
	{
		sum += dp[n - 1][i];
	}

	printf("%lld\n", sum % 1000000000);
}