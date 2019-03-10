#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct Pos
{
	int x;
	int y;
} pos;

bool compare(const pos a, const pos b)
{
	if (a.x == b.x)
	{
		return a.y < b.y;
	}
	else
	{
		return a.x < b.x;
	}
}

double dist(pos a, pos b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(void)
{
	int tc;

	cin >> tc;
	while (tc--)
	{
		pos arr[4];
		for (int i = 0; i < 4; i++)
		{
			cin >> arr[i].x >> arr[i].y;
		}

		sort(arr, arr + 4, compare);

		if (dist(arr[0], arr[3]) == dist(arr[1], arr[2]))
		{
			if (dist(arr[0], arr[1]) == dist(arr[1], arr[3]) && dist(arr[1], arr[3]) == dist(arr[3], arr[2]) && dist(arr[3], arr[2]) == dist(arr[2], arr[0]))
			{
				cout << "1" << endl;
				continue;
			}
		}

		cout << "0" << endl;
	}
}