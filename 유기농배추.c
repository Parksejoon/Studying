#include<stdio.h>
#include<memory.h>

int Field[55][55];

void Virus(int x, int y)
{
	Field[x][y] = 0;

	if (Field[x][y + 1])
		Virus(x, y + 1);

	if (Field[x][y - 1])
		Virus(x, y - 1);

	if (Field[x + 1][y])
		Virus(x + 1, y);

	if (Field[x - 1][y])
		Virus(x - 1, y);

	return;
}

int main(void)
{
	int t, width, hight;
	int i, j, k;
	int x, y;
	int cnt = 0;


	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d %d %d", &width, &hight, &j);

		for(k = 0; k < hight; k++)
			memset(Field[k], 0, sizeof(int) * width);


		for (; j >= 1; j--) {
			scanf("%d %d", &x, &y);
			Field[x][y] = 1;
		}


		for (j = 0; j < width; j++)
		{
			for (k = 0; k < hight; k++)
			{
				if (Field[j][k])
				{
					cnt++;
					Virus(j, k);
				}
			}
		}


		printf("%d\n", cnt);
		cnt = 0;
	}
}