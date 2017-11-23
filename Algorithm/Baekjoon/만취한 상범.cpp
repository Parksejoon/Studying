#include <iostream>

using namespace std;

int dp[101];

int main()
{
	int tc;

	cin >> tc;
	while (tc--)
	{
		int n;
		int cnt = 0;

		cin >> n;
		for (int i = 0; i <= n; i++)
		{
			dp[i] = 1;
		}

		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= n; j += i)
			{
				dp[j] *= -1;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			if (dp[i] == 1)
			{
				cnt++;
			}
		}

		cout << cnt << "\n";
	}
}