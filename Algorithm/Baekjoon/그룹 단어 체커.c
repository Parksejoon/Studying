#include<stdio.h>

int result;

int main(void)
{
	int plus, cnt, n;
	char is[101];
	char arr[101];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr);

		plus = 1;
		cnt = 1;
		is[0] = arr[0];

		for (int j = 1; arr[j] != '\0'; j++)
		{
			if (arr[j] == arr[j - 1]) continue;
			else
			{
				int flag = 0;

				for (int k = 0; k < cnt; k++)
				{
					if (arr[j] == is[k])
					{
						flag = 1;
						break;
					}
				}
				
				if (flag)
				{
					plus = 0;
					break;
				}
				else is[cnt++] = arr[j];
			}
		}

		result += plus;
	}

	printf("%d\n", result);
}