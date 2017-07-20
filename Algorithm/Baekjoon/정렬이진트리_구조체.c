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
	int ch;								//�Է� Ŀ�ǵ�


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
			printf("���ϴ°ž� ! \n");
			break;
		}

		printf("\n\n");
	}
}

void Insert()
{
	int d;
	struct node* now = Root;


	printf("�������� ������ �Է� ! : ");
	scanf("%d", &d);

	if (Root == NULL)
	{
		Root = (struct node*)malloc(sizeof(struct node));
		Reset(Root, d);

		return;
	}									//�ҹ�� ä���

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
		}								//��ġ�� ã�Ƽ� ����
		else if (now->data < d)
		{
			if (now->right == NULL)
			{
				now->right = (struct node *)malloc(sizeof(struct node));
				Reset(now->right, d);

				return;
			}

			now = now->right;
		}								//��ġ�� ã�Ƽ� ����
		else if (now->data == d)
		{
			printf("�̹� �����ϴ� �����Ϳ��� ! \n");
			return;
		}
	}

	return;
}

void Delete()
{
	int d;											//�Է� ������
	struct node* now = Root;						//���� ����
	struct node* mother;							//���� ������ �θ�


	printf("������ ������ �Է� ! : ");
	scanf("%d", &d);
	
	if (now == NULL)
	{
		printf("�ƹ��͵� ���µ��.. ?\n");
		return;
	}

	if (now->left == NULL && now->right == NULL)
	{
		if (now->data == d)
		{
			free(now);
			now = NULL;
			Root = NULL;
			printf("���� �Ϸ� !");
			return;
		}								//�ҹ�� ����
		else
		{
			printf("��ã�Ҿ��.. \n");
			return;
		}
	}

	if (now->data == d)
	{
		printf("���� ���� ..\n");
		return;
	}

	while (now)
	{
		if (d < now->data)
		{
			mother = now;
			now = now->left;
		}											//��ġ ã��
		else if (d > now->data)
		{
			mother = now;
			now = now->right;
		}											//��ġ ã��
		else if (d == now->data)
		{
			if (mother->left == now)
			{
				mother->left = now->left;

				if (now->left == NULL && now->right == NULL)
				{
				}									//�����ʿ� x
				else if (now->left == NULL)
				{
					printf("���� ���� ..\n");
					return;
				}									//������ �������
				else
				{
					mother = now->left;

					while (mother->right)
					{
						mother = mother->right;
					}

					mother->right = now->right;
				}									//����

				free(now);
				now = NULL;
			}
			else
			{
				mother->right = now->right;
				

				if (now->left == NULL && now->right == NULL)
				{
				}									//�����ʿ� x
				else if (now->right == NULL)
				{
					printf("���� ���� ..\n");
					return;
				}									//������ �������
				else
				{
					mother = mother->right;

					while (mother->left != NULL)
					{
						mother = mother->left;
					}

					mother->left = now->left;
				}									//����

				free(now);
				now = NULL;
			}

			printf("���� �Ϸ� ! \n");
			return;
		}
	}

	printf("��ã�Ҿ��.. \n");
	return;
}

void Check()
{
	int ch, l = 1, empty = 0;						//Ŀ�ǵ�, ����, ����ִ°�?
	struct node* now = Root;						//���� ����

	printf("\t\t1 - Left�� �̵�\n");
	printf("\t\t2 - Right�� �̵�\n");
	printf("\t\t3 - ���� ���������ھ� !\n");

	while (1)
	{
		printf("Level : %d\n", l);
		if (now == NULL)
		{
			printf("����� ! \n");
			return;
		}
		else
		{
			printf("    %d\n", now->data);
			if (now->left == NULL)
			{
				printf("    ");
			}									//������� ���� x
			else
			{
				printf("%d", now->left->data);
			}									//������� ���� o

			if (now->right == NULL)
			{
				printf("\n");
			}									//������� ���� x
			else
			{
				printf("       %d\n", now->right->data);
			}									//������� ���� o
		}

		if (now->right == NULL && now->left == NULL)
		{
			empty = 1;
		}										//�Ѵ� ��

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
			printf("���ϴ°ž� !\n");
			continue;
			break;
		}
	}

	return;
}

void Find() 
{
	int d, cnt = 0;									//�Է� ������, ��ġ
	struct node* now = Root;						//���� ����


	printf("ã�� �����͸� �Է� ! : ");
	scanf("%d", &d);

	while (now)
	{ 

		if (d < now->data)
		{ 
			now = now->left;
			cnt = cnt * 2 + 1;
		}											//�����̵�
		else if (d > now->data)
		{
			now = now->right;
			cnt = cnt * 2 + 2;
		}											//�����̵�
		else if (d == now->data)
		{
			printf("%d���� ã�Ҿ�� !\n", cnt);
			return;
		}

	}

	printf("��ã�Ҿ��.. \n");
	return;
}

void Reset(struct node* reset, int d)
{
	reset->data = d;
	reset->left = NULL;
	reset->right = NULL;

	return;
}