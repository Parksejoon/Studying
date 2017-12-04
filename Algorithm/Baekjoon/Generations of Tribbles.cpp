#include <iostream>

using namespace std;

long long int dp[70];

int main(void)
{
	int tc;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	cin >> tc;
	while (tc--)
	{
		int n;

		cin >> n;
		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
		}

		printf("%lld\n", dp[n]);
	}

	return 0;
}