#include <iostream>

char arr[3072][6144];

void draw(int n, int dy, int dx)
{
	if (n == 3)
	{
		arr[dy][dx] = '*';

		arr[dy + 1][dx - 1] = '*';
		arr[dy + 1][dx + 1] = '*';

		arr[dy + 2][dx + 2] = '*';
		arr[dy + 2][dx + 1] = '*';
		arr[dy + 2][dx + 0] = '*';
		arr[dy + 2][dx - 1] = '*';
		arr[dy + 2][dx - 2] = '*';

		return;
	}

	draw(n / 2, dy, dx);
	draw(n / 2, dy + (n / 2), dx - (n / 2));
	draw(n / 2, dy + (n / 2), dx + (n / 2));
}

int main(void)
{
	int n;

	std::cin >> n;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n * 2; x++)
		{
			if (x == n * 2 - 1) arr[y][x] = '\0';
			else				arr[y][x] = ' ';
		}
	}

	draw(n, 0, n - 1);

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n * 2 - 1; x++)
		{
			std::cout << arr[y][x];
		}

		std::cout << std::endl;
	}
}