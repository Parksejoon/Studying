#include<stdio.h>
#include<Windows.h>

#define SIZE 100

struct Node {
	int data;
	int index;
};

struct Node List[SIZE];


void reset(void);						//����Ʈ�� �ε������� �ʱ�ȭ
void CheckList(int);					//����Ʈ�� üũ
void InsertList(int, int*);				//��� �߰�
void DeleteList(int, int*);					//��� ����
int CheckEmpty(void);					//���� Ž��
int CheckNode(int, int, int*);				//����Ʈ �ε��� Ž��

int main(void)
{
	int start = 0;
	int key;
	int InsertNode;
	int DeleteNode;

	reset();

	printf("\t======   ����Ʈ.. �ΰ����ϴ� !   ======\n\n");
	printf("\t\t 1 - ����Ʈ Ȯ��\n");
	printf("\t\t  2 - ��� �߰�\n");
	printf("\t\t  3 - ��� ����\n\n");
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
			printf("� ���ڿ� ��带 �߰��Ҳ����� ?\n���� �� ó���� �߰��ϰ� ������ -1�� �Է� !\nIndex : ");
			scanf("%d", &InsertNode);
			InsertList(InsertNode, &start);
			break;

		case 3:
			printf("��� ��带 �����Ҳ����� ?\nIndex : ");
			scanf("%d", &DeleteNode);
			DeleteList(DeleteNode, &start);
			break;

		default:
			printf("�߸��� �Է��ΰͰ��ƿ� !\n");
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


	printf("�������� �Է��ؿ� !\n");
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
		printf("�������� �ʴ� ����� �ε���.. �ΰͰ��ƿ� !\n");
		return;
	}

	else
	{
		List[Index].data = value;					//����ִ� ��忡 ���Է�
		List[Index].index = List[i].index;			//���� ��� ����
		List[i].index = Index;						//���� ��� ����
	}

	CheckList(*start);
	printf("\n�۾��� ���������� �����ѰͰ��ƿ� !\n");

	return;
}

void DeleteList(int IndexNode, int *start)
{
	int i, j, NodeNum;


	NodeNum = CheckNode(IndexNode, *start, &i);

	if (List[i].index == -1 && IndexNode == 0)
	{
		printf("��带 �ٻ����ϸ� ������ ���Ŀ�..\n");
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
	printf("\n�۾��� ���������� �����ѰͰ��ƿ� !\n");

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
	}											//�ε��� Ȯ��

	return cnt;
}

int CheckEmpty(void)
{
	int i;

	for(i = 0; List[i].index != -2; i++) {}

	return i;
}
