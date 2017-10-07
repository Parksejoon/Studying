#include <iostream>

using namespace std;

int check[101];
int arr[101][101];
int n, link;

int dfs(int now)
{
	if (check[now]) return 0;

	int sum = 0;

	check[now] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (arr[now][i])
		{
			sum += dfs(i);
		}
	}

	return sum + 1;
}

int main(void)
{
	cin >> n;
	cin >> link;
	for (int i = 0; i < link; i++)
	{
		int a, b;

		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	cout << dfs(1) - 1 << "\n";
}