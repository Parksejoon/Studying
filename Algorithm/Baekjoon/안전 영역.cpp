#include <iostream>

using namespace std;

int n;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int arr[100][100];
bool visited[100][100];

void dfs(int cy, int cx, int height)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = cy + dy[i];
		int nx = cx + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (arr[ny][nx] <= height) continue;
		if (visited[ny][nx]) continue;

		visited[ny][nx] = true;
		dfs(ny, nx, height);
	}
}

int solution(int height)
{
	int ans = 0;

	fill(&visited[0][0], &visited[0][0] + sizeof(visited), false);

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (arr[y][x] <= height) continue;
			if (visited[y][x]) continue;

			visited[y][x] = true;
			dfs(y, x, height);
			ans++;
		}
	}

	return ans;
}

int main(void)
{
	int max = 0;
	int ans = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}
	}

	for (int i = 0; i < max; i++)
	{
		int newAns = solution(i);

		if (newAns > ans)
		{
			ans = newAns;
		}
	}

	cout << ans << endl;
}