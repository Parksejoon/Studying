#include <iostream>
#include <vector>

using namespace std;

struct node
{
	int child;
	int length;
};

vector<node> arr[10000];
bool visited[10000];
int n;
int ans;
int end_node;

void dfs(int cur_node, int length)
{
	visited[cur_node] = true;

	if (ans < length)
	{
		ans = length;
		end_node = cur_node;
	}

	for (int i = 0; i < arr[cur_node].size(); i++)
	{
		if (!visited[arr[cur_node][i].child])
		{
			dfs(arr[cur_node][i].child, arr[cur_node][i].length + length);
		}
	}
}

int main(void)
{
	cin >> n;

	int parent, child, length;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> parent >> child >> length;

		arr[parent].push_back({ child, length });
		arr[child].push_back({ parent, length });
	}

	dfs(1, 0);

	ans = 0;
	fill(visited, visited + sizeof(visited), false);

	dfs(end_node, 0);

	cout << ans << endl;
}