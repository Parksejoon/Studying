#include <stdio.h>
#include <algorithm>

int arr[301];
int dp[301];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	dp[0] = arr[0];
	dp[1] = arr[1] + arr[0];
	dp[2] = std::max(arr[2] + arr[1], arr[2] + arr[0]);
	for (int i = 3; i < n; i++)
	{
		dp[i] = arr[i] + std::max(dp[i - 2], arr[i - 1] + dp[i - 3]);
	}

	printf("%d\n", dp[n - 1]);
	
	return 0;
}