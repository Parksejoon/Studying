#include <iostream>
#include <algorithm>
using namespace std;

char arr[1001][1001];
int dp[1001][1001];

int main(void)
{
	int n, m, k = 0;


	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j])
			{
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				
				if (k < dp[i][j])
				{
					k = dp[i][j];
				}
			}
		}
	}

	cout << k * k << endl;
}