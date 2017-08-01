#include<stdio.h>

int arr[20000002];
int n, m;

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int temp;

		scanf("%d", &temp);
		arr[temp + 10000000]++;
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int temp;

		scanf("%d", &temp);
		printf("%d ", arr[temp + 10000000]);
	}
}