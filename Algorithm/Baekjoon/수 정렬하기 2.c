#include<stdio.h>

int arr[1000000];
int n;

void swap(int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void q_sort(int s, int e)
{
	if (s < e)
	{
		int p = s;
		int l = s + 1, r = e;

		while (l <= r)
		{
			while (l <= e && arr[l] <= arr[p]) l++;
			while (r >= s + 1 && arr[r] >= arr[p]) r--;
			if (l < r) swap(l, r);
		}
		swap(r, p);
		q_sort(s, r - 1);
		q_sort(r + 1, e);
	}

	return;
}

int main(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	q_sort(0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
}