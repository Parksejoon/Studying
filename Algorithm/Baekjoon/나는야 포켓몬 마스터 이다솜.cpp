#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, m;
map<string, int> pm;
string arr[100001];
char str[21];

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		string input = str;

		pm.insert(pair<string, int>(input, i));
		arr[i] = input;
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%s", str);

		if (isdigit(str[0]))
		{
			cout << arr[atoi(str) - 1] << "\n";
		}
		else
		{
			string s = str;
			printf("%d\n", pm[s] + 1);
		}
	}
}