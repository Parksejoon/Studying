#include <iostream>

using namespace std;

// �̹������ �Ҷ� �������� ������ 
// 1. ������ �Ҹ��� ����
//		�ڴ�� ���ҵ� ���ϰ� pivot��ġ�� r��ġ�� ���� ������ �����Ͱ� �Ҹ����� ������?
//		=> ���� �����Ͱ� �Ҹ��ҷ��� l, r�� �ι� �������� �ϴµ�, �׷� ���� ���� �� ����
void qsort(int* arr, int left, int right)
{
	// ���� �迭�� ���̰� 1���ϸ�
	if (left > right)
	{
		return;
	}

	// l, r, pivot���� �ʱ�ȭ
	int l = left;
	int r = right;
	int p = arr[left];

	while (l < r)
	{
		// r�� pivot ���� ���� ���� ���� �� ���� ����
		while (arr[r] >= p && l < r)
		{
			r--;
		}

		// ���� ���� ���� �Ǻ����� ������
		if (l != r)
		{
			// pivot�� r���� ����
			arr[left] = arr[r];
		}

		// l�� pivot ���� ū ���� ���� �� ���� ����
		while (arr[l] <= p && l < r)
		{
			l++;
		}

		// ���� ���� ���� �Ǻ����� ũ��
		if (l != r)
		{
			// r�� l���� ����
			arr[r] = arr[l];
			// ������ �ϸ鼭 ���� ������⿡ �������� �� ĭ ����
			r--;
		}
	}

	// l�� pivot���� ����
	arr[l] = p;
	// pivot�� l�� ġȯ
	p = l;
	
	// �����ؼ� qsort
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