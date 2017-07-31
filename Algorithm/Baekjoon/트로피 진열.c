#include<stdio.h>

int arr[50];
int n, big;
int cnt;

int main(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > big)
		{
			cnt++;
			big = arr[i];
		}
	}

	printf("%d\n", cnt);
	cnt = 0;
	big = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] > big)
		{
			cnt++;
			big = arr[i];
		}
	}

	printf("%d\n", cnt);
}