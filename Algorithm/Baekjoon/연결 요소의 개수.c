#include<stdio.h>

int trunk[1000][1000];
int node[1000];
int nodeN, trunkM;

void dfs(int n)
{
	node[n] = 0;

	for (int i = 0; i < nodeN; i++)
	{
		if (trunk[n][i] && node[i])
		{
			dfs(i);
		}
	}

	return;
}

int solve(void)
{
	int cnt = 0;

	for (int i = 0; i < nodeN; i++)
	{
		if (node[i])
		{
			dfs(i);
			cnt++;
		}
	}

	return cnt;
}

int main(void)
{
	int u, v;

	scanf("%d %d", &nodeN, &trunkM);

	for (int i = 0; i < trunkM; i++)
	{
		scanf("%d %d", &u, &v);

		u--;
		v--;
		trunk[u][v] = 1;
		trunk[v][u] = 1;
	}

	for (int i = 0; i < nodeN; i++)
	{
		node[i] = 1;
	}

	printf("%d\n", solve());

	return 0;
}