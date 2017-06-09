#include<stdio.h>

void Ant(int *num, int n)
{
	int i, j = 0, cnt;						//전체 반복문, 임시저장배열 인덱스, 갯수
	int newnum[1000] = { 0 };				//출력된 수를 임시저장


	if (n <= 0)
	{
		return;
	}										//재귀 제한
	
	for (i = 0; num[i] != 0; i++)
	{	
		cnt = i + 1;
		printf("%d ", num[i]);

		while (num[i] == num[cnt])
		{
			cnt++;
		}

		newnum[j++] = num[i];
		newnum[j++] = cnt - i;

		printf("%d ", cnt - i);
		i = cnt - 1;
	}										//수열 생성, 저장

	printf("\n");

	return Ant(newnum, n - 1);				//재귀
}

int main(void)
{
	int n;									//줄수
	int num[1000] = { 0 };					//수열 배열


	printf("줄 수를 입력해요 ! : ");
	scanf("%d", &n);

	printf("1\n");
	num[0] = 1;
	Ant(num, n - 1);

	return 0;
}