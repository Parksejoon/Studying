#include <stdio.h>
#include <conio.h>

void printContents(FILE* readContents_fp);
void saveContents(FILE* saveContents_fp);

int main()
{
	char ch;		//��� �Է�

	//�޸� ���
	FILE* readContents_fp = fopen("text.txt", "r");		//�б������� ���� ����

	printContents(readContents_fp);

	fclose(readContents_fp);

	printf("�޸� �߰��Ϸ��� �ƹ��ų� �Է�! ���� : x\n");
	while (1)
	{
		if (kbhit())
		{
			if (getch() == 'x')
			{
				break;
			}

			//�޸� �ۼ�
			FILE* saveContents_fp = fopen("text.txt", "w");		//���������� ���� ����

			saveContents(saveContents_fp);

			fclose(saveContents_fp);

			break;
		}
	}

	return 0;
}

//���Ͽ� �ִ°� �о� ȭ�鿡 ���
void printContents(FILE* readContents_fp)
{
	char ch;

	ch = fgetc(readContents_fp);
	if (ch == NULL)
	{
		printf("�޸�� ������ �����ϴ� !");
	}
	else
	{
		printf("�޸�� ����\n");

		while (ch != EOF)
		{
			printf("%c", ch);
			ch = fgetc(readContents_fp);
		}
	}

	printf("\n\n\n");

	return;
}

//�Է��Ͽ� ���Ͽ� ����
void saveContents(FILE* saveContents_fp)
{
	char saveContentsArr[300];
	
	printf("�޸��� ������ �Է��ϼ��� ! (����� '?' �Է�)\n");
	scanf("%[^?]s", saveContentsArr);
	fprintf(saveContents_fp, "%s", saveContentsArr);
}