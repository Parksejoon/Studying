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
	queue<char> q;

	for (auto iter = input.begin(); iter != input.end(); iter++)
	{
		// 괄호 열기 priority 0
		if (*iter == '(')
		{
			s.push(make_pair(*iter, 0));
		}
		// 괄호 닫기
		if (*iter == ')')
		{
			while (s.top().first != '(')
			{
				q.push(s.top().first);
				s.pop();
			}
			s.pop();
		}
		// 연산자 priority 1
		if (*iter == '+' || *iter == '-')
		{
			while (!s.empty() && s.top().second >= 1)
			{
				q.push(s.top().first);
				s.pop();
			}
			s.push(make_pair(*iter, 1));
		}
		// 연산자 priority 2
		if (*iter == '*' || *iter == '/')
		{
			while (!s.empty() && s.top().second >= 2)
			{
				q.push(s.top().first);
				s.pop();
			}
			s.push(make_pair(*iter, 2));
		}

		// 피연산자
		if (*iter >= '0' && *iter <= '9')
		{
			q.push(*iter);
		}
	}

	while (!s.empty())
	{
		if (s.top().first != '(')
		{
			q.push(s.top().first);
		}
		s.pop();
	}

	stack<int> calcs;

	while (!q.empty())
	{
		cout << q.front() << " ";

		if (q.front() == '+')
		{
			int b = calcs.top(); calcs.pop();
			int a = calcs.top(); calcs.pop();

			calcs.push(a + b);
		}
		if (q.front() == '-')
		{
			int b = calcs.top(); calcs.pop();
			int a = calcs.top(); calcs.pop();

			calcs.push(a - b);
		}
		if (q.front() == '*')
		{
			int b = calcs.top(); calcs.pop();
			int a = calcs.top(); calcs.pop();

			calcs.push(a * b);
		}
		if (q.front() == '/')
		{
			int b = calcs.top(); calcs.pop();
			int a = calcs.top(); calcs.pop();

			calcs.push(a / b);
		}
		if (q.front() >= '0' && q.front() <= '9')
		{
			calcs.push(q.front() - '0');
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