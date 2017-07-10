#include<stdio.h>

int size = 3;
int arr[101][101];

void Input(void)
{
	printf("마방진의 한 변의 크기를 입력하세용 ! : ");
	scanf("%d", &size);
}

void Hole_Solve(void)
{
	int start_x = -(size / 2), start_y = size / 2;
	int num = 1;

	for (int k = 0; k < size; k++)
	{
		int x = start_x, y = start_y;

		for (int i = 0; i < size; i++)
		{
			if (x < 0)			arr[x + size][y] = num;
			else if (x >= size)	arr[x - size][y] = num;
			else if (y < 0)		arr[x][y + size] = num;
			else if (y >= size)	arr[x][y - size] = num;
			else arr[x][y] = num;

			x++;
			y++;
			num++;
		}

		start_x++;
		start_y--;
	}
}

void print_arr(void)
{
	printf("\n\n");

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n\n");
	}

	printf("\n");
}

int main(void)
{
	Input();

	Hole_Solve();

	print_arr();
}