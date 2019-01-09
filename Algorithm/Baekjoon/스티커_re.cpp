#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int tc;

	cin >> tc;
	while (tc--)
	{
		int n;

		vector<vector<int>> arr(100000, vector<int>(2, 0));
		
		cin >> n;

		for (int k = 0; k < 2; k++)
		{
			for (int i = 0; i < n; i++)
			{

				cin >> arr[i][k];
			}
		}

		arr[1][0] += arr[0][1];
		arr[1][1] += arr[0][0];

		for (int i = 2; i < n; i++)
		{
			arr[i][0] += max(arr[i - 1][1], max(arr[i - 2][0], arr[i - 2][1]));
			arr[i][1] += max(arr[i - 1][0], max(arr[i - 2][0], arr[i - 2][1]));
		}

		cout << max(arr[n - 1][0], arr[n - 1][1]) << endl;
	}
}