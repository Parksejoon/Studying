#include <stdio.h>

int money[1001];
int dp[1001];

int main(void)
{
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &money[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (dp[i] < dp[i - j] + money[j]) dp[i] = dp[i - j] + money[j];
		}
	}

	printf("%d\n", dp[n]);
}