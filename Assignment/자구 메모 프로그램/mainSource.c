#include <stdio.h>
#include <conio.h>

void printContents(FILE* readContents_fp);
void saveContents(FILE* saveContents_fp);

int main()
{
	char ch;		//명령 입력

	//메모 출력
	FILE* readContents_fp = fopen("text.txt", "r");		//읽기형으로 파일 오픈

	printContents(readContents_fp);

	fclose(readContents_fp);

	printf("메모를 추가하려면 아무거나 입력! 종료 : x\n");
	while (1)
	{
		if (kbhit())
		{
			if (getch() == 'x')
			{
				break;
			}

			//메모 작성
			FILE* saveContents_fp = fopen("text.txt", "w");		//쓰기형으로 파일 오픈

			saveContents(saveContents_fp);

			fclose(saveContents_fp);

			break;
		}
	}

	return 0;
}

//파일에 있는걸 읽어 화면에 출력
void printContents(FILE* readContents_fp)
{
	char ch;

	ch = fgetc(readContents_fp);
	if (ch == NULL)
	{
		printf("메모된 내용이 없습니다 !");
	}
	else
	{
		printf("메모된 내용\n");

		while (ch != EOF)
		{
			printf("%c", ch);
			ch = fgetc(readContents_fp);
		}
	}

	printf("\n\n\n");

	return;
}

//입력하여 파일에 저장
void saveContents(FILE* saveContents_fp)
{
	char saveContentsArr[300];
	
	printf("메모할 내용을 입력하세요 ! (종료시 '?' 입력)\n");
	scanf("%[^?]s", saveContentsArr);
	fprintf(saveContents_fp, "%s", saveContentsArr);
}