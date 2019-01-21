#include <iostream>
#include <queue>

using namespace std;

int visited[100001];

int main(void)
{
	int result = 0;
	int n, k;
	queue<int> q;

	cin >> n >> k;

	q.push(n);
	visited[n] = 1;
	while (!q.empty())
	{
		int cn = q.front(); q.pop();

		if (cn == k)
		{
			result = visited[cn] - 1;
			break;
		}

		if (cn - 1 >= 0 && !visited[cn - 1])
		{
			visited[cn - 1] = visited[cn] + 1;
			q.push(cn - 1);
		}
		
		if (cn + 1 <= 100000 && !visited[cn + 1])
		{
			visited[cn + 1] = visited[cn] + 1;
			q.push(cn + 1);
		}

		if (cn * 2 <= 100000 && !visited[cn * 2])
		{
			visited[cn * 2] = visited[cn] + 1;
			q.push(cn * 2);
		}
	}

	cout << result << endl;
}