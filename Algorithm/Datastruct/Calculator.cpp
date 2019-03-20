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
		// 괄호 열기 priority 0
		if (*iter == '(')
		{
			// 스택에 푸쉬
			s.push(make_pair(*iter, 0));
		}
		// 괄호 닫기
		if (*iter == ')')
		{
			// 괄호가 열린 부분까지 스택을 팝하며 전부 출력
			while (s.top().first != '(')
			{
				q.push(make_pair(s.top().first, 0));
				s.pop();
			}
			s.pop();
		}
		// 연산자 priority 1
		if (*iter == '+' || *iter == '-')
		{
			// 자기보다 연산자 우선순위가 낮은 곳까지 출력
			while (!s.empty() && s.top().second >= 1)
			{
				q.push(make_pair(s.top().first, 0));
				s.pop();
			}
			// 그 후 현재 연산자를 스텍에 푸쉬
			s.push(make_pair(*iter, 1));
		}
		// 연산자 priority 2
		if (*iter == '*' || *iter == '/')
		{
			// 자기보다 연산자 우선순위가 낮은 곳까지 출력
			while (!s.empty() && s.top().second >= 2)
			{
				q.push(make_pair(s.top().first, 0));
				s.pop();
			}
			// 그 후 현재 연산자를 스텍에 푸쉬
			s.push(make_pair(*iter, 2));
		}

		// 피연산자
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