#include <iostream>

using namespace std;

int dp[31];
int res[31];

int main(void)
{
	int n;

	dp[0] = 1;
	dp[2] = 3;
	res[0] = 1;

	for (int i = 4; i < 31; i += 2)
	{
		dp[i] = 2;
	}

	cin >> n;
	for (int i = 2; i <= n; i += 2)
	{
		for (int j = 2; j <= i; j += 2)
		{
			res[i] += res[i - j] * dp[j];
		}
	}

	cout << res[n] << "\n";
}