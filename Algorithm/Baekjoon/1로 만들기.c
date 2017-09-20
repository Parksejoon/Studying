#include <stdio.h>
#include <algorithm>

int dp[1000001];

int main(void)
{
	int n;
	int a, b, c;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[0] = 10000000;

	scanf("%d", &n);

	for (int i = 4; i <= n; i++)
	{
		a = b = 0;
		c = i - 1;

		if (i % 3 == 0) a = i / 3;
		if (i % 2 == 0) b = i / 2;

		dp[i] = std::min(dp[a], std::min(dp[b], dp[c])) + 1;
	}

	printf("%d\n", dp[n]);
}