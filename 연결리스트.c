#include<stdio.h>
#include<Windows.h>

#define SIZE 100

struct Node {
	int data;
	int index;
};

struct Node List[SIZE];


void reset(void);						//리스트의 인덱스값을 초기화
void CheckList(int);					//리스트를 체크
void InsertList(int, int*);				//노드 추가
void DeleteList(int, int*);					//노드 삭제
int CheckEmpty(void);					//빈노드 탐색
int CheckNode(int, int, int*);				//리스트 인덱스 탐색

int main(void)
{
	int start = 0;
	int key;
	int InsertNode;
	int DeleteNode;

	reset();

	printf("\t======   리스트.. 인가봅니다 !   ======\n\n");
	printf("\t\t 1 - 리스트 확인\n");
	printf("\t\t  2 - 요소 추가\n");
	printf("\t\t  3 - 요소 삭제\n\n");
	printf("\t=======================================\n\n\n");

	while (1)
	{
		scanf_s("%d", &key);

		switch (key)
		{
		case 1:
			CheckList(start);
			break;

		case 2:
			printf("어떤 노드뒤에 노드를 추가할꺼에요 ?\n만약 맨 처음에 추가하고 싶으면 -1을 입력 !\nIndex : ");
			scanf("%d", &InsertNode);
			InsertList(InsertNode, &start);
			break;

		case 3:
			printf("몇번 노드를 삭제할꺼에요 ?\nIndex : ");
			scanf("%d", &DeleteNode);
			DeleteList(DeleteNode, &start);
			break;

		default:
			printf("잘못된 입력인것같아요 !\n");
			break;
		}

		printf("\n\n\n");
	}

}

void reset(void)
{
	int i;


	List[0].index = -1;
	for (i = 1; i < SIZE; i++)
		List[i].index = -2;

	List[0].data = 10;
	List[0].index = 1;
	List[1].data = 20;
	List[1].index = 2;
	List[2].data = 30;
	List[2].index = -1;

	return;
}

void CheckList(int start)
{
	int i = start;
	int cnt = 0;

	printf("\n");
	
	while(List[i].index != -1)
	{
		printf("[%d] %d --- ", cnt++, List[i].data);
		i = List[i].index;
	}
	printf("[%d] %d\n", cnt, List[i].data);


	return;
}

void InsertList(int IndexNode, int *start)
{
	int Index = CheckEmpty();
	int value, i, NodeNum;


	printf("넣을값을 입력해요 !\n");
	scanf("%d", &value);
	
	NodeNum = CheckNode(IndexNode, *start, &i);
	if(IndexNode == -1)
	{
		List[Index].data = value;
		List[Index].index = *start;
		*start = Index;
	}

	else if (IndexNode > NodeNum || IndexNode < 0)
	{
		printf("존재하지 않는 노드의 인덱스.. 인것같아요 !\n");
		return;
	}

	else
	{
		List[Index].data = value;					//비어있는 노드에 값입력
		List[Index].index = List[i].index;			//뒤쪽 노드 연결
		List[i].index = Index;						//앞쪽 노드 연결
	}

	CheckList(*start);
	printf("\n작업을 성공적으로 수행한것같아요 !\n");

	return;
}

void DeleteList(int IndexNode, int *start)
{
	int i, j, NodeNum;


	NodeNum = CheckNode(IndexNode, *start, &i);

	if (List[i].index == -1 && IndexNode == 0)
	{
		printf("노드를 다삭제하면 마음이 아파요..\n");
		return;
	}

	else if (i == *start)
	{
		*start = List[i].index;
		List[i].data = NULL;
		List[i].index = -2;
	}

	else
	{
		List[i].data = NULL;
		for (j = *start; List[j].index != -1;)
		{
			if (i == List[j].index)
				break;

			j = List[j].index;
		}

		List[j].index = List[i].index;
		List[i].index = -2;
	}

	CheckList(*start);
	printf("\n작업을 성공적으로 수행한것같아요 !\n");

	return;
}

int CheckNode(int IndexNode, int start, int *i)
{
	int cnt = 0;

	for (*i = start; List[*i].index != -1;)
	{
		if (cnt++ == IndexNode)
			break;

		*i = List[*i].index;
	}											//인덱스 확인

	return cnt;
}

int CheckEmpty(void)
{
	int i;

	for(i = 0; List[i].index != -2; i++) {}

	return i;
}
