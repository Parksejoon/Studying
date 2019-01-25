#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int n, k;		// 보드 크기, 사과 개수
int moveX = 1;
int moveY = 0;
int map[100][100];
deque<pair<int, int>> snake;
queue<pair<int, char>> moveQ;

bool move(int sec)
{
	pair<int, int> current = snake[snake.size() - 1];
	int nextX = current.first + moveX;
	int nextY = current.second + moveY;

	snake.push_back(make_pair(nextX, nextY));
	if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n)
	{
		if (map[nextY][nextX] == 1)
		{
			return false;
		}
		
		if (map[nextY][nextX] != 2)
		{
			map[snake[0].second][snake[0].first] = 0;
			snake.pop_front();
		}
		map[nextY][nextX] = 1;
	}
	else
	{
		return false;
	}
	
	if (!moveQ.empty())
	{
		pair<int, char> nextMove = moveQ.front();
		if (nextMove.first == sec)
		{
			moveQ.pop();

			if (nextMove.second == 'D')
			{
				if (moveX > 0)
				{
					moveX = 0;
					moveY = 1;
				}
				else if (moveY > 0)
				{
					moveX = -1;
					moveY = 0;
				}
				else if (moveX < 0)
				{
					moveX = 0;
					moveY = -1;
				}
				else if (moveY < 0)
				{
					moveX = 1;
					moveY = 0;
				}
			}
			else if (nextMove.second == 'L')
			{
				if (moveX < 0)
				{
					moveX = 0;
					moveY = 1;
				}
				else if (moveY > 0)
				{
					moveX = 1;
					moveY = 0;
				}
				else if (moveX > 0)
				{
					moveX = 0;
					moveY = -1;
				}
				else if (moveY < 0)
				{
					moveX = -1;
					moveY = 0;
				}
			}
		}
	}

	return true;
}

int main(void)
{
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;

		cin >> y >> x;
		map[y - 1][x - 1] = 2;
	}

	int moveSize;

	cin >> moveSize;
	for (int i = 0; i < moveSize; i++)
	{
		int s;
		char moveWay;

		cin >> s >> moveWay;
		moveQ.push(make_pair(s, moveWay));
	}

	int sec = 1;

	snake.push_back(make_pair(0, 0));
	map[0][0] = 1;
	while (move(sec))
	{
		sec++;
	}

	cout << sec << endl;
}