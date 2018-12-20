#include <stdio.h>
#include <string.h>

char arr[200];

int main(void)
{
	scanf("%[^\n]s", arr);

	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] != ' ')
		{
			char charact = arr[i] - 3;

			if (charact < 97)
			{
				charact += 26;
			}

			printf("%c", charact);
		}
		else
		{
			printf(" ");
		}
	}
}