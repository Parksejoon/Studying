#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>

int n, S[1000000];

void swap(int a, int b)
{
	int temp = S[a];
	S[a] = S[b];
	S[b] = temp;
}

void quick_sort(int start, int end)
{
	if (start < end)
	{
		int p = start, l = start + 1, r = end;

		while (l <= r)
		{
			while (l <= end && S[l] <= S[p]) l++;
			while (r >= start + 1 && S[r] >= S[p]) r--;
			if (l < r) swap(l, r);
		}
		swap(p, r);
		quick_sort(start, r - 1);
		quick_sort(r + 1, end);
	}

	return;
}

void print_array()
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", S[i]);
	}
	printf("\n");

	return;
}

int find(int start, int end, int data)
{
	int p = (start + end) / 2;

	while (start <= end)
	{
		if (data == S[p]) return S[p];
		if (data > S[p]) return find(p + 1, end, data);
		else return find(start, p - 1, data);
	}

	return -1;
}

int main(void)
{
	srand(time(NULL));

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		S[i] = rand();
	}
	//print_array();
	int start = clock();

	quick_sort(0, n - 1);

	print_array();
	printf("result = %.3lf(sec)\n", (double)(clock() - start) / CLOCKS_PER_SEC);

	int data;
	scanf("%d", &data);

	start = clock();

	find(0, n, data);
	
	printf("result = %.3lf(sec)\n", (double)(clock() - start) / CLOCKS_PER_SEC);

	return 0;
}