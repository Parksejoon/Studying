#include <iostream>

using namespace std;

int arr[300][300];

int main()
{
	int w, h;
	int n;

	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> arr[i][j];
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int startX, startY;
		int endX, endY;
		int sum = 0;

		cin >> startY >> startX >> endY >> endX;
		for (int j = startY; j <= endY; j++)
		{
			for (int k = startX; k <= endX; k++)
			{
				sum += arr[j - 1][k - 1];
			}
		}

		cout << sum << "\n";
	}
}