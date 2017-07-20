#include<stdio.h>

int main(void)
{
	int cx, cy, r;
	int planat;
	int start_x, start_y;
	int goal_x, goal_y;
	int t;
	int i, j;
	int cnt;

	
	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		cnt = 0;

		scanf("%d %d %d %d", &start_x, &start_y, &goal_x, &goal_y);
		scanf("%d", &planat);

		for (j = 0; j < planat; j++)
		{
			scanf("%d %d %d", &cx, &cy, &r);
			if ((start_x - cx) * (start_x - cx) + (start_y - cy) * (start_y - cy) < r * r || (goal_x - cx) * (goal_x - cx) + (goal_y - cy) * (goal_y - cy) < r * r)
			{
				if ((start_x - cx) * (start_x - cx) + (start_y - cy) * (start_y - cy) < r * r && (goal_x - cx) * (goal_x - cx) + (goal_y - cy) * (goal_y - cy) < r * r) {}
				else
					cnt++;
			}
		}

		printf("%d\n", cnt);
	}
}