#include<stdio.h>

int main(void)
{
	int w, h;
	int i;
	int min = 1000;
	int arr[4];


	scanf("%d %d %d %d", &arr[0], &arr[1], &w, &h);

	arr[2] = w - arr[0];
	arr[3] = h - arr[1];

	for (i = 0; i < 4; i++)
	{
		if (min > arr[i])
			min = arr[i];
	}

	printf("%d", min);
}