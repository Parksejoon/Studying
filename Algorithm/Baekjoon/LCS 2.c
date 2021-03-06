#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char arr1[1001];
char arr2[1001];
char arr3[1001];
int field[1001][1001];
int st[1001][1001];

int main(void)
{
	scanf("%s %s", arr1, arr2);

	int len1 = strlen(arr1);
	int len2 = strlen(arr2);

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (arr1[i - 1] == arr2[j - 1])
			{
				field[i][j] = field[i - 1][j - 1] + 1;
				st[i][j] = 1;
			}
			else if (field[i - 1][j] > field[i][j - 1])
			{
				field[i][j] = field[i - 1][j];
				st[i][j] = 2;
			}
			else
			{
				field[i][j] = field[i][j - 1];
				st[i][j] = 3;
			}
		}
	}
	printf("%d\n", field[len1][len2]);

	int index = 0;
	int i = len1;
	int j = len2;
	while (i > 0 && j > 0) {
		if (st[i][j] == 1)
		{
			arr3[index++] = arr1[i - 1];
			--i;
			--j;
		}
		else if (st[i][j] == 2)
		{
			--i;
		}
		else
		{
			--j;
		}
	}

	for (int k = strlen(arr3) - 1; k >= 0; k--)
	{
		printf("%c", arr3[k]);
	}
}