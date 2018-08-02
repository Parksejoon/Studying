#include <stdio.h>

#define MAX_ITEM 21

void dfs(int, int);

int itemPrice[MAX_ITEM];
int result, money, item;

int main(void)
{
	scanf_s("%d %d", &money, &item);
	for (int i = 0; i < item; i++)
	{
		scanf_s("%d", &itemPrice[i]);
	}

	for (int i = 0; i < item; i++)
	{
		dfs(itemPrice[i], i);
	}

	printf("%d\n", result);

	return 0;
}

void dfs(int nowPrice, int nowIndex)
{
	for (int i = nowIndex + 1; i < item; i++)
	{
		int totalPrice = nowPrice + itemPrice[i];

		if (totalPrice <= money)
		{
			if (totalPrice > result)
			{
				result = totalPrice;
			}

			dfs(totalPrice, i);
		}
	}
}