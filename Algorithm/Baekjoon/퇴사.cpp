#include <iostream>
#include <algorithm>

using namespace std;

int dp[16];
pair<int, int> input[16];

int main(void)
{
	int n;
	int ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t, p;

		cin >> t >> p;

		for (int k = i + t; k <= n; k++)
		{
			dp[k] = max(dp[k], dp[i] + p);
		}
	}

	for (int i = 0; i <= n; i++)
	{
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;
}