#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> s1, s2;

int main(void)
{
	int tc;

	cin >> tc;
	while (tc--)
	{
		string input;

		cin >> input;

		for (int i = 0; i < input.size(); i++)
		{
			char cur = input[i];

			if (cur == '\n')
			{
				break;
			}

			if (cur == '<')
			{
				if (!s1.empty())
				{
					s2.push(s1.top());
					s1.pop();
				}
			}
			else if (cur == '>')
			{
				if (!s2.empty())
				{
					s1.push(s2.top());
					s2.pop();
				}
			}
			else if (cur == '-')
			{
				if (!s1.empty())
				{
					s1.pop();
				}
			}
			else
			{
				s1.push(cur);
			}
		}

		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}

		while (!s2.empty())
		{
			cout << s2.top();
			s2.pop();
		}

		cout << endl;
	}
}