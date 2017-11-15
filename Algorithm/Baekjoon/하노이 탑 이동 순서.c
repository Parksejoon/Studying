#include <stdio.h>

int hanoiCnt(int x)
{
	if (x == 1) return 1;
	return hanoiCnt(x - 1) + 1 + hanoiCnt(x - 1);
}

void hanoi(int x, int sc, int mc, int fc)
{	
	if (x == 0) return;
	hanoi(x - 1, sc, fc, mc);

	printf("%d %d\n", sc, fc);

	hanoi(x - 1, mc, sc, fc);
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d\n", hanoiCnt(n));
	hanoi(n, 1, 2, 3);
}