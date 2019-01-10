#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct data
{
	int y;
	int x;
	int count;
};

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<vector<char>> map(50, vector<char>(50, 0));	// 맵
vector<vector<int>> water(50, vector<int>(50, 321));	// 물이 차있는 정도
queue<struct data> animal_q;// bfs에 사용하는 큐
queue<struct data> water_q;	// bfs에 사용하는 큐
vector<vector<bool>> visited(50, vector<bool>(50, false));
int r, c;					// 행렬

void water_bfs()
{
	while (!water_q.empty())
	{
		struct data cur_data = water_q.front(); water_q.pop();
		int cur_y = cur_data.y;
		int cur_x = cur_data.x;
		int cur_count = cur_data.count;

		for (int i = 0; i < 4; i++)
		{
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];

			if (ny >= 0 && ny < r && nx >= 0 && nx < c)
			{
				if (water[ny][nx] != 321)
				{
					continue;
				}

				if (map[ny][nx] != 'X' && map[ny][nx] != 'D')
				{
					water[ny][nx] = cur_count + 1;
					water_q.push({ ny, nx, cur_count + 1 });
				}
			}
		}
	}
}

void bfs()
{
	int answer = 321;

	while (!animal_q.empty())
	{
		struct data cur_data = animal_q.front(); animal_q.pop();
		int cur_y = cur_data.y;
		int cur_x = cur_data.x;
		int cur_count = cur_data.count;

		for (int i = 0; i < 4; i++)
		{
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];

			if (ny >= 0 && ny < r && nx >= 0 && nx < c)
			{
				if (visited[ny][nx])
				{
					continue;
				}

				if (map[ny][nx] == 'D')
				{
					answer = min(answer, cur_count);
				}

				if (map[ny][nx] != 'X' && cur_count + 1 < water[ny][nx])
				{
					visited[ny][nx] = true;
					animal_q.push({ ny, nx, cur_count + 1 });
				}
			}
		}
	}

	if (answer == 321)
	{
		cout << "KAKTUS" << endl;
	}
	else
	{
		cout << answer + 1 << endl;
	}
}

int main(void)
{
	cin >> r >> c;
	for (int y = 0; y < r; y++)
	{
		for (int x = 0; x < c; x++)
		{
			cin >> map[y][x];

			if (map[y][x] == '*')
			{
				water_q.push({ y, x, 0 });
				water[y][x] = 0;
			}

			if (map[y][x] == 'S')
			{
				animal_q.push({ y, x, 0 });
				visited[y][x] = true;
			}
		}
	}

	water_bfs();
	bfs();
}