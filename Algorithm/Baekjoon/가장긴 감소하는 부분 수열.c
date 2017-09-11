#include<stdio.h>

int arr[1000];
int cnt[1000];

int main(void)
{
	int size;

	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = size - 1; i >= 0; i--)
	{
		int big = i;
		
		for (int j = i; j < size; j++)
		{
			if (cnt[big] < cnt[j] && arr[j] < arr[i]) big = j;
		}

		cnt[i] = cnt[big] + 1;
	}

	int big = 0;
	for (int i = 0; i < size; i++)
	{
		if (big < cnt[i]) big = cnt[i];
	}

	printf("%d\n", big);
}