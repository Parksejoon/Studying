#include <stdio.h>
#include <string.h>

int a[110];
int b[110];
int result[110];

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}

	return b;
}

int main(void)
{
	int i, j, k;
	int c = 0;
	char in[100];

	scanf("%s", in);
	i = strlen(in) - 1;
	for (int l = 0; l <= i; l++)
	{
		a[l] = in[l] - 48;
	}
	
	scanf("%s", in);
	j = strlen(in) - 1;
	for (int l = 0; l <= j; l++)
	{
		b[l] = in[l] - 48;
	}

	k = max(i, j) + 1;
	for (int l = 0; k - l > 0; l++)
	{
		int aresult;
		int bresult;

		if (i - l < 0)
		{
			aresult = 0;
		}
		else
		{
			aresult = a[i - l];
		}
		if (j - l < 0)
		{
			bresult = 0;
		}
		else
		{
			bresult = b[j - l];
		}

		int sum = aresult + bresult + c;

		result[k - l] = sum % 10;
		c = sum / 10;
	}
	result[0] = c;

	if (result[0] != 0)
	{
		printf("%d", result[0]);
	}

	for (int l = 1; l <= k; l++)
	{
		printf("%d", result[l]);
	}
}