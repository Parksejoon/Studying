#include<stdio.h>
#include<stdlib.h>

int arr[11];

int compare(const void* a, const void* b)
{
	int num1 = *(int*) a;
	int num2 = *(int*) b;

	if (num1 < num2) return 1;
	if (num1 > num2) return -1;
	return 0;
}

int main(void)
{
	int index = 0;
	char ch = getchar();

	for (int i = 0; ch != '\n'; i++)
	{
		index++;
		arr[i] = (int)ch - 48;
		ch = getchar();
	}

	qsort(arr, index, sizeof(int), compare);

	for (int i = 0; i < index; i++)
	{
		printf("%d", arr[i]);
	}
}