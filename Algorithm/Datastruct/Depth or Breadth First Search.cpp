#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[101][101];
int nx[4] = { 0, 0, 1, -1 };
int ny[4] = { 1, -1, 0, 0 };
bool visited[101][101];

void dfs(int cx, int cy)
{
	cout << cy << " " << cx << endl;

	for (int i = 0; i < 4; i++)
	{
		int nextx = cx + nx[i];
		int nexty = cy + ny[i];

		if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m)
		{
			continue;
		}

		if (!visited[nexty][nextx])
		{
			visited[nexty][nextx] = true;

			dfs(nextx, nexty);
		}
	}
}

void bfs(int sx, int sy)
{
	queue<pair<int, int>> q;

	visited[sy][sx] = true;
	q.push(make_pair(sy, sx));

	while (!q.empty())
	{
		pair<int, int> cur_pos = q.front(); q.pop();

		cout << cur_pos.first << " " << cur_pos.second << endl;

		for (int i = 0; i < 4; i++)
		{
			int nextx = cur_pos.second + nx[i];
			int nexty = cur_pos.first + ny[i];

			if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m)
			{
				continue;
			}

			if (!visited[nexty][nextx])
			{
				visited[nexty][nextx] = true;

				q.push(make_pair(nexty, nextx));
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;

	bfs(0, 0);
}