#include <iostream>

using namespace std;

int dp[1000];
int arr[1000];

int main(void)
{
	int n, res = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		int big = 0;

		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (dp[j] > big)
				{
					big = dp[j];
				}
			}
		}

		dp[i] = big + arr[i];
		if (dp[i] > res)
		{
			res = dp[i];
		}
	}

	cout << res << "\n";
}