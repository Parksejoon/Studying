#include <iostream>
#include <algorithm>

using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
int arr[100][100];
int dp[100][100];
bool visited[100][100];
int n, m;

void dfs(int cy, int cx, int min_num)
{
	if (dp[cy][cx] <= min_num) return;
	else dp[cy][cx] = min_num;

	if (cy == n - 1 && cx == m - 1) return;

	for (int i = 0; i < 4; i++)
	{
		int ny = cy + dy[i];
		int nx = cx + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;

		visited[ny][nx] = true;
		dfs(ny, nx, min_num + arr[ny][nx]);
		visited[ny][nx] = false;
	}
}

int main(void)
{
	cin >> m >> n;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			scanf("%1d", &arr[y][x]);
		}
	}

	fill(&dp[0][0], &dp[n][0], 99999);
	visited[0][0] = true;
	dfs(0, 0, 0);

	cout << dp[n - 1][m - 1] << endl;
}