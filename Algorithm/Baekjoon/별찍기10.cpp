#include <iostream>

void draw(int dy, int dx)
{
	while (dy != 0)
	{
		if (dy % 3 == 1 && dx % 3 == 1)
		{
			std::cout << " ";

			return;
		}
		
		dy /= 3;
		dx /= 3;
	}

	std::cout << "*";
}

int main(void)
{
	int n;

	std::cin >> n;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			draw(y, x);
		}

		std::cout << std::endl;
	}
}