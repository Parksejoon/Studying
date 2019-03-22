#include <iostream>

using namespace std;

bool primeArr[1001];

void eratos(int n)
{
	if (n == 1)
	{
		return;
	}

	for (int i = 2; i <= n; i++)
	{
		primeArr[i] = true;
	}

	for (int i = 2; i * i <= n; i++)
	{
		if (primeArr[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				primeArr[j] = false;
			}
		}
	}
}

int main(void)
{
	int tc;
	int ans = 0;

	cin >> tc;

	eratos(1000);
	while (tc--)
	{
		int n;

		cin >> n;

		ans += primeArr[n];
	}

	cout << ans << endl;
}