#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double mainData[1000];		//��� �ڷ�
double aveData[100];		//ǥ������� ����
int    intAveData[100];		//������ ǥ������� ����
int	   countData[30];		//������ ī��Ʈ
int    n;			        //�������� ����

							//����
double square(double value)
{
	return value * value;
}

//��ձ��ϴ°�
double E(double* arr, int n)
{
	double sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	return sum / n;
}

//�л걸�ϴ°�
double V(double* arr, double m, int n)
{
	double sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += square(m - arr[i]);
	}

	return sum / n;
}

//qsort
int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
	{
		return 1;
	}
	else if (*(int*)a < *(int*)b)
	{
		return -1;
	}
	return 0;
}

int main(void)
{
	double min = INT_MAX, max = 0;	//�ּ� �ִ밪

									//ǥ������
	double ave;						//���
	double dis;						//�л�
	double std;						//ǥ��

									//������
	double Mave;					//���
	double Mdis;					//�л�
	double Mstd;					//ǥ��

	int    range;					    //����
	const int    rangeValue = 10;		    //���� �ڸ� ����
	int    j = 0;						//ī��Ʈ

										//���� ����
	FILE* fp = fopen("data.csv", "r");

	for (int i = 0; i < 1000; i++)
	{
		fscanf(fp, "%lf", &mainData[i]);
	}

	//���� ó�� ��
	fclose(fp);

	printf("��� �ڷḦ �������� : ");
	scanf("%d", &n);

	//���� �ʱ�ȭ
	srand(time(NULL));

	//100ȸ �ݺ�
	for (int i = 0; i < 100; i++)
	{
		double sum = 0;

		//������ ��
		for (int j = 0; j < n; j++)
		{
			sum += mainData[rand() % 1000];
		}

		//ǥ�����
		aveData[i] = sum / n;

		if (min > aveData[i]) min = aveData[i];
		else if (max < aveData[i]) max = aveData[i];
	}

	range = (int)(((max - min) / rangeValue) * 10000);

	//������ ī��Ʈ
	for (int i = 0; i < 100; i++)
	{
		intAveData[i] = (int)((aveData[i] - min) * 10000);
	}

	qsort(intAveData, 100, sizeof(int), compare);

	//������ Ȯ��
	for (int i = 0; i < 100; i++)
	{
		if (intAveData[i] >= range * j)
		{
			countData[j]++;
			j++;
		}
		else
		{
			countData[j]++;
		}
	}

	for (int y = 30; y >= 0; y--)
	{
		for (int i = 0; i <= j; i++)
		{
			if (countData[i] >= y)
			{
				printf("  *  ");
			}
			else
			{
				printf("     ");
			}
		}

		printf("\n");
	}

	//ǥ������� ���, �л�, ǥ������
	ave = E(aveData, 100);
	dis = V(aveData, ave, 100);
	std = sqrt(dis);

	//�������� ���, �л�, ǥ������
	Mave = E(mainData, 1000);
	Mdis = V(mainData, Mave, 1000);

	printf("��� : %lf �л� : %lf ǥ������ : %lf\n", ave, dis, std);
	printf("��� : %lf �л� : %lf\n", Mave, Mdis);
}