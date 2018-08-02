#include <stdio.h>

int main(void)
{
	int g, c;

	scanf_s("%d %d", &g, &c);
	
	if (g == c)
	{
		printf("tie\n");
	}
	else
	{
		if (g == 0 && c == 1 || g == 1 && c == 2 || g == 2 && c == 0)
		{
			printf("win\n");
		}
		else
		{
			printf("lose\n");
		}
	}
}