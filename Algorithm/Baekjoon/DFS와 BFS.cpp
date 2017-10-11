#include <iostream>
#include <queue>

using namespace std;

int v;
int n, m;
int arr[1001][1001];
int dcheck[1001];
int bcheck[1001];

void dfs(int now)
{
	printf("%d ", now);
	dcheck[now] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (arr[now][i] && !dcheck[i]) dfs(i);
	}

	return;
}

void bfs(void)
{
	queue<int> q;

	q.push(v);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (!bcheck[now]) printf("%d ", now);
		bcheck[now] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (arr[now][i] && !bcheck[i]) q.push(i);
		}
	}
}

int main(void)
{
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	dfs(v);
	printf("\n");
	bfs();
	printf("\n");
}