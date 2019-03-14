#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> digit(int num)
{
	vector<int> return_value;

	while (num >= 10)
	{
		return_value.push_back(num % 10);
		num /= 10;
	}
	return_value.push_back(num);
	reverse(return_value.begin(), return_value.end());

	return return_value;
}

char convert(int n)
{
	if (n >= 10)
	{
		return 41 + (n - 10);
	}

	return 30 + n;
}

int bin_to_dec(int n)
{
	vector<int> bin = digit(n);
	int answer = 0;
	int two = 1;

	for (auto iter = bin.rbegin(); iter != bin.rend(); iter++)
	{
		answer += (*iter) * two;
		two *= 2;
	}

	return answer;
}

int bin_to_oct(int n)
{
	vector<int> bin = digit(n);
	int answer = 0;
	int dig = 1;

	for (auto iter = bin.rbegin(); iter != bin.rend();)
	{
		int two = 1;
		int num = 0;

		for (int i = 0; i < 3; i++)
		{
			if (iter != bin.rend())
			{
				num += *(iter) * two;
				two *= 2;
				iter++;
			}
			else
			{
				break;
			}
		}

		answer += num * dig;
		dig *= 10;
	}

	return answer;
}

string bin_to_hex(int n)
{
	vector<int> bin = digit(n);
	string answer = 0;

	for (auto iter = bin.rbegin(); iter != bin.rend();)
	{
		int two = 1;
		int num = 0;

		for (int i = 0; i < 4; i++)
		{
			if (iter != bin.rend())
			{
				num += *(iter)* two;
				two *= 2;
				iter++;
			}
			else
			{
				break;
			}
		}

		answer += convert(num);
	}

	reverse(answer.begin(), answer.end());
	return answer;
}

int dec_to_bin(int n)
{
	int answer = 0;
	int dig = 1;

	while (n >= 2)
	{
		answer += dig * (n % 2);
		dig *= 10;
		n /= 2;
	}

	answer += dig * n;

	return answer;
}

int dec_to_oct(int n)
{
	return bin_to_oct(dec_to_bin(n));
}

string dec_to_hex(int n)
{
	return bin_to_hex(dec_to_bin(n));
}

int main(void)
{
	int n;

	cin >> n;

	cout << dec_to_bin(n) << endl;
	cout << dec_to_oct(n) << endl;
	cout << dec_to_hex(n) << endl;
}