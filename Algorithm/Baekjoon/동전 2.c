#include <iostream>
#include <algorithm>

using namespace std;

int coin[101];
int dp[10001];

int main(void)
{
	int n, k;

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}

	dp[0] = 1;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i - coin[j] >= 0)
			{
				if (dp[i - coin[j]])
				{
					if (dp[i] == 0)
					{
						dp[i] = dp[i - coin[j]] + 1;
					}
					else
					{
						dp[i] = min(dp[i], dp[i - coin[j]] + 1);
					}
				}
			}
		}
	}

	printf("%d\n", dp[k] - 1);
}