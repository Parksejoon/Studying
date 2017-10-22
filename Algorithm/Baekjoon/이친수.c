#include <stdio.h>

long long int dp[91];

int main(void)
{
	int n;

	dp[1] = dp[2] = 1;

	scanf("%d", &n);
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	printf("%lld\n", dp[n]);
}