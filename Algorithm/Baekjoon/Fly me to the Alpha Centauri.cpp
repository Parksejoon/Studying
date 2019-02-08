#include <iostream>

using namespace std;

int solve(int dist)
{
	long long cnt = 0;
	int d = dist;

	while (d > 0)
	{
		d -= cnt;
		cnt += 2;
	}

	cnt = cnt / 2 - 1;

	if (dist <= cnt * cnt)
	{
		return cnt * 2 - 1;
	}
	else
	{
		return cnt * 2;
	}
}

int main(void)
{
	int tc;

	cin >> tc;
	while (tc--)
	{
		int start, end;
		
		cin >> start >> end;
		cout << solve(end - start) << endl;
	}

}