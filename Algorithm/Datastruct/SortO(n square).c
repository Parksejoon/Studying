#include <stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void selection_sort(int* arr, int size)
{
	int target = 0;

	for (int i = 0; i < size - 1; i++)
	{
		target = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[target])
			{
				target = j;
			}
		}

		swap(&arr[i], &arr[target]);
	}
}

void insertion_sort(int* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int target = arr[i];
		int cur = i;

		while (cur > 0 && arr[cur - 1] > target)
		{
			arr[cur] = arr[cur - 1];
			cur--;
		}

		arr[cur] = target;
	}
}

void show(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

int main(void)
{
	int arr[5] = { 5, 3, 1, 2, 4 };
	int size = sizeof(arr) / sizeof(int);

	show(arr, size);
	insertion_sort(arr, size);
	show(arr, size);
}