#include <iostream>

#define SIZE 10

using namespace std;

void merge(int* arr, int left, int mid, int right)
{
	int i, j, k, m;

	i = left;		// 배열A 시작점
	j = mid + 1;	// 배열B 시작점
	k = left;		// temp배열 시작점

	int temp_arr[SIZE];

	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
		{
			temp_arr[k++] = arr[i++];
		}
		else
		{
			temp_arr[k++] = arr[j++];
		}
	}

	if (i > mid)
	{
		for (m = j; m <= right; m++)
		{
			temp_arr[k++] = arr[m];
		}
	}
	else
	{
		for (m = i; m <= mid; m++)
		{
			temp_arr[k++] = arr[m];
		}
	}

	for (m = left; m <= right; m++)
	{
		arr[m] = temp_arr[m];
	}
}

void merge_sort(int* arr, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main(void)
{
	int arr[SIZE] = { 21, 10, 12, 20, 25, 13, 15 ,22, 42, 11 };

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		cout << arr[i] << " ";
	}
}