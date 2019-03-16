#include <iostream>

using namespace std;

// 이방식으로 할때 생각나는 문제점 
// 1. 데이터 소멸의 문제
//		멋대로 스왑도 안하고 pivot위치나 r위치에 값을 넣으면 데이터가 소멸하지 않을까?
//		=> 만약 데이터가 소멸할려면 l, r가 두번 땡겨져야 하는데, 그런 경우는 있을 수 없음
void qsort(int* arr, int left, int right)
{
	// 만약 배열의 길이가 1이하면
	if (left > right)
	{
		return;
	}

	// l, r, pivot값을 초기화
	int l = left;
	int r = right;
	int p = arr[left];

	while (l < r)
	{
		// r을 pivot 보다 작은 값을 만날 때 까지 땡김
		while (arr[r] >= p && l < r)
		{
			r--;
		}

		// 만약 현재 값이 피봇보다 작으면
		if (l != r)
		{
			// pivot에 r값을 대입
			arr[left] = arr[r];
		}

		// l을 pivot 보다 큰 값을 만날 때 까지 땡김
		while (arr[l] <= p && l < r)
		{
			l++;
		}

		// 만약 현재 값이 피봇보다 크면
		if (l != r)
		{
			// r에 l값을 대입
			arr[r] = arr[l];
			// 대입을 하면서 값이 변질됬기에 왼쪽으로 한 칸 땡김
			r--;
		}
	}

	// l에 pivot값을 대입
	arr[l] = p;
	// pivot을 l로 치환
	p = l;
	
	// 분할해서 qsort
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