#include <iostream>

using namespace std;

int dp[41];

int main(void)
{
	int n, c, res = 1;
	int j, k = 0;

	cin >> n >> c;

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	for (int i = 0; i < c; i++)
	{
		cin >> j;

		res *= dp[j - k - 1];

		k = j;
	}
	res *= dp[n - k];

	cout << res << endl;
}