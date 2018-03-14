#include <iostream>

using namespace std;

int main(void)
{
	int n, t = 1;
	int a, b;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
	
		if (a == t)
		{
			t = b;
		}
		else if (b == t)
		{
			t = a;
		}
	}

	cout << t << endl;
}