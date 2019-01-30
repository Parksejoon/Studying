#include <iostream>
#include <string>

using namespace std;

int aline, bline;
string a;
string b;

void check()
{
	for (int ia = 0; ia < a.size(); ia++)
	{
		for (int ib = 0; ib < b.size(); ib++)
		{
			if (a[ia] == b[ib])
			{
				bline = ia;
				aline = ib;

				return;
			}
		}
	}

	return;
}

int main(void)
{
	cin >> a >> b;

	check();

	for (int y = 0; y < b.size(); y++)
	{
		if (y == aline)
		{
			cout << a;
		}
		else
		{
			for (int x = 0; x < a.size(); x++)
			{
				if (x == bline)
				{
					cout << b[y];
				}
				else
				{
					cout << '.';
				}
			}
		}

		cout << endl;
	}
}