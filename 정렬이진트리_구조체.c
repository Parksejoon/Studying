#include<stdio.h>
#include<malloc.h>


struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* Root = NULL;

void Insert();
void Delete();
void Check();
void Find();
void Reset(struct node*, int);

int main(void)
{
	int ch;								//입력 커맨드


	while (1)
	{
		printf("\t\t1 - Insert\n");
		printf("\t\t2 - Delete\n");
		printf("\t\t3 - Check\n");
		printf("\t\t4 - Find\n");

		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			Insert();
			break;
		case 2:
			Delete();
			break;
		case 3:
			Check();
			break;
		case 4:
			Find();
			break;
		default:
			printf("뭐하는거얏 ! \n");
			break;
		}

		printf("\n\n");
	}
}

void Insert()
{
	int d;
	struct node* now = Root;


	printf("넣으려는 데이터 입력 ! : ");
	scanf("%d", &d);

	if (Root == NULL)
	{
		Root = (struct node*)malloc(sizeof(struct node));
		Reset(Root, d);

		return;
	}									//뚝배기 채우기

	while (1)
	{
		if (now->data > d)
		{
			if (now->left == NULL)
			{
				now->left = (struct node *)malloc(sizeof(struct node));
				Reset(now->left, d);

				return;
			}

			now = now->left;
		}								//위치를 찾아서 삽입
		else if (now->data < d)
		{
			if (now->right == NULL)
			{
				now->right = (struct node *)malloc(sizeof(struct node));
				Reset(now->right, d);

				return;
			}

			now = now->right;
		}								//위치를 찾아서 삽입
		else if (now->data == d)
		{
			printf("이미 존재하는 데이터에용 ! \n");
			return;
		}
	}

	return;
}

void Delete()
{
	int d;											//입력 데이터
	struct node* now = Root;						//현재 정점
	struct node* mother;							//현재 정점의 부모


	printf("삭제할 데이터 입력 ! : ");
	scanf("%d", &d);
	
	if (now == NULL)
	{
		printf("아무것도 없는디요.. ?\n");
		return;
	}

	if (now->left == NULL && now->right == NULL)
	{
		if (now->data == d)
		{
			free(now);
			now = NULL;
			Root = NULL;
			printf("삭제 완료 !");
			return;
		}								//뚝배기 비우기
		else
		{
			printf("못찾았어요.. \n");
			return;
		}
	}

	if (now->data == d)
	{
		printf("삭제 실패 ..\n");
		return;
	}

	while (now)
	{
		if (d < now->data)
		{
			mother = now;
			now = now->left;
		}											//위치 찾기
		else if (d > now->data)
		{
			mother = now;
			now = now->right;
		}											//위치 찾기
		else if (d == now->data)
		{
			if (mother->left == now)
			{
				mother->left = now->left;

				if (now->left == NULL && now->right == NULL)
				{
				}									//연결필요 x
				else if (now->left == NULL)
				{
					printf("삭제 실패 ..\n");
					return;
				}									//연결할 방법없음
				else
				{
					mother = now->left;

					while (mother->right)
					{
						mother = mother->right;
					}

					mother->right = now->right;
				}									//연결

				free(now);
				now = NULL;
			}
			else
			{
				mother->right = now->right;
				

				if (now->left == NULL && now->right == NULL)
				{
				}									//연결필요 x
				else if (now->right == NULL)
				{
					printf("삭제 실패 ..\n");
					return;
				}									//연결할 방법없음
				else
				{
					mother = mother->right;

					while (mother->left != NULL)
					{
						mother = mother->left;
					}

					mother->left = now->left;
				}									//연결

				free(now);
				now = NULL;
			}

			printf("삭제 완료 ! \n");
			return;
		}
	}

	printf("못찾았어요.. \n");
	return;
}

void Check()
{
	int ch, l = 1, empty = 0;						//커맨드, 레벨, 비어있는가?
	struct node* now = Root;						//현재 정점

	printf("\t\t1 - Left로 이동\n");
	printf("\t\t2 - Right로 이동\n");
	printf("\t\t3 - 모든걸 끝내버리겠어 !\n");

	while (1)
	{
		printf("Level : %d\n", l);
		if (now == NULL)
		{
			printf("비엇당 ! \n");
			return;
		}
		else
		{
			printf("    %d\n", now->data);
			if (now->left == NULL)
			{
				printf("    ");
			}									//좌측노드 존재 x
			else
			{
				printf("%d", now->left->data);
			}									//좌측노드 존재 o

			if (now->right == NULL)
			{
				printf("\n");
			}									//우측노드 존재 x
			else
			{
				printf("       %d\n", now->right->data);
			}									//우측노드 존재 o
		}

		if (now->right == NULL && now->left == NULL)
		{
			empty = 1;
		}										//둘다 빔

		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			if (empty == 1)
				return;
			now = now->left;
			l++;
			break;
		case 2:
			if (empty == 1)
				return;
			now = now->right;
			l++;
			break;
		case 3:
			return;
		default:
			printf("뭐하는거얏 !\n");
			continue;
			break;
		}
	}

	return;
}

void Find() 
{
	int d, cnt = 0;									//입력 데이터, 위치
	struct node* now = Root;						//현재 정점


	printf("찾을 데이터를 입력 ! : ");
	scanf("%d", &d);

	while (now)
	{ 

		if (d < now->data)
		{ 
			now = now->left;
			cnt = cnt * 2 + 1;
		}											//좌측이동
		else if (d > now->data)
		{
			now = now->right;
			cnt = cnt * 2 + 2;
		}											//우측이동
		else if (d == now->data)
		{
			printf("%d에서 찾았어요 !\n", cnt);
			return;
		}

	}

	printf("못찾았어요.. \n");
	return;
}

void Reset(struct node* reset, int d)
{
	reset->data = d;
	reset->left = NULL;
	reset->right = NULL;

	return;
}