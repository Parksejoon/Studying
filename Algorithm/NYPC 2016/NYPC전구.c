#include<stdio.h>

char arr[30][31];
int w, h;
int x, y;
int move_x = 0, move_y = -1;

void Input()
{
	int flag = true;

	scanf("%d %d", &w, &h);

	for (int i = 0; i < h; i++)
	{
		scanf("%s", arr[i]);

		if (flag)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr[i][j] == 'o')
				{
					x = i;
					y = j;
					flag = false;
				}
			}
		}
	}

	return;
}

void swap()
{
	int temp = move_x;
	move_x = move_y;
	move_y = temp;
}

void Solve()
{
	int move = 1;
	int ox = x, oy = y;

	while (true)
	{
		x += move_x;
		y += move_y;

		if (y < 0)
		{
			printf("U %d", x);
			break;
		}
		else if (y >= h)
		{
			printf("D %d", x);
			break;
		}
		else if (x < 0)
		{
			printf("L %d", y);
			break;
		}
		else if (x >= w)
		{
			printf("R %d", y);
			break;
		}
		
		if (arr[y][x] == 'o')
		{
			x = ox;
			y = oy;

			switch (move)
			{
				case 1 :
					move_x = 0;
					move_y = 1;
					break;
				case 2 :
					move_x = -1;
					move_y = 0;
					break;
				case 3 :
					move_x = 1;
					move_y = 0;
					break;
			}

			move++;
		}
		else if (arr[y][x] == '\\') swap();
		else if (arr[y][x] == '/')
		{
			move_x *= -1;
			move_y *= -1;
			swap();
		}
	}
}

int main(void)
{
	Input();

	Solve();
}