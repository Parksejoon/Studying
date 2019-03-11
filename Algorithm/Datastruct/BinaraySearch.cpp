#include <iostream>

using namespace std;

int arr[10] = { 1, 3, 5, 7, 9, 10, 14, 17, 20, 23 };

int bin_search(int num)
{
	int s = 0;
	int e = 9;
	int m = (s + e) / 2;

	while (e - s >= 0)
	{
		if (arr[m] == num)
		{
			return m;
		}
		else if (arr[m] < num)
		{
			s = m + 1;
		}
		else
		{
			e = m - 1;
		}

		m = (s + e) / 2;
	}

	return -1;
}

int main(void)
{
	cout << bin_search(1) << endl;
	cout << bin_search(2) << endl;
	cout << bin_search(10) << endl;
	cout << bin_search(23) << endl;
}