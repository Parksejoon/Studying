#include <iostream>
#include <algorithm>

using namespace std;

int arr[2][100003];

int main(void)
{
	int t;

	cin >> t;
	while (t--)
	{
		int n;

		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int i = 1; i < n; i++)
		{
			arr[0][i] += max(arr[1][i - 1], max(arr[0][i - 2], arr[1][i - 2]));
			arr[1][i] += max(arr[0][i - 1], max(arr[0][i - 2], arr[1][i - 2]));
		}

		printf("%d\n", max(arr[1][n - 1], arr[0][n - 1]));
	}
}