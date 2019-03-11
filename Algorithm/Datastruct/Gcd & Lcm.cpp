#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	while (a % b)
	{
		int temp = a % b;
		b = a;
		a = temp;
	}

	return b;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main(void)
{
	int a, b;

	cin >> a >> b;

	cout << gcd(a, b) << endl;
	cout << lcm(a, b) << endl;
}