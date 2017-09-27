#include <iostream>
#include <algorithm>

using namespace std;

int n;
int sum[501];
int arr[501];
int dp[501][501];

int main(void)
{
	int tc;

	cin >> tc;
	while (tc--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}

		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j + i <= n; j++)
			{
				int h = j + i;

				dp[j][h] = 214700000;

				for (int k = j; k < h; k++)
				{
					dp[j][h] = min(dp[j][h], dp[j][k] + dp[k + 1][h] + sum[h] - sum[j - 1]);
				}
			}
		}

		cout << dp[1][n] << "\n";
	}
}