#include <iostream>
#include <algorithm>

using namespace std;

long long dp[101];

int main(void)
{
	int t, n;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i < 101; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << dp[n] << "\n";
	}
}