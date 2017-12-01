#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

void	realMain(void);															//����

																				//���� �����
void	printContents(FILE* readContents_fp);									//���Ͽ� ����� �޸� ���
void	saveContents(FILE* saveContents_fp);									//���Ͽ� �޸� ����

																				//���� ��� ����
int		chooseWay(void);														//���� ����� ����
void	setToRegis(LPCWSTR route);												//������Ʈ�� ���� ����
void	setToSchedul(const char* route);										//�����ٷ� ���� ����

																				//���� ����
static int SetRegistry(LPCWSTR IpValueName, LPCWSTR IpExeFile);					//���� ������Ʈ���� ���
int SetScheduler(const char* route, const char* date, const char* time); //�����ٷ��� ���

int main(void)
{
	realMain();

	system("pause");

	return 0;
}

//����
void realMain(void)
{
	LPCWSTR route = L"C:\\Users\\dsm2017\\Desktop\\SmartMemo.exe";					//exe������ ���
	char* routeStr = "C:\\Users\\dsm2017\\Desktop\\SmartMemo.exe";					//exe������ ��� (string)

																					//�޸� �ҷ��ͼ� ���
	FILE* readContents_fp = fopen("text.txt", "r");
	printContents(readContents_fp);
	fclose(readContents_fp);

	//�޸� �ۼ��� txt������ ������
	FILE* saveContents_fp = fopen("text.txt", "w");
	saveContents(saveContents_fp);
	fclose(saveContents_fp);

	switch (chooseWay())
	{
	case 1:	//���� ������Ʈ���� ���
		setToRegis(route);

		break;
	case 2: //���� �ð��� ����
		setToSchedul(routeStr);

		break;
	default:
		printf("\n�߸��� �Է��Դϴ� !\n");

		break;
	}

	return;
}

//���Ͽ� �ִ°� �о� ȭ�鿡 ���
void printContents(FILE* readContents_fp)
{
	char ch;	//�޸� ��½ÿ� ���

	ch = fgetc(readContents_fp);
	if (ch == NULL)
	{
		printf("----------�޸�� ������ �����ϴ� !----------");
	}
	else
	{
		printf("----------�޸�� ����----------\n");

		//������ ������ �˻�
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
	char saveContentsArr[300];		//���Ͽ� ������ ���ڿ�

	printf(">> �޸��� ������ �Է��ϼ��� !\n");
	printf(">> ������ ������ '?'�� �Է� !\n");
	scanf("%[^?]s", saveContentsArr);

	//���� ����
	getchar();
	getchar();

	fprintf(saveContents_fp, "%s", saveContentsArr);

	return;
}

//������ ���� ����� ����
int chooseWay(void)
{
	int command = 0;		//�Է¹��� Ŀ�ǵ�

	printf("\n>> �˸� ����� �����ϼ��� !\n");
	printf("1. ���� ������Ʈ���� ��� ( ������ ��ǻ�� ����ÿ� �޸� ���� )\n");
	printf("2. �۾� �����ٷ��� ��� ( ���ϴ� �ð��� �޸� ���� )\n");
	scanf("%d", &command);

	return command;
}

//������Ʈ�� ������� ����
void setToRegis(LPCWSTR route)
{
	if (SetRegistry(L"SmartMemoP", route))
	{
		printf("���������� �޸� �߰��Ǿ����ϴ�!\n");
	}
	else
	{
		printf("�޸� �߰��� �����߽��ϴ�...\n");
	}

	return;
}

//�����ٷ� ������� ����
void setToSchedul(const char* route)
{
	char noticeDate[100];		//�޸� ����� ��¥
	char noticeTime[100];		//�޸� ����� �ð�

	printf(">> ���� �޸� �������� �Է����ּ��� !\n");
	printf(">> �Է� ���� : YYYY/MM/DD HH:MM\n");
	scanf("%s %s", noticeDate, noticeTime);

	SetScheduler(route, noticeDate, noticeTime);

	return;
}

//������Ʈ���� ����ϴ� �Լ�
//��ó : whiteat.com/WhiteAT_c/3288
//�⺻ �ҽ����� ��κ��� �����Ͽ� ����Ͽ���
//
//Parameters
//	IpValueName : ������ ���� �̸�
//  IpExeFile   : ����� exe������ ���
//
//ReturnValue
//	0 : Fail
//  1 : Success
//
static int SetRegistry(LPCWSTR IpValueName, LPCWSTR IpExeFile)
{
	HKEY hKey;		//������Ʈ�� ������ �� �� �ڵ鰪�� ������ ��
	long lRes;		//������Ʈ�� ��Ͽ� ���Ǵ� ����

					//���ڰ� NULL�̸� Fail
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

//�����ٷ��� ����ϴ� �Լ�
//
//RetrunValue
//	0 : Fail
//	1 : Success
int SetScheduler(const char* route, const char* date, const char* time)
{
	char mainCommand[200] = "SCHTASKS /Create /SC onCE /ST ";		//���� ��ɾ�
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