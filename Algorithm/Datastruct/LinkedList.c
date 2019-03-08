#include <stdio.h>
#include <malloc.h>

// 리스트의 노드 역할을 하는 구조체
typedef struct Node
{
	int value;				// 값
	Node* next = NULL;		// 다음 노드
} Node;

// 링크드 리스트 역할을 하는 구조체
typedef struct LinkedList
{
	int size = 0;			// 리스트의 크기
	Node* head = NULL;		// 리스트의 첫 부분
} LinkedList;

static int errno = 0;
LinkedList list;

// 에러 체크
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

// 리스트 인덱싱
int indexOf(int ind)
{
	if (list.size == 0)
	{
		// exception (List is empty)
		errno = 2;

		return 0;
	}

	// 해당 인덱스의 노드까지 감
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

// 리스트에 추가
void insert(int ind, int value)
{
	Node* curNode = list.head;

	// 만약 첫 번쨰(헤드)를 추가한다면
	if (ind == 0)
	{
		// 새로운 노드를 생성
		Node* newNode = (Node*)malloc(sizeof(Node));

		// 생성된 노드에 값을 넣어줌
		newNode->value = value;

		// 처음으로 노드를 등록할시
		if (list.size == 0)
		{
			// 다음 노드가 없으므로 NULL
			newNode->next = NULL;
		}
		else
		{
			// 생성된 노드를 다음 노드와 연결
			newNode->next = curNode->next;
		}

		// 리스트의 헤드에 등록
		list.head = newNode;
		
		// 리스트 크기 증가
		list.size++;
		
		return;
	}

	// 해당 인덱스의 노드 바로 전까지 감
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

	// 새로운 노드 생성
	Node* newNode = (Node*)malloc(sizeof(Node));

	// 생성된 노드를 다음 노드에 연결
	newNode->value = value;
	newNode->next = curNode->next;

	// 생성된 노드를 앞 노드에 연결
	curNode->next = newNode;

	// 리스트 크기 증가
	list.size++;

	return;
}

// 리스트에서 해당 인덱스의 요소 삭제
void del(int ind)
{
	Node* curNode = list.head;

	// 리스트가 비어있을시
	if (list.size == 0)
	{
		// exception (list is empty)
		errno = 2;

		return;
	}

	// 만약 첫 번쨰(헤드)를 삭제한다면
	if (ind == 0)
	{
		// 헤드에 새로운 노드(다음 노드)를 등록
		list.head = curNode->next;
		
		// 노드를 삭제
		free(curNode);

		// 리스트 크기 감소
		list.size--;

		return;
	}

	// 해당 인덱스의 노드 바로 전까지 감
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

	// 삭제할 노드를 저장
	Node* delNode = curNode->next;

	curNode->next = curNode->next->next;

	// 노드 삭제
	free(delNode);

	// 리스트 크기 감소
	list.size--;

	return;
}

// 리스트에 모든 요소 보여주기
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

// 메뉴 아웃풋
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
			case 1:	// 삽입
			{
				printf("삽입할 값을 입력해 주세요.\n");
				scanf("%d", &value);

				printf("삽입할 위치(인덱스)를 입력해 주세요.\n");
				scanf("%d", &ind);

				insert(ind, value);

				checkError();

				break;
			}
			case 2:	// 삭제
			{
				printf("삭제할 위치(인덱스)를 입력해 주세요.\n");
				scanf("%d", &ind);

				del(ind);

				checkError();

				break;
			}
			case 3:	// 인덱싱
			{
				printf("찾을 요소의 위치(인덱스)를 입력해 주세요.\n");
				scanf("%d", &ind);

				int result = indexOf(ind);

				if (!checkError())
				{
					printf("%d\n", result);
				}

				break;
			}
			case 4:	// 리스트 show
			{
				showAll();

				break;
			}
			default:
			{
				printf("입력이 잘못되었습니다.\n");
				break;
			}
		}
	}
}