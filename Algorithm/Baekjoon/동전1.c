#include <iostream>

using namespace std;

int dp[10001];

int main(void)
{
	int coin[101];
	int n, k;
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}

	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			dp[j] += dp[j - coin[i]];
		}
	}

	printf("%d\n", dp[k]);
}