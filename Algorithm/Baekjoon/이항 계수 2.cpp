#include <iostream>

using namespace std;

int dp[1001][1991];

int main(void)
{
	int n, r;

	cin >> n >> r;
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 1;

		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}

	cout << dp[n][r] << "\n";
}