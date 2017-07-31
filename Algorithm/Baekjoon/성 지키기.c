#include<stdio.h>

char arr[50][51];
int w, h;
int cnt;

void solve()
{
	int flag = 1;
	int i, j, k, o;

	for (i = 0; i < h; i++)
	{
		flag = 1;

		for (j = 0; j < w; j++)
		{
			if (arr[i][j] == 'X')
			{
				flag = 0;
				break;
			}
		}

		if (flag)
		{
			cnt++;

			for (o = 0; o < w; o++)
			{
				flag = 1;

				for (k = 0; k < h; k++)
				{
					if (arr[k][o] == 'X') flag = 0;
				}

				if (flag) break;
			}

			if (flag) arr[i][o] = 'X';
			else arr[0][o] = 'X';
		}
	}

	for (j = 0; j < w; j++)
	{
		flag = 1;

		for (i = 0; i < h; i++)
		{
			if (arr[i][j] == 'X')
			{
				flag = 0;
				break;
			}
		}

		if (flag)
		{
			cnt++;

			for (k = 0; k < h; k++)
			{
				flag = 1;

				for (o = 0; o < w; o++)
				{
					if (arr[o][k] == 'X') flag = 0;
				}

				if (flag) break;
			}

			if (flag) arr[k][j] = 'X';
			else arr[k][0] = 'X';
		}
	}
}

int main(void)
{
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++)
	{
		scanf("%s", arr[i]);
	}

	solve();
	
	printf("%d\n", cnt);
}