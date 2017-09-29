#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];
int dp[100000];

int main(void)
{
	int n;
	int big = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = arr[0];
	big = dp[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(arr[i], arr[i] + dp[i - 1]);
		if (big < dp[i]) big = dp[i];
	}

	dp[n - 1] = arr[n - 1];
	if (big < dp[n - 1]) big = dp[n - 11];
	for (int i = n - 2; i >= 0; i--)
	{
		dp[i] = max(arr[i], arr[i] + dp[i + 1]);
		if (big < dp[i]) big = dp[i];
	}

	printf("%d\n", big);
}