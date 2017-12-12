#include <iostream>

using namespace std;

int arr[200];
int dp[200];

int main(void)
{
	int n, res = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		int big = 0;

		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				if (big < dp[j])
				{
					big = dp[j];
				}
			}
		}

		dp[i] = big + 1;
		if (dp[i] > res)
		{
			res = dp[i];
		}
	}

	cout << n - res << endl;
}