#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main(void)
{
	int n, res = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		int big = 0;

		for (int j = 0; j <= i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (dp[j] > big)
				{
					big = dp[j];
				}
			}
		}

		dp[i] = big + 1;
		if (res < dp[i])
		{
			res = dp[i];
		}
	}

	cout << res << "\n";
}