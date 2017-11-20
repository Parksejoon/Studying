#include <iostream>

using namespace std;

int dp[100001];

int main()
{
	int n;

	for (int i = 1; i <= 316; i++)
	{
		dp[i * i] = 1;
	}

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (!dp[i])
		{
			dp[i] = 1000;

			for (int j = 1; j <= i / 2; j++)
			{
				int now = dp[j] + dp[i - j];

				if (now < dp[i])
				{
					dp[i] = now;
				}
			}
		}
	}

	cout << dp[n] << "\n";
}