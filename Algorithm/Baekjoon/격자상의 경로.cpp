#include <iostream>

using namespace std;

int dp[16][16];

int main(void)
{
	int w, h, k;
	int pointX, pointY;

	cin >> h >> w >> k;

	if (k)
	{
		pointX = ((k - 1) % w) + 1;
		pointY = ((k - 1) / w) + 1;

		for (int i = 0; i <= pointX; i++) { dp[1][i] = 1; }
		for (int i = 0; i <= pointY; i++) { dp[i][1] = 1; }

		for (int i = 2; i <= pointY; i++)
		{
			for (int j = 2; j <= pointX; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		for (int i = pointY ; i <= h; i++)
		{
			for (int j = pointX; j <= w; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	else
	{
		for (int i = 0; i <= w; i++) { dp[1][i] = 1; }
		for (int i = 0; i <= h; i++) { dp[i][1] = 1; }

		for (int i = 2; i <= h; i++)
		{
			for (int j = 2; j <= w; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	cout << dp[h][w] << endl;

	return 0;
}