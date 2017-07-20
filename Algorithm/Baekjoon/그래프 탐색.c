#include<stdio.h>
#include<algorithm>

int n[31][31];
int size, cnt = 2;
int doduzi[21];

void input()
{
	scanf("%d", &size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			scanf("%d", &n[i][j]);

	return;
}

bool safe(int a, int b)
{
	return (0 <= a && a <= size) && (0 <= b && b <= size);
}

bool cmp(int a, int b)
{
	return a > b;
}

void dfs(int i, int j)
{
	int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };


	doduzi[cnt - 2]++;
	n[i][j] = cnt;

	for (int k = 0; k < 4; k++)
		if (safe(i + dx[k], j + dy[k]) && n[i + dx[k]][j + dy[k]] == 1)
			dfs(i + dx[k], j + dy[k]);

	return;
}

void solve()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (n[i][j] == 1)
			{
				dfs(i, j);
				cnt++;
			}

	std::sort(doduzi, doduzi + cnt, cmp);

	return;
}

void output()
{
	printf("\n\n");

	for (int i = 0; i < cnt - 2; i++)
		printf("%d ", doduzi[i]);

	printf("\n");

	return;
}

int main(void)
{
	input();

	solve();

	output();

	return 0;
}