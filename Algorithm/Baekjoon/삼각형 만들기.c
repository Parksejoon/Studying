#include<stdio.h>
#include<stdlib.h>

int arr[1000001];

int compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second) return 1;
	else if (*(int*)first < *(int*)second) return -1;
	else return 0;
}

int main(void)
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), compare);

	int now = n - 1;
	while (arr[now] >= arr[now - 1] + arr[now - 2])
	{
		now--;

		if (now < 3)
		{
			printf("%d", -1);
			return 0;
		}
	}

	printf("%d\n", arr[now] + arr[now - 1] + arr[now - 2]);
	return 0;
}