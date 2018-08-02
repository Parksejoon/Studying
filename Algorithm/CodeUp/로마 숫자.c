#include<stdio.h>

char roma[2][51];
int arr[24];

char rom(int num)
{
	switch (num)
	{
	case 1:    return 'I';
	case 5:    return 'V';
	case 10:   return 'X';
	case 50:   return 'L';
	case 100:  return 'C';
	case 500:  return 'D';
	case 1000: return 'M';
	default:   break;
	}
}

int main(void)
{
	int i = 0, result = 0;
	int bef, e = 1;
	char romresult[41];

	arr['I' - 65] = 1;
	arr['V' - 65] = 5;
	arr['X' - 65] = 10;
	arr['L' - 65] = 50;
	arr['C' - 65] = 100;
	arr['D' - 65] = 500;
	arr['M' - 65] = 1000;

	
	for (int j = 0; j < 2; j++)
	{
		i = 0;
		scanf("%s", roma[j]);

		bef = arr[roma[j][i] - 65];
		result += arr[roma[j][i++] - 65];

		while (roma[j][i] != '\0')
		{
			int now = arr[roma[j][i++] - 65];

			if (bef < now)
			{
				result += now - bef * 2;
			}
			else result += now;

			bef = now;
		}
	}

	printf("%d\n", result);
	i = 0;

	while (result >= e * 10)
	{
		e *= 10;
	}

	while (result != 0)
	{
		int temp = result / e;
		result %= e;
		
		if (temp <= 3)
		{
			for (; temp > 0; temp--)
			{
				romresult[i++] = rom(e);
			}
		}
		else if (temp == 4)
		{
			romresult[i++] = rom(e);
			romresult[i++] = rom(5 * e);
		}
		else if (temp == 5)
		{
			romresult[i++] = rom(5 * e);
		}
		else if (temp <= 8)
		{
			romresult[i++] = rom(5 * e);

			for (; temp > 5; temp--)
			{
				romresult[i++] = rom(e);
			}
		}
		else
		{
			romresult[i++] = rom(e);
			romresult[i++] = rom(10 * e);
		}

		e /= 10;
	}

	romresult[i] = '\0';

	printf("%s\n", romresult);
}

