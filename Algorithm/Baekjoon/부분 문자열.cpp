#include <iostream>
#include <string>

using namespace std;

bool check(string sub, string main)
{
	int k = 0;
	int j = 0;

	for (; (j < sub.size() && k <= main.size() - sub.size() + j); k++)
	{
		if (sub[j] == main[k])
		{
			j++;
		}
	}

	if (j == sub.size())
	{
		return true;
	}

	return false;
}

int main(void)
{
	string sub;
	string main;

	while (cin >> sub >> main)
	{
		if (check(sub, main))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
}