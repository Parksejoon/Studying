#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	if (*a < *b)
	{
		int temp;

		temp = *a;
		*a = *b;
		*b = temp;
	}

	return;
}

int main(void)
{
	int a, b;
	int c, d;
	int res = 0;


	cin >> a >> b;
	cin >> c >> d;

	swap(&a, &b);
	swap(&c, &d);

	if (b < c && c < a)
	{
		res++;
	}
	if (b < d && d < a)
	{
		res++;
	}

	if (res % 2)
	{
		cout << "cross" << endl;
	}
	else
	{
		cout << "not cross" << endl;
	}
}