#include <stdio.h>

int n;
int x = 1, y = -1;
int nowX = 1, nowY = 1;

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		if (nowY + y <= 0)
		{
			x *= -1;
			y *= -1;
			nowX++;
			continue;
		}
		else if (nowX + x <= 0)
		{
			x *= -1;
			y *= -1;
			nowY++;
			continue;
		}

		nowX += x;
		nowY += y;
	}

	printf("%d/%d\n", nowY, nowX);
}