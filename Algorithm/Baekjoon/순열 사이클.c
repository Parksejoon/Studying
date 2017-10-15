#include <stdio.h>

void dfs(int* arr, int now)
{
	int nextInd = arr[now];

	arr[now] = 0;
	if (arr[nextInd]) dfs(arr, nextInd);

	return;
}

int main(void)
{
	int t;

	scanf("%d", &t);
	while (t--)
	{
		int arr[1001] = { 0 };
		int n, cnt = 0;;

		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
		}

		for (int i = 1; i <= n; i++)
		{
			if (arr[i])
			{
				dfs(arr, i);
				cnt++;
			}
		}

		printf("%d\n", cnt);
	}
}