#include<stdio.h>

int S[101];
int size, pos;

int big(void)
{
	int a = 0;

	for (int i = 1; i < size; i++)
		if (S[a] < S[i]) a = i;

	return a;
}

void push(void)
{
	int temp = S[0];

	for (int k = 0; k < size - 1; k++) S[k] = S[k + 1];

	S[size - 1] = temp;
}

int main(void)
{
	int tc;

	scanf("%d", &tc);

	for (int i = 0; i < tc; i++)
	{
		int cnt = 0;

		scanf("%d %d", &size, &pos);

		for (int j = 0; j < size; j++)
		{
			scanf("%d", S + j);
		}

		while (1)
		{
			int on_push = 0;
			int big_index = big();

			if (0 == big_index)
			{
				cnt++;
				on_push = 1;
				
				if (0 == pos)
				{
					printf("%d\n", cnt);
					break;
				}
			}

			if (0 == pos)
			{
				pos = size;
			}

			push();
			pos--;

			if (on_push) size--;
		}
	}

	return 0;
}