#include <iostream>

#define SIZE 10

using namespace std;

// 
void merge(int* arr, int left, int mid, int right)
{
	int i, j, k, m;

	i = left;		// 배열A 시작점
	j = mid + 1;	// 배열B 시작점
	k = left;		// temp배열 시작점

	int temp_arr[SIZE];

	// 한쪽 배열을 다 쓸 때까지 병합
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

	// 남아있는 배열을 뒤에 붙여줌
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

	// 정렬된 배열을 리턴
	for (m = left; m <= right; m++)
	{
		cout << temp_arr[m] << " ";
		arr[m] = temp_arr[m];
	}
	cout << endl;
}

void merge_sort(int* arr, int left, int right)
{
	int mid;

	// 배열의 길이가 1이하이면 소팅 안함
	if (left < right)
	{
		// 중간지점 잡고
		mid = (left + right) / 2;

		// 반으로 나눠서 재귀
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		// 반으로 나누어진걸 합침(소팅)
		merge(arr, left, mid, right);
	}
}

int main(void)
{
	int arr[SIZE] = { 21, 10, 12, 20, 25, 13, 15 ,22, 42, 11 };

	merge_sort(arr, 0, 9);
}