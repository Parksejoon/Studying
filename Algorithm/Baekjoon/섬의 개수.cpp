#include <iostream>
#include <vector>

using namespace std;

int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int w, h;
int arr[50][50];
bool visited[50][50];

void dfs(int cy, int cx)
{
	for (int i = 0; i < 8; i++)
	{
		int ny = cy + dy[i];
		int nx = cx + dx[i];

		if (ny >= 0 && ny < h && nx >= 0 && nx < w)
		{
			if (!visited[ny][nx] && arr[ny][nx])
			{
				visited[ny][nx] = true;
				dfs(ny, nx);
			}
		}
	}
}

int main(void)
{
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
		{
			break;
		}

		int ans = 0;
		fill(&visited[0][0], &visited[0][0] + sizeof(visited), false);

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				cin >> arr[y][x];
			}
		}

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				if (!visited[y][x] && arr[y][x])
				{
					ans++;
					visited[y][x] = true;
					dfs(y, x);
				}
			}
		}

		cout << ans << endl;
	}
}