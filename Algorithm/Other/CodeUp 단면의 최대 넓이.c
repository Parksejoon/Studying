#include <stdio.h>

int main(void)
{
	int n;
	int result, max_num = 0;

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int s = i * (n - (2 * i));

		if (max_num < s)
		{
			max_num = s;
			result = i;
		}
	}

	printf("%d\n", result);
}