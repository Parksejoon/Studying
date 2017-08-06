#include<stdio.h>

int map[50][50];
int n, cnt;

void dfs(int now)
{
	int flag = 0;

	for (int i = 0; i < n; i++)
	{
		if (map[now][i])
		{
			flag = 1;
			map[now][i] = 0;
			map[i][now] = 0;
			dfs(i);
		}
	}

	if (!flag) cnt++;
	return;
}

int main(void)
{
	int l;
	int k;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int num;

		scanf("%d", &num);
		
		if (num == -1)
		{
			l = i;
		}
		else
		{
			map[i][num] = 1;
			map[num][i] = 1;
		}
	}

	scanf("%d", &k);

	for (int i = 0; i < n; i++)
	{
		map[i][k] = 0;
		map[k][i] = 0;
	}

	if (!(l == k)) dfs(l);

	printf("%d\n", cnt);
}