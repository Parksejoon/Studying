#include <iostream>

using namespace std;

int main()
{
	while (true)
	{
		int n;
		int temp = 0;

		cin >> n;
		if (n == 0)
		{
			break;
		}

		for (int i = 0; i < n; i++)
		{
			int a;

			cin >> a;
			if (a != temp)
			{
				temp = a;
				cout << a << " ";
			}
		}

		cout << "$\n";
	}

	return 0;
}