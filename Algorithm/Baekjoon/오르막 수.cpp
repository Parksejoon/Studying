#include <iostream>

using namespace std;

int dp[1002][10];

int main(void)
{
	int n;

	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	cin >> n;
	for (int i = 1; i <= n + 1; i++)
	{
		dp[i][0] = 1;

		for (int j = 1; j < 10; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
		}
	}

	cout << dp[n + 1][9] << "\n";
}