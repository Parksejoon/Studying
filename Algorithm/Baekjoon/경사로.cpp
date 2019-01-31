#include <iostream>

using namespace std;

int arr[100][100];
int n, l;

int solve()
{
	int ans = 0;

	for (int y = 0; y < n; y++)
	{
		int up = 1;
		int same_cnt = 1;

		for (int x = 1; x < n; x++)
		{
			if (arr[y][x - 1] == arr[y][x])
			{
				same_cnt++;
			}
			else if (arr[y][x - 1] + 1 == arr[y][x])
			{
				if (same_cnt >= l)
				{
					same_cnt = 1;
				}
				else
				{
					up = 0;
					break;
				}
			}
			else if (arr[y][x - 1] - 1 == arr[y][x])
			{
				if (x + l - 1 < n)
				{
					int same = arr[y][x];
					
					for (int k = 1; k < l; k++)
					{
						if (arr[y][x + k] != same)
						{
							up = 0;
							break;
						}
					}

					if (up)
					{
						x += l - 1;
						same_cnt = 0;
					}
					else
					{
						break;
					}
				}
				else
				{
					up = 0;
					break;
				}
			}
			else
			{
				up = 0;
				break;
			}
		}

		ans += up;
	}

	for (int x = 0; x < n; x++)
	{
		int up = 1;
		int same_cnt = 1;

		for (int y = 1; y < n; y++)
		{
			if (arr[y - 1][x] == arr[y][x])
			{
				same_cnt++;
			}
			else if (arr[y - 1][x] + 1 == arr[y][x])
			{
				if (same_cnt >= l)
				{
					same_cnt = 1;
				}
				else
				{
					up = 0;
					break;
				}
			}
			else if (arr[y - 1][x] - 1 == arr[y][x])
			{
				if (y + l - 1 < n)
				{
					int same = arr[y][x];

					for (int k = 1; k < l; k++)
					{
						if (arr[y + k][x] != same)
						{
							up = 0;
							break;
						}
					}

					if (up)
					{
						y += l - 1;
						same_cnt = 0;
					}
					else
					{
						break;
					}
				}
				else
				{
					up = 0;
					break;
				}
			}
			else
			{
				up = 0;
				break;
			}
		}

		ans += up;
	}

	return ans;
}

int main(void)
{
	cin >> n >> l;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> arr[y][x];
		}
	}

	cout << solve() << endl;
}