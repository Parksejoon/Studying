#include <iostream>

using namespace std;

int arr[10];

int main(void)
{
	char num;
	int ans = 0;

	while (true)
	{
		num = getchar();

		if (num == '\n')
		{
			break;
		}

		arr[num - '0']++;
	}

	arr[6] = (arr[6] + arr[9]) / 2 + (arr[6] + arr[9]) % 2;
	arr[9] = 0;

	for (int i = 0; i < 10; i++)
	{
		if (ans < arr[i])
		{
			ans = arr[i];
		}
	}

	cout << ans << endl;
}