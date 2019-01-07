#include <iostream>
#include <cstring>

using namespace std;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int map[51][51];
int r, c, dir, nextR, nextC;
int n, m;
int ans;
bool flag;

int change_direction(int now)
{
	if (now == 0)
	{
		return 3;
	}
	else if (now == 1)
	{
		return 0;
	}
	else if (now == 2)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

int main() 
{
	cin >> n >> m;
	cin >> r >> c >> dir;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			cin >> map[i][j];
		}
	}

	ans++;
	map[r][c] = 2;
	while (1) 
	{
		int turnDir = dir;

		for (int i = 0; i < 4; i++) 
		{
			flag = false;
			turnDir = change_direction(turnDir);
			nextR = r + dr[turnDir];
			nextC = c + dc[turnDir];

			if (nextC >= 0 && nextC < m && nextR >= 0 && nextR < n && map[nextR][nextC] == 0)
			{
				ans++;
				dir = turnDir;
				r = nextR;
				c = nextC;
				map[r][c] = 2;
				flag = true;

				break;
			}
		}

		if (!flag)
		{
			if (dir == 0)
			{
				r++;
			}
			else if (dir == 1)
			{
				c--;
			}
			else if (dir == 2)
			{
				r--;
			}
			else if (dir == 3)
			{
				c++;
			}

			if (map[r][c] == 1)
			{
				break;
			}
		}
	}

	cout << ans;
}