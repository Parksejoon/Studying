#include<stdio.h>
#include<string.h>

char A[51];
char B[51];

void Input(void)
{
	scanf("%s", A);
	scanf("%s", B);
}

void Solve(void)
{
	int limit = strlen(B) - strlen(A) + 1;
	int cnt = 0, small = 55;

	for (int i = 0; i < limit; i++)
	{
		cnt = 0;

		for (int j = 0; j < strlen(A); j++)
		{
			if (A[j] != B[j + i]) cnt++;
		}

		if (cnt < small) small = cnt;
	}

	printf("%d\n", small);
}

int main(void)
{
	Input();

	Solve();
}