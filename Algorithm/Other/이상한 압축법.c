#include <stdio.h>
#include <string.h>

void enc(int n, char* arr, char* res)
{
	int index = 0;
	int cnt = 1;
	
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] == arr[i])
		{
			cnt++;
		}
		else
		{
			if (cnt >= 2)
			{
				res[index++] = cnt + 48;
				res[index++] = arr[i - 1];
			}
			else
			{
				res[index++] = arr[i - 1];
			}

			cnt = 1;
		}
	}
	if (cnt >= 2)
	{
		res[index++] = cnt + 48;
		res[index++] = arr[n - 1];
	}
	else
	{
		res[index++] = arr[n - 1];
	}
}

void dec(int n, char* arr, char* res)
{
	int index = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 48 && arr[i] < 58)
		{
			int r = arr[i] - 48;

			while (r--)
			{
				res[index++] = arr[i + 1];
			}

			i++;
		}
		else
		{
			res[index++] = arr[i];
		}
	}
}

int main(void)
{
	int n, mode;
	char arr[101] = { 0 };
	char res[101] = { 0 };

	scanf("%s %d", arr, &mode);
	n = strlen(arr);

	if (mode)
	{
		dec(n, arr, res);
	}
	else
	{
		enc(n, arr, res);
	}


	printf("%s\n", res);
}