#include <iostream>

using namespace std;

void eratos(int n)
{
	if (n == 1)
	{
		return;
	}

	bool* primeArr = new bool[n + 1];

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

	for (int i = 2; i < n + 1; i++)
	{
		if (primeArr[i])
		{
			printf("%d ", i);
		}
	}
}

int main(void)
{
	eratos(100000);
}