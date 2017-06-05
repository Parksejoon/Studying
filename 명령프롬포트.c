#include<stdio.h>

int main(void)
{
	char string[51][51];
	int n, i, j;
	int same;


	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", string[i]);
	}


	for (i = 0; string[0][i] != '\0'; i++)
	{
		same = 1;


		for (j = 1; j < n; j++)
		{
			if (string[0][i] != string[j][i])
			{
				same = 0;
				break;
			}
		}


		if (same)
		{
			printf("%c", string[0][i]);
		}
		else
		{
			printf("?");
		}
	}
}