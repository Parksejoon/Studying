#include<stdio.h>

int S[4];
int ts1, te1;
int ts2, te2;
int ts3, te3;
int result;

void Input()
{
	scanf("%d %d %d", &S[1], &S[2], &S[3]);
	scanf("%d %d", &ts1, &te1);
	scanf("%d %d", &ts2, &te2);
	scanf("%d %d", &ts3, &te3);
}

void Solve()
{
	int time = 0;
	int stack = 0;


	while (time < 101)
	{
		time++;

		if (time == ts1) stack++;
		if (time == ts2) stack++;
		if (time == ts3) stack++;
		if (time == te1) stack--;
		if (time == te2) stack--;
		if (time == te3) stack--;

		result += S[stack] * stack;
	}
}

void Output()
{
	printf("%d\n", result);
}

int main(void)
{
	Input();

	Solve();

	Output();
}