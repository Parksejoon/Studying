#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000][3];
int maxDp[2][3];
int minDp[2][3];

int main(void)
{
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		maxDp[0][i] = arr[0][i];
		minDp[0][i] = arr[0][i];
	}

	for (int i = 1; i < n; i++)
	{
		maxDp[i % 2][0] = max(maxDp[(i - 1) % 2][0], maxDp[(i - 1) % 2][1]) + arr[i][0];
		maxDp[i % 2][1] = max(maxDp[(i - 1) % 2][0], max(maxDp[(i - 1) % 2][1], maxDp[(i - 1) % 2][2])) + arr[i][1];
		maxDp[i % 2][2] = max(maxDp[(i - 1) % 2][1], maxDp[(i - 1) % 2][2]) + arr[i][2];

		minDp[i % 2][0] = min(minDp[(i - 1) % 2][0], minDp[(i - 1) % 2][1]) + arr[i][0];
		minDp[i % 2][1] = min(minDp[(i - 1) % 2][0], min(minDp[(i - 1) % 2][1], minDp[(i - 1) % 2][2])) + arr[i][1];
		minDp[i % 2][2] = min(minDp[(i - 1) % 2][1], minDp[(i - 1) % 2][2]) + arr[i][2];
	}

	cout << max(maxDp[(n - 1) % 2][0], max(maxDp[(n - 1) % 2][1], maxDp[(n - 1) % 2][2])) << " " << min(minDp[(n - 1) % 2][0], min(minDp[(n - 1) % 2][1], minDp[(n - 1) % 2][2])) << "\n";
}