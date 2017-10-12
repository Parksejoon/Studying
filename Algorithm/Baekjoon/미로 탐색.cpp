#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[101][101];
int moveX[4] = { 0, 0, 1, -1 };
int moveY[4] = { 1, -1, 0, 0 };

int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	arr[1][1] = 2;
	arr[n][m] = 1;
	
	queue<int> xq;
	queue<int> yq;

	xq.push(1);
	yq.push(1);
	while (!xq.empty())
	{
		int nowX = xq.front();
		int nowY = yq.front();
		
		xq.pop();
		yq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = nowX + moveX[i];
			int nextY = nowY + moveY[i];

			if (0 < nextX && nextX <= m
				&& arr[nextY][nextX] == 1 && 0 < nextY && nextY <= n)
			{
				xq.push(nextX);
				yq.push(nextY);
				arr[nextY][nextX] = arr[nowY][nowX] + 1;
			}
		}
	}

	cout << arr[n][m] - 1 << "\n";
}