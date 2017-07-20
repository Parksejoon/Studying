#include<stdio.h>

char Tree[65][65];

void check(int, int, int);

int main(void)
{
	int n, i;


	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", Tree[i]);
	}

	check(n, 0, 0);
	printf("\n");
}

void check(int n, int start_x, int start_y)
{
	int i, j;
	int all = 1;


	for (i = start_y; i < start_y + n; i++)
	{
		for (j = start_x; j < start_x + n; j++)
		{

			if (Tree[start_x][start_y] != Tree[j][i])
			{
				printf("(");
				check(n / 2, start_x, start_y);
				check(n / 2, start_x, start_y + n / 2);
				check(n / 2, start_x + n / 2, start_y);
				check(n / 2, start_x + n / 2, start_y + n / 2);
				printf(")");
				all = 0;
				break;
			}
	
		}

		if (all == 0)
			break;
	}


	if (all == 1)
	{
		printf("%c", Tree[start_x][start_y]);
		return;
	}
	
	return;
}