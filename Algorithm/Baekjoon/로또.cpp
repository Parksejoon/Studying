#include <iostream>

using namespace std;

int arr[13];			// 배열
int lotto[6];			// 로또
int n;					// 개수

void dfs(int now, int stack)
{
	if (stack >= 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << lotto[i] << ' ';
		}
		cout << "\n";
	}
	else
	{
		for (int i = now; i < n; i++)
		{
			lotto[stack] = arr[i];
			dfs(i + 1, stack + 1);
		}
	}

	return;
}

int main()
{
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		
		dfs(0, 0);

		cout << "\n";
	}

	return 0;
}