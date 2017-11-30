#include <iostream>

using namespace std;

int arr[30001];
int check[3001];

int main(void)
{
	int n, m, k, r;
	int res = 0;

	cin >> n >> m >> k >> r;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		int sum = 0;

		for (int j = 0; j < 3000; j++)
		{
			check[j] = 0;
		}

		check[r] = 1;

		for (int j = i; j < i + k; j++)
		{
			check[arr[j % n]] = 1;
		}

		for (int j = 1; j <= m; j++)
		{
			sum += check[j];
		}

		if (sum > res)
		{
			res = sum;
		}
	}

	cout << res << "\n";
}