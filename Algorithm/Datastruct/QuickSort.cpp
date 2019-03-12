#include <iostream>

using namespace std;

void qsort(int* arr, int left, int right)
{
	if (left > right)
	{
		return;
	}

	int l = left;
	int r = right;
	int p = arr[left];

	while (l < r)
	{
		while (arr[r] >= p && l < r)
		{
			r--;
		}

		// 만약 현재 값이 피봇보다 작으면
		if (l != r)
		{
			arr[left] = arr[r];
		}

		while (arr[l] <= p && l < r)
		{
			l++;
		}

		// 만약 현재 값이 피봇보다 크면
		if (l != r)
		{
			arr[r] = arr[l];
			r--;
		}
	}

	arr[l] = p;
	p = l;
	
	qsort(arr, left, p - 1);
	qsort(arr, p + 1, right);

	return;
}

void show(int* arr, size_t length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void)
{
	int arr[] = { 5, 4, 3, 2, 1 };

	qsort(arr, 0, 4);

	show(arr, sizeof(arr) / sizeof(int));
}