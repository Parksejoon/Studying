#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double mainData[1000];		//통계 자료
double aveData[100];		//표본평균의 집합
int    intAveData[100];		//정수형 표본평균의 집합
int	   countData[30];		//데이터 카운트
int    n;			        //임의추출 개수

							//제곱
double square(double value)
{
	return value * value;
}

//평균구하는거
double E(double* arr, int n)
{
	double sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	return sum / n;
}

//분산구하는거
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
	double min = INT_MAX, max = 0;	//최소 최대값

									//표준편차
	double ave;						//평균
	double dis;						//분산
	double std;						//표편

									//모집단
	double Mave;					//평균
	double Mdis;					//분산
	double Mstd;					//표편

	int    range;					    //범위
	const int    rangeValue = 10;		    //범위 자를 단위
	int    j = 0;						//카운트

										//파일 열기
	FILE* fp = fopen("data.csv", "r");

	for (int i = 0; i < 1000; i++)
	{
		fscanf(fp, "%lf", &mainData[i]);
	}

	//파일 처리 끝
	fclose(fp);

	printf("몇개의 자료를 임의추출 : ");
	scanf("%d", &n);

	//랜덤 초기화
	srand(time(NULL));

	//100회 반복
	for (int i = 0; i < 100; i++)
	{
		double sum = 0;

		//데이터 합
		for (int j = 0; j < n; j++)
		{
			sum += mainData[rand() % 1000];
		}

		//표본평균
		aveData[i] = sum / n;

		if (min > aveData[i]) min = aveData[i];
		else if (max < aveData[i]) max = aveData[i];
	}

	range = (int)(((max - min) / rangeValue) * 10000);

	//범위값 카운트
	for (int i = 0; i < 100; i++)
	{
		intAveData[i] = (int)((aveData[i] - min) * 10000);
	}

	qsort(intAveData, 100, sizeof(int), compare);

	//분포도 확인
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

	//표본평균의 평균, 분산, 표준편차
	ave = E(aveData, 100);
	dis = V(aveData, ave, 100);
	std = sqrt(dis);

	//모집단의 평균, 분산, 표준편차
	Mave = E(mainData, 1000);
	Mdis = V(mainData, Mave, 1000);

	printf("평균 : %lf 분산 : %lf 표준편차 : %lf\n", ave, dis, std);
	printf("평균 : %lf 분산 : %lf\n", Mave, Mdis);
}