#include<stdio.h>

char arr[8][9];
int result;

int main(void)
{
	for (int i = 0; i < 8; i++)
	{
		scanf("%s", arr[i]);

		for (int j = 0; j < 8; j++)
			if ((i + j) % 2 == 0 && arr[i][j] == 'F') result++;
	}

	printf("%d\n", result);
}