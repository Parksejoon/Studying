#include <iostream>

using namespace std;

int dp[31][31];

int main(void)
{
	int tc;

	for (int i = 0; i <= 30; i++)
	{
		dp[1][i] = i;
	}

	for (int i = 2; i <= 30; i++)
	{
		for (int j = i; j <= 30; j++)
		{
			for (int k = j; k >= i; k--)
			{
				dp[i][j] += dp[i - 1][k - 1];
			}
		}
	}

	cin >> tc;
	while (tc--)
	{
		int n, m;

		cin >> n >> m;
		cout << dp[n][m] << endl;
	}
}