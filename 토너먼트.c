#include<stdio.h>

int S[100001];
int n, k, j, cnt = 1;

void Input()
{
	scanf("%d %d %d", &n, &k, &j);

	k -= 1;
	j -= 1;
}

int big(int a, int b)
{
	if (S[a] >= S[b]) return S[a];
	else return S[b];
}

void Solve()
{
	for (int t = 0; t < n; t++) S[t] = 1;

	S[k] = S[j] = 2;

	int i = 0, q = 0;

	while (1)
	{
		if (S[i])
		{
			if (S[i] == S[i + 1] && S[i] == 2) break;

			int temp = big(i, i + 1);
			S[i] = S[i + 1] = 0;
			S[q++] = temp;
		}

		if (i >= n - 1)
		{
			cnt++;
			i = 0;
			q = 0;
		}
		else
		{
			i++;
		}
	}
}

void Output()
{
	printf("%d\n", cnt);
}

int main(void)
{
	Input();

	Solve();

	Output();
}