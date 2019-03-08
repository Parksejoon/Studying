#include <stdio.h>
#include <malloc.h>

// ����Ʈ�� ��� ������ �ϴ� ����ü
typedef struct Node
{
	int value;				// ��
	Node* next = NULL;		// ���� ���
} Node;

// ��ũ�� ����Ʈ ������ �ϴ� ����ü
typedef struct LinkedList
{
	int size = 0;			// ����Ʈ�� ũ��
	Node* head = NULL;		// ����Ʈ�� ù �κ�
} LinkedList;

static int errno = 0;
LinkedList list;

// ���� üũ
int checkError()
{
	int copyerrno = errno;

	errno = 0;

	if (copyerrno)
	{
		printf("Error // cause: ");
	}
	else
	{
		return 0;
	}

	switch (copyerrno)
	{
	case 1:
		printf("Out of Index\n");
		return 1;
	case 2:
		printf("List is empty\n");
		return 1;
	default:
		printf("Undefined error\n");
		return 1;
	}
}

// ����Ʈ �ε���
int indexOf(int ind)
{
	if (list.size == 0)
	{
		// exception (List is empty)
		errno = 2;

		return 0;
	}

	// �ش� �ε����� ������ ��
	Node* curNode = list.head;
	int curInd = 0;

	while (curInd < ind)
	{
		curInd++;
		if (curNode != NULL)
		{
			curNode = curNode->next;
		}
		else
		{
			// exception (Out of index)
			errno = 1;

			return 0;
		}
	}

	return curNode->value;
}

// ����Ʈ�� �߰�
void insert(int ind, int value)
{
	Node* curNode = list.head;

	// ���� ù ����(���)�� �߰��Ѵٸ�
	if (ind == 0)
	{
		// ���ο� ��带 ����
		Node* newNode = (Node*)malloc(sizeof(Node));

		// ������ ��忡 ���� �־���
		newNode->value = value;

		// ó������ ��带 ����ҽ�
		if (list.size == 0)
		{
			// ���� ��尡 �����Ƿ� NULL
			newNode->next = NULL;
		}
		else
		{
			// ������ ��带 ���� ���� ����
			newNode->next = curNode->next;
		}

		// ����Ʈ�� ��忡 ���
		list.head = newNode;
		
		// ����Ʈ ũ�� ����
		list.size++;
		
		return;
	}

	// �ش� �ε����� ��� �ٷ� ������ ��
	int curInd = 0;

	while (curInd < ind - 1)
	{
		curInd++;
		if (curNode != NULL)
		{
			curNode = curNode->next;
		}
		else
		{
			// exception (Out of index)
			errno = 1;

			return;
		}
	}

	// ���ο� ��� ����
	Node* newNode = (Node*)malloc(sizeof(Node));

	// ������ ��带 ���� ��忡 ����
	newNode->value = value;
	newNode->next = curNode->next;

	// ������ ��带 �� ��忡 ����
	curNode->next = newNode;

	// ����Ʈ ũ�� ����
	list.size++;

	return;
}

// ����Ʈ���� �ش� �ε����� ��� ����
void del(int ind)
{
	Node* curNode = list.head;

	// ����Ʈ�� ���������
	if (list.size == 0)
	{
		// exception (list is empty)
		errno = 2;

		return;
	}

	// ���� ù ����(���)�� �����Ѵٸ�
	if (ind == 0)
	{
		// ��忡 ���ο� ���(���� ���)�� ���
		list.head = curNode->next;
		
		// ��带 ����
		free(curNode);

		// ����Ʈ ũ�� ����
		list.size--;

		return;
	}

	// �ش� �ε����� ��� �ٷ� ������ ��
	int curInd = 0;

	while (curInd < ind - 1)
	{
		curInd++;
		if (curNode != NULL)
		{
			curNode = curNode->next;
		}
		else
		{
			// exception (Out of index)
			errno = 1;

			return;
		}
	}

	// ������ ��带 ����
	Node* delNode = curNode->next;

	curNode->next = curNode->next->next;

	// ��� ����
	free(delNode);

	// ����Ʈ ũ�� ����
	list.size--;

	return;
}

// ����Ʈ�� ��� ��� �����ֱ�
void showAll()
{
	printf("Size : %d\n", list.size);
	if (list.size == 0)
	{
		printf("Nothing here!\n");

		return;
	}

	Node* curNode = list.head;

	while (curNode != NULL)
	{
		printf("%d ", curNode->value);
		curNode = curNode->next;
	} 

	printf("\n");

	return;
}

// �޴� �ƿ�ǲ
void Menu()
{
	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("----------LinkedList----------\n");
	printf("1) Add\n");
	printf("2) Delete\n");
	printf("3) ShowIndexOf\n");
	printf("4) ShowAll\n");

	return;
}

int main(void)
{
	int command = 0;
	int ind, value;

	while (true)
	{
		Menu();

		scanf("%d", &command);

		switch (command)
		{
			case 1:	// ����
			{
				printf("������ ���� �Է��� �ּ���.\n");
				scanf("%d", &value);

				printf("������ ��ġ(�ε���)�� �Է��� �ּ���.\n");
				scanf("%d", &ind);

				insert(ind, value);

				checkError();

				break;
			}
			case 2:	// ����
			{
				printf("������ ��ġ(�ε���)�� �Է��� �ּ���.\n");
				scanf("%d", &ind);

				del(ind);

				checkError();

				break;
			}
			case 3:	// �ε���
			{
				printf("ã�� ����� ��ġ(�ε���)�� �Է��� �ּ���.\n");
				scanf("%d", &ind);

				int result = indexOf(ind);

				if (!checkError())
				{
					printf("%d\n", result);
				}

				break;
			}
			case 4:	// ����Ʈ show
			{
				showAll();

				break;
			}
			default:
			{
				printf("�Է��� �߸��Ǿ����ϴ�.\n");
				break;
			}
		}
	}
}