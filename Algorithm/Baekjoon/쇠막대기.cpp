#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int answer = 0;
	int s = 0;
	string input;

	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			s++;
		}
		else
		{
			s--;

			if (input[i - 1] == '(')
			{
				answer += s;
			}
			else
			{
				answer++;
			}
		}
	}

	cout << answer << endl;
}