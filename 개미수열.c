#include<stdio.h>

void Ant(int *num, int n)
{
	int i, j = 0, cnt;						//��ü �ݺ���, �ӽ�����迭 �ε���, ����
	int newnum[1000] = { 0 };				//��µ� ���� �ӽ�����


	if (n <= 0)
	{
		return;
	}										//��� ����
	
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
	}										//���� ����, ����

	printf("\n");

	return Ant(newnum, n - 1);				//���
}

int main(void)
{
	int n;									//�ټ�
	int num[1000] = { 0 };					//���� �迭


	printf("�� ���� �Է��ؿ� ! : ");
	scanf("%d", &n);

	printf("1\n");
	num[0] = 1;
	Ant(num, n - 1);

	return 0;
}