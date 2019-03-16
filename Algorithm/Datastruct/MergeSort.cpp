#include <iostream>

#define SIZE 10

using namespace std;

// 
void merge(int* arr, int left, int mid, int right)
{
	int i, j, k, m;

	i = left;		// �迭A ������
	j = mid + 1;	// �迭B ������
	k = left;		// temp�迭 ������

	int temp_arr[SIZE];

	// ���� �迭�� �� �� ������ ����
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

	// �����ִ� �迭�� �ڿ� �ٿ���
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

	// ���ĵ� �迭�� ����
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

	// �迭�� ���̰� 1�����̸� ���� ����
	if (left < right)
	{
		// �߰����� ���
		mid = (left + right) / 2;

		// ������ ������ ���
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		// ������ ���������� ��ħ(����)
		merge(arr, left, mid, right);
	}
}

int main(void)
{
	int arr[SIZE] = { 21, 10, 12, 20, 25, 13, 15 ,22, 42, 11 };

	merge_sort(arr, 0, 9);
}