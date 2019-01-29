#include <iostream>
#include <algorithm>

using namespace std;

struct Meeting
{
	int start;
	int end;
};

Meeting arr[100000];

bool compare(const Meeting& a, const Meeting& b)
{
	if (a.end == b.end)
	{
		return a.start < b.start;
	}
	else
	{
		return a.end < b.end;
	}
}

int main(void)
{
	int n;
	int ans = 0;
	int cur_time = 0;


	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].start >> arr[i].end;
	}

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++)
	{
		if (cur_time <= arr[i].start)
		{
			cur_time = arr[i].end;
			ans++;
		}
	}

	cout << ans << endl;
}