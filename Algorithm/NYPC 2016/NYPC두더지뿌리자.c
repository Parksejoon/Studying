#include<stdio.h>

char arr[21][21];
int n;
int dar = 0, chr = 0;

void Input(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr[i]);

		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 'D') dar++;
			else if (arr[i][j] == 'C') chr++;
		}
	}
}

void Solve(void)
{
	int x = 0, y = 0;

	while (dar < chr * 2)
	{
		if (arr[y][x] == '.')
		{
			arr[y][x] = 'D';
			dar++;
		}

		if (x >= n)
		{
			x = 0;
			y++;
		}
		else x++;
	}
}

void Output(void)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c", arr[i][j]);
		}

		printf("\n");
	}
}

int main(void)
{
	Input();

	Solve();

	Output();
}