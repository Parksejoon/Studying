#include <stdio.h>

int arr[3];

int sqr(int a)
{
	return a * a;
}

int check_triangle()
{
	int long_side = 0;
	int sum = 0;

	for (int i = 0; i < 3; i++)
	{
		if (arr[long_side] < arr[i])
		{
			long_side = i;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (i != long_side)
		{
			sum += arr[i];
		}
	}

	if (sum > arr[long_side])
	{
		return 1;
	}

	return 0;
}

int check_right_angle()
{
	for (int i = 0; i < 3; i++)
	{
		if (sqr(arr[i]) + sqr(arr[(i + 1) % 3]) == sqr(arr[(i + 2) % 3]))
		{
			printf("Á÷°¢»ï°¢Çü\n");

			return 1;
		}
	}

	return 0;
}

int main(void)
{
	int result = 3;

	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &arr[i]);
	}

	if (check_triangle())
	{
		for (int i = 0; i < 3; i++)
		{
			if (arr[i] != arr[(i + 1) % 3])
			{
				result--;
			}
		}

		switch (result)
		{
		case 3:
			printf("Á¤»ï°¢Çü\n");

			break;
		case 2:
		case 1:
			printf("ÀÌµîº¯»ï°¢Çü\n");
			break;
		case 0:
			if (!check_right_angle())
			{
				printf("»ï°¢Çü\n");
			}

			break;
		default:
			break;
		}
	}
	else
	{
		printf("»ï°¢Çü¾Æ´Ô\n");
	}
}