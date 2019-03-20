#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;


int calc(string input)
{
	stack<pair<char, int>> s;
	queue<pair<char, int>> q;

	for (auto iter = input.begin(); iter < input.end(); iter++)
	{
		// ��ȣ ���� priority 0
		if (*iter == '(')
		{
			// ���ÿ� Ǫ��
			s.push(make_pair(*iter, 0));
		}
		// ��ȣ �ݱ�
		if (*iter == ')')
		{
			// ��ȣ�� ���� �κб��� ������ ���ϸ� ���� ���
			while (s.top().first != '(')
			{
				q.push(make_pair(s.top().first, 0));
				s.pop();
			}
			s.pop();
		}
		// ������ priority 1
		if (*iter == '+' || *iter == '-')
		{
			// �ڱ⺸�� ������ �켱������ ���� ������ ���
			while (!s.empty() && s.top().second >= 1)
			{
				q.push(make_pair(s.top().first, 0));
				s.pop();
			}
			// �� �� ���� �����ڸ� ���ؿ� Ǫ��
			s.push(make_pair(*iter, 1));
		}
		// ������ priority 2
		if (*iter == '*' || *iter == '/')
		{
			// �ڱ⺸�� ������ �켱������ ���� ������ ���
			while (!s.empty() && s.top().second >= 2)
			{
				q.push(make_pair(s.top().first, 0));
				s.pop();
			}
			// �� �� ���� �����ڸ� ���ؿ� Ǫ��
			s.push(make_pair(*iter, 2));
		}

		// �ǿ�����
		if (*iter >= '0' && *iter <= '9')
		{
			string strNum = "";
			int num = 0;

			while (*iter >= '0' && *iter <= '9')
			{
				strNum += *iter;
				iter++;

				if (iter >= input.end())
				{
					break;
				}
			}

			iter--;
			num = stoi(strNum);
			q.push(make_pair(0, num));
		}
	}

	while (!s.empty())
	{
		if (s.top().first != '(')
		{
			q.push(make_pair(s.top().first, 0));
		}
		s.pop();
	}

	stack<int> calcs;

	while (!q.empty())
	{
		if (q.front().first == 0)
		{
			cout << q.front().second << " ";
		}
		else
		{
			cout << q.front().first << " ";
		}

		if (q.front().first == '+')
		{
			int b = calcs.top(); calcs.pop();
			int a = calcs.top(); calcs.pop();

			calcs.push(a + b);
		}
		if (q.front().first == '-')
		{
			int b = calcs.top(); calcs.pop();
			int a = calcs.top(); calcs.pop();

			calcs.push(a - b);
		}
		if (q.front().first == '*')
		{
			int b = calcs.top(); calcs.pop();
			int a = calcs.top(); calcs.pop();

			calcs.push(a * b);
		}
		if (q.front().first == '/')
		{
			int b = calcs.top(); calcs.pop();
			int a = calcs.top(); calcs.pop();

			calcs.push(a / b);
		}
		if (q.front().first == 0)
		{
			calcs.push(q.front().second);
		}
		q.pop();
	}

	cout << endl;

	return calcs.top();
}

int main(void)
{
	string input;

	cin >> input;

	cout << calc(input) << endl;
}