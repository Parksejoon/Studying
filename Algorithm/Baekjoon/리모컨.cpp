#include <iostream>
#include <string>

using namespace std;

bool num[10];

int main(void)
{
	string goal;
	int goalInt;
	int n;
	int ans;

	cin >> goal >> n;
	for (int i = 0; i < 10; i++)
	{
		num[i] = true;
	}
	for (int i = 0; i < n; i++)
	{
		int target;

		scanf("%d", &target);
		num[target] = false;
	}

	goalInt = stoi(goal.c_str());
	ans = abs(goalInt - 100);

	for (int i = 0; i <= 888888; i++)
	{
		bool flag = false;
		string curStr = to_string(i);

		for (int k = 0; k < curStr.length(); k++)
		{
			int value = curStr[k] - '0';

			if (!num[value])
			{
				flag = true;
				break;
			}
		}

		if (!flag)
		{
			if (ans > abs(i - goalInt) + curStr.length())
			{
				ans = abs(i - goalInt) + curStr.length();
			}
		}
	}

	printf("%d\n", ans);
}