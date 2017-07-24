#include<stdio.h>
#include<string.h>

char fil[2501];
char word[51];
int cnt;

int main(void)
{
	scanf("%[^\n]s", fil);
	while (getchar() != '\n');
	scanf("%[^\n]s", word);

	int size = strlen(word);

	for (; ; )
	{
		char* start = strstr(fil, word);
		
		if (NULL == start)
		{
			break;
		}
		else
		{
			cnt++;

			for (int i = 0; i < size; i++)
			{
				*(start + i) = 'A';
			}
		}
	}

	printf("%d\n", cnt);
}