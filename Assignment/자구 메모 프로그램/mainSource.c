#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void		realMain();																//메인
void		printContents(FILE* readContents_fp);									//파일에 저장된 메모를 출력
void		saveContents(FILE* saveContents_fp);									//파일에 메모를 저장
static int		SetRegistry(LPCWSTR IpValueName, LPCWSTR IpExeFile);					//시작 레지스트리에 등록

int main()
{
	realMain();

	system("pause");

	return 0;
}

//메인
void realMain()
{
	char    ch;																		//입력된 명령어
	LPCWSTR route = L"C:\\Users\\dsm2017\\Desktop\\SmartMemo.exe";					//exe파일의 경로

																					//읽기형으로 파일 오픈
	FILE* readContents_fp = fopen("text.txt", "r");

	printContents(readContents_fp);

	fclose(readContents_fp);

	printf("메모를 추가하려면 아무거나 입력! \n종료 : x\n");
	while (1)
	{
		if (kbhit())
		{
			if (getch() == 'x')
			{
				//프로그램 종료
				return;
			}

			//메모 작성
			//쓰기형으로 파일 오픈
			FILE* saveContents_fp = fopen("text.txt", "w");

			saveContents(saveContents_fp);
			if (SetRegistry(L"memoP", route))
			{
				printf("성공적으로 메모가 추가되었습니다!\n");
			}
			else
			{
				printf("메모 추가에 실패했습니다...\n");
			}

			fclose(saveContents_fp);

			return;
		}
	}

	return;
}

//파일에 있는걸 읽어 화면에 출력
void printContents(FILE* readContents_fp)
{
	char ch;						//메모 출력시에 사용

	ch = fgetc(readContents_fp);
	if (ch == NULL)
	{
		printf("메모된 내용이 없습니다 !");
	}
	else
	{
		printf("메모된 내용\n");

		//파일의 끝까지 검사
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
	char saveContentsArr[300];		//파일에 저장할 문자열

	printf("메모할 내용을 입력하세요 ! (종료시 '?' 입력)\n");
	scanf("%[^?]s", saveContentsArr);
	fprintf(saveContents_fp, "%s", saveContentsArr);
}

//레지스트리에 등록하는 함수
//출처 : whiteat.com/WhiteAT_c/3288
//
//Parameters
//	IpValueName : 설정할 값의 이름
//  IpExeFile   : 등록할 exe파일의 경로
//
//ReturnValue
//	0 : Fail
//  1 : Success
//
static int SetRegistry(LPCWSTR IpValueName, LPCWSTR IpExeFile)
{
	HKEY hKey;		//레지스트리 파일을 연 후 핸들값을 저장할 곳
	long lRes;		//레지스트리 등록에 사용되는 변수

					//인자가 NULL이면 Fail
	if (IpValueName == NULL || IpExeFile == NULL)
	{
		return 0;
	}
	if (RegOpenKeyEx(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce", 0, KEY_WRITE, &hKey) != ERROR_SUCCESS)
	{
		return 0;
	}

	lRes = RegSetValueEx(hKey, IpValueName, 0, REG_SZ, (BYTE*)IpExeFile, lstrlen(IpExeFile) * 2);
	RegCloseKey(hKey);

	if (lRes != ERROR_SUCCESS)
	{
		return 0;
	}

	return 1;
}