#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int length, q;
	int i, j, PLD;
	int Start, End;
	char ch;


	scanf("%d", &length);
	char **num = (char**)malloc(sizeof(char) * length);
	for (i = 0; i < length; i++)
		num[i] = (char*)malloc(sizeof(char) * 7);

	for (i = 0; i < length; i++)
	{
		j = 0;
		do
		{
			scanf("%c", &ch);
			scanf("%s", &num[i]);
		}
		while (num[i][j] != ' ');
		
		printf("%c\n", num[i][j]);
		//scanf("%d", &num[i]);
	}

	/*

	scanf("%d", &q);

	for (i = 0; i < q; i++)
	{
		scanf("%d %d", &Start, &End);
		PLD = 1;

		while (Start < End)
		{
			if (num[Start - 1] != num[End - 1])
			{
				PLD = 0;
				break;
			}

			Start++;
			End--;
		}

		printf("%d\n", PLD);
	}
	*/

	free(num);
}