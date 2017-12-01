#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

void	realMain(void);															//메인

																				//파일 입출력
void	printContents(FILE* readContents_fp);									//파일에 저장된 메모를 출력
void	saveContents(FILE* saveContents_fp);									//파일에 메모를 저장

																				//저장 방식 선택
int		chooseWay(void);														//실행 방식을 설정
void	setToRegis(LPCWSTR route);												//레지스트리 형식 선택
void	setToSchedul(const char* route);										//스케줄러 형식 선택

																				//저장 구현
static int SetRegistry(LPCWSTR IpValueName, LPCWSTR IpExeFile);					//시작 레지스트리에 등록
int SetScheduler(const char* route, const char* date, const char* time); //스케줄러에 등록

int main(void)
{
	realMain();

	system("pause");

	return 0;
}

//메인
void realMain(void)
{
	LPCWSTR route = L"C:\\Users\\dsm2017\\Desktop\\SmartMemo.exe";					//exe파일의 경로
	char* routeStr = "C:\\Users\\dsm2017\\Desktop\\SmartMemo.exe";					//exe파일의 경로 (string)

																					//메모를 불러와서 띄움
	FILE* readContents_fp = fopen("text.txt", "r");
	printContents(readContents_fp);
	fclose(readContents_fp);

	//메모 작성후 txt파일을 저장함
	FILE* saveContents_fp = fopen("text.txt", "w");
	saveContents(saveContents_fp);
	fclose(saveContents_fp);

	switch (chooseWay())
	{
	case 1:	//시작 레지스트리로 등록
		setToRegis(route);

		break;
	case 2: //일정 시간에 실행
		setToSchedul(routeStr);

		break;
	default:
		printf("\n잘못된 입력입니다 !\n");

		break;
	}

	return;
}

//파일에 있는걸 읽어 화면에 출력
void printContents(FILE* readContents_fp)
{
	char ch;	//메모 출력시에 사용

	ch = fgetc(readContents_fp);
	if (ch == NULL)
	{
		printf("----------메모된 내용이 없습니다 !----------");
	}
	else
	{
		printf("----------메모된 내용----------\n");

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

	printf(">> 메모할 내용을 입력하세요 !\n");
	printf(">> 끝내고 싶으면 '?'를 입력 !\n");
	scanf("%[^?]s", saveContentsArr);

	//버퍼 비우기
	getchar();
	getchar();

	fprintf(saveContents_fp, "%s", saveContentsArr);

	return;
}

//다음번 실행 방식을 선택
int chooseWay(void)
{
	int command = 0;		//입력받을 커맨드

	printf("\n>> 알림 방식을 선택하세요 !\n");
	printf("1. 시작 레지스트리에 등록 ( 다음번 컴퓨터 실행시에 메모 실행 )\n");
	printf("2. 작업 스케줄러에 등록 ( 원하는 시간에 메모 실행 )\n");
	scanf("%d", &command);

	return command;
}

//레지스트리 방식으로 저장
void setToRegis(LPCWSTR route)
{
	if (SetRegistry(L"SmartMemoP", route))
	{
		printf("성공적으로 메모가 추가되었습니다!\n");
	}
	else
	{
		printf("메모 추가에 실패했습니다...\n");
	}

	return;
}

//스케줄러 방식으로 저장
void setToSchedul(const char* route)
{
	char noticeDate[100];		//메모가 띄어질 날짜
	char noticeTime[100];		//메모가 띄어질 시간

	printf(">> 언제 메모를 띄울것인지 입력해주세요 !\n");
	printf(">> 입력 포맷 : YYYY/MM/DD HH:MM\n");
	scanf("%s %s", noticeDate, noticeTime);

	SetScheduler(route, noticeDate, noticeTime);

	return;
}

//레지스트리에 등록하는 함수
//출처 : whiteat.com/WhiteAT_c/3288
//기본 소스에서 대부분을 수정하여 사용하였음
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

//스케줄러에 등록하는 함수
//
//RetrunValue
//	0 : Fail
//	1 : Success
int SetScheduler(const char* route, const char* date, const char* time)
{
	char mainCommand[200] = "SCHTASKS /Create /SC onCE /ST ";		//메인 명령어
	char secondCommand[30] = " /TN SmartMemoP /TR ";
	char thirdCommand[10] = " /SD ";

	if (date == NULL || time == NULL || route == NULL)
	{
		return 0;
	}

	strcat(mainCommand, time);
	strcat(mainCommand, secondCommand);
	strcat(mainCommand, route);
	strcat(mainCommand, thirdCommand);
	strcat(mainCommand, date);

	printf("%s\n", mainCommand);
	system(mainCommand);
}