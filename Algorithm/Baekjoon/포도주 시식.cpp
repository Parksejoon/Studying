#include <iostream>
#include <algorithm>

using namespace std;

int dp[10001];
int table[10001];

int main(void)
{
	int big = 0;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> table[i];
	}
	
	dp[0] = table[0];
	dp[1] = table[0] + table[1];
	dp[2] = max(table[2] + max(table[0], table[1]), table[0] + table[1]);
	for (int i = 3; i < n; i++)
	{
		dp[i] = max(table[i] + max(dp[i - 2], dp[i - 3] + table[i - 1]), dp[i - 1]);
	}
	
	for (int i = 0; i < n; i++)
	{
		if (big < dp[i]) big = dp[i];
	}

	cout << big << "\n";
}