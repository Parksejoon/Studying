#include <iostream>

int dp[40];

int main(void)
{
	int tc;

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < 40; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	std::cin >> tc;
	while (tc--)
	{
		int n;

		std::cin >> n;

		if (n == 0) std::cout << "1 0" << std::endl;
		else if (n == 1) std::cout << "0 1" << std::endl;
		else std::cout << dp[n - 2] << " " << dp[n - 1] << std::endl;
	}
}