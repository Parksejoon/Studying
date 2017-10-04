#include <stdio.h>

int a[50];
int cnt[50];
int n;

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j]) cnt[i]++;
			else cnt[j]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", cnt[i]);
	}
}